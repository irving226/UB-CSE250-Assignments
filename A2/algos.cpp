// ============================================================================
// algos.cpp
// ~~~~~~~~~~~~~~~~
// author: James Droste <james@droste.im>
// ============================================================================

#include <stdexcept> // to throw exceptions if you need to

#include <fstream>   // to open & read from input file
#include <cstdlib>   // for atoi() if you want to use it

#include <set>       // for sba algorithm
#include <vector>    // for vba algorithm
#include <algorithm> // for vba algorithm

#include "Lexer.h"
#include "algos.h"

// File Reader crap
#include <iostream>                                                       
#include <fstream>

using namespace std; // BAD PRACTICE

// Method's
int findSNAPNeedleA(string& line);
int findSNAPNeedleB(string& line, int needlea);

// Actual Method's
int vba(string filename)
{
	string fname, line;
	ifstream ifs;
	vector< pair<int, int> > vba_vector;

	ifs.open(filename.c_str());

	if ( ifs.fail() ) {
		ifs.clear();

		throw runtime_error("Unable to open file. Does it exist?");
	} else {
		while (getline(ifs, line)) {
			if ( line.substr(0, 1) != "#" ) {
				if ( line[line.length()-1] == '\n' ) {
					line.erase(line.length()-1);
				}
				
				int needle = findSNAPNeedleA(line);
				int a = atoi(line.substr(0, needle).c_str());
				int b = atoi(line.substr(findSNAPNeedleB(line, needle)).c_str());

				if ( b > a ) swap(a, b);

				vba_vector.push_back(make_pair(a, b));
			}
		}

		ifs.close();
	}

	// Sort
	sort(vba_vector.begin(), vba_vector.end());

	// Iterate, removing the non-unique elements
	vba_vector.erase( unique(vba_vector.begin(), vba_vector.end()), vba_vector.end() );

	return vba_vector.size();
}

int sba(string filename)
{
	string fname, line;
	ifstream ifs;
	set< pair<int, int> > sba_set;
	
	ifs.open(filename.c_str());
	
	if ( ifs.fail() ) {
		ifs.clear();
		
		throw runtime_error("Unable to open file. Does it exist?");
	} else {
		while (getline(ifs, line)) {
			if ( line.substr(0, 1) != "#" ) {
				if ( line[line.length()-1] == '\n' ) {
					line.erase(line.length()-1);
				}

				int needle = findSNAPNeedleA(line);
				int a = atoi(line.substr(0, needle).c_str());
				int b = atoi(line.substr(findSNAPNeedleB(line, needle)).c_str());
				
				if ( b > a ) swap(a, b);

				sba_set.insert(make_pair(a, b));
			}
		}
		
		ifs.close();
	}
	
	return sba_set.size();
}

// =====================================
int findSNAPNeedleA(string& line) {
	for ( size_t i=0; i < line.length(); i++ ) {
		if ( line[i] == '\t' || line[i] == ' ') {
			return i;
		}
	}

	return -1;
}

int findSNAPNeedleB(string& line, int needlea) {
	for ( size_t i=needlea; i < line.length(); i++ ) {
		if ( line[i] == '\t' || line[i] == '\n' || line[i] == ' ') {
			return i;
		}
	}
	
	return -1;
}
