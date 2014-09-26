// ============================================================================
// cmd.cpp
// ~~~~~~~
// author : James Droste <james@droste.im>
// - implement the two main commands: validate and display
// - this is the only file you can modify and submit
// ============================================================================

#include <iostream>
#include <sstream>
#include <stack>
#include <map>

#include "cmd.h"
#include "Lexer.h" // you should make use of the provided Lexer
#include "term_control.h"
#include "error_handling.h"

// Exceptions
#include <stdexcept>

// FIFO
#include <queue>

using namespace std;

// Method Declarations
queue<string> tokenizeCommand(const string& expression);
map<string, term_colors_t> getFormattingColorsMap();
map<string, term_attrib_t> getFormattingAttrMap();
bool isTerminalColor(string& modifier);
string getTerminalModifier(string& modifier);

// ======================
// Methods
// ======================

string display(const string& expression)
{
	queue<string> tokens;
	string output;

	try {
		tokens = tokenizeCommand(expression);
	} catch (exception &e) {
		return e.what();
	}

	// Output
	while ( !tokens.empty() ) {
		output += tokens.front();
		tokens.pop();
	}

	return output;
}

string validate(const string& expression)
{
	try {
		tokenizeCommand(expression);
	} catch (exception &e) {
		return e.what();
	}

	return "VALID";
}

queue<string> tokenizeCommand(const string& expression) {
	// Setup our variables
	queue<string> _stack;
	stack<string> _tags;
	stack<string> _tagsColors;
	stack<string> _tagsAttr;

	// Maps
	static map<string, term_colors_t> colorsMap = getFormattingColorsMap();
	static map<string, term_attrib_t> attrMap   = getFormattingAttrMap();

	// Start tokenization
	Lexer lex;
	Token tok;

	lex.set_input(expression);
	while ( lex.has_more_token() ) {
		tok = lex.next_token();

		switch ( tok.type ) {
			case TAG:
				bool closing;
				closing = false;

				if ( tok.value[0] == '/' ) {
					closing = true;
					tok.value = tok.value.substr(1);
				}

				if (
					colorsMap.find(tok.value) == colorsMap.end() &&
					attrMap.find(tok.value) == attrMap.end()
				) {
					throw runtime_error("UNKNOWN TAG");
				}

				if ( closing ) {
					// Closing tag, w/o an opening tag
					if ( _tags.empty() ) throw runtime_error("EXPRESSION NOT WELL-FORMED");

					// Closing tag not closing the correct tag
					if ( tok.value != _tags.top() ) {
						throw runtime_error("EXPRESSION NOT WELL-FORMED");
					} else {
						// Remove it from being remembered.
						if ( isTerminalColor(tok.value) ) {
							_tagsColors.pop();
						} else {
							_tagsAttr.pop();
						}
						_tags.pop();

						// Closing tag. Clear it, then add the previous one.
						_stack.push(term_cc(DEFAULT_COLOR, DEFAULT_COLOR, DEFAULT_ATTRIB));

						if ( !_tagsColors.empty() ) {
							_stack.push(getTerminalModifier(_tagsColors.top()));
						}
						if ( !_tagsAttr.empty() ) {
							_stack.push(getTerminalModifier(_tagsAttr.top()));
						}
					}
				} else {
					if ( isTerminalColor(tok.value) ) {
						_tagsColors.push(tok.value);
					} else {
						_tagsAttr.push(tok.value);
					}
					_tags.push(tok.value);

					_stack.push(getTerminalModifier(tok.value));
				}
			break;

			case IDENT:
				// Insert the characters into the stack
				_stack.push(tok.value);
			break;

			case BLANK:
				//if ( !_stack.empty() ) {
					// Insert the blank character into stack
					_stack.push(" ");
				//}
			break;

			case ERRTOK:
				throw runtime_error("INVALID TOKEN");
			break;

			default: break;

		}
	}

	// _tags should be empty before returning the stack
	if ( !_tags.empty() || !_tagsColors.empty() || !_tagsAttr.empty() ) {
		throw runtime_error("EXPRESSION NOT WELL-FORMED");
	}

	return _stack;
}

/*
 * @NOTE: I feel this could be better implemented
 * However, it works now(TM) 
 *
 * - James
 */
map<string, term_colors_t> getFormattingColorsMap() {
	map<string, term_colors_t> formattingMap;

	// Colors
	formattingMap.insert(make_pair("red", RED));
	formattingMap.insert(make_pair("green", GREEN));
	formattingMap.insert(make_pair("yellow", YELLOW));
	formattingMap.insert(make_pair("blue", BLUE));
	formattingMap.insert(make_pair("magenta", MAGENTA));
	formattingMap.insert(make_pair("cyan", CYAN));

	return formattingMap;
}

map<string, term_attrib_t> getFormattingAttrMap() {
	map<string, term_attrib_t> formattingMap;

	// attrs
	formattingMap.insert(make_pair("dim", DIM));
	formattingMap.insert(make_pair("underline", UNDERLINE));
	formattingMap.insert(make_pair("bright", BRIGHT));

	return formattingMap;
}

bool isTerminalColor(string& modifier) {
	// Color map
	static map<string, term_colors_t> colorsMap = getFormattingColorsMap();
	
	return (colorsMap.find(modifier) != colorsMap.end());
}

string getTerminalModifier(string& modifier) {
	// Maps
	static map<string, term_colors_t> colorsMap = getFormattingColorsMap();
	static map<string, term_attrib_t> attrMap   = getFormattingAttrMap();
	
	if ( colorsMap.find(modifier) != colorsMap.end() ) {
		return term_fg(
			colorsMap[modifier]
		);
	} else if ( attrMap.find(modifier) != attrMap.end() ) {
		return term_attrib(
			attrMap[modifier]
		);
	} else {
		return "";
	}
}
