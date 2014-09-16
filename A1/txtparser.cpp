//Author: James Droste
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Method Definitions
void prompt();
void show_help();
int numcols(string filename);
int numrows(string filename);
string get_command(string line);
string get_arg(string line);
string read_file(string filename);

// Methods
int main() {
	string line;
	
	prompt();
	
	while ( getline(cin, line) ) {
		string command = get_command(line);
		string arg = get_arg(line);
		
		if ( command == "numcols" && !arg.empty() ) {
			int cols = numcols(arg);
			
			if ( cols != -1 ) cout << cols << endl;
		} else if ( command == "numrows" && !arg.empty()  ) {
			int rows = numrows(arg);
			
			if ( rows != -1 ) cout << rows << endl;
		} else if ( command == "exit" ) {
			return 0;
		} else if ( command == "help" ) {
			show_help();
		} else if ( command == "numcols" ) {
			cout << "ERROR: Argument required for numcols command." << endl;
			show_help();
		} else if ( command == "numrows" ) {
			cout << "ERROR: Argument required for numrows command." << endl;
			show_help();
		} else {
			cout << "ERROR: Unknown command '" << command << "'. " << endl;
			show_help();
		}
		
		prompt();
	}
	
	return 0;
}

void prompt() {
	cout << "> ";
}

void show_help() {
	cout << "Usage:" << '\n'
		<< "numcols filename - Shows the number of columns in filename" << '\n'
		<< "numrows filename - Shows the number of rows in filename" << '\n'
		<< "help - Shows this message" << '\n'
		<< "exit - Exits this program" << '\n' << endl;
}

int numcols(string filename) {
	string content = read_file(filename);
	if ( content.empty() ) return -1;
	
	int col = 0, maxcol = 0;
	bool inword = false;
	for ( int i=0; i < content.length(); i++ ) {
		char c = content[i];
		
		// Start of a new row
		if ( c == '\n' ) {
			if ( col > maxcol ) {
				maxcol = col;
			}
			col = 0;
			inword = false;
		} else {
			if ( c != ' ' && c != '\t' ) {
				if ( inword == false ) {
					col++;
					inword = true;
				}
			} else {
				inword = false;
			}
		}
	}
	
	return maxcol;
}

int numrows(string filename) {
	string content = read_file(filename);
	if ( content.empty() ) return -1;
	
	int rows = 0;
	
	for ( int i=0; i < content.length(); i++ ) {
		char c = content[i];
		
		if ( c == '\n' ) {
			rows++;
		}
	}
	
	return rows;
}

// This could be done easier, but idc
string get_command(string line) {
	string cmd = "";
	
	for ( int i=0; i < line.length(); i++ ) {
		char c = line[i];
		
		if ( c == ' ' ) {
			return cmd;
		}
		
		cmd += c;
	}
	
	return cmd;
}

// This could be done easier, but idc
string get_arg(string line) {
	string cmd = "";
	bool hit = false;
	
	for ( int i=0; i < line.length(); i++ ) {
		char c = line[i];
		
		if ( c == ' ' ) {
			if ( hit == false ) {
				hit = true;
			} else {
				return cmd;
			}
		}
		
		if ( hit == true && c != ' ' ) cmd += c;
	}
	
	return cmd;
}

string read_file(string filename) {
	ifstream ifs;
	string rtn = "", line;
	
	ifs.open(filename.c_str());
	
	if ( ifs.fail() ) {
		cerr << "Fatal Error: Unable to open file " << filename << endl;
		ifs.clear();
		
		return "";
	} else {
		while ( getline(ifs, line) ) {
			rtn += line+'\n';
		}
	}
	
	return rtn;
}
