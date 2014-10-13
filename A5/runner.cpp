//===========================
// runner.cpp
// -------
// @author: James Droste <james@droste.im>
//
// Runs the assignment #5. Not required.
//===========================

#include "a5.h"
#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h> // Rand
#include <fstream>
#include <cstring>

using namespace std;

// Prototypes
void test_p1_a();
void test_p1_b();
stack<int> p1_makeStack(int neg);
void test_p2_a();
void test_p2_b();
void test_p3();
vector<int> p3_makeVector();
void test_cs();

// Methods
int main(int argc, char **argv)  {
	cout << "A5 Test Runner" << endl;
	cout << "By James Droste <james@droste.im>" << endl;

	cout << "----------" << endl;
	cout << "Problem #1:" << endl;
	test_p1_a();
	test_p1_b();

	cout << "---------" << endl;
	cout << "Problem #2:" << endl;
	test_p2_a();
	test_p2_b();

	cout << "---------" << endl;
	cout << "Problem #3" << endl;
	test_p3();
	
	cout << "---------" << endl;
	cout << "Code Sniffing" << endl;
	test_cs();

	return 0;
}

// Tests
void test_p1_a() {
	int fail = 0;

	for ( int i=1; i < 10; i++ ) {
		int neg = rand() % 100;
		string pfail = "FAIL";

		int actual = iterative_num_negatives(p1_makeStack(neg));

		if ( neg == actual ) {
			pfail = "PASS";
		} else {
			fail++;
		}

		cout << "[test_p1_a : test" << i << " | " << pfail << " ] expected: " << neg << " | actual: " << actual << endl;
	}

	if ( fail > 0 )
		cout << endl << "FAILED: " << fail << endl << endl;
}

void test_p1_b() {
	int fail = 0;

	for ( int i=1; i < 10; i++ ) {
		int neg = rand() % 100;
		string pfail = "FAIL";

		int actual = recursive_num_negatives(p1_makeStack(neg));

		if ( neg == actual ) {
			pfail = "PASS";
		} else {
			fail++;
		}

		cout << "[test_p1_b : test" << i << " | " << pfail << " ] expected: " << neg << " | actual: " << actual << endl;
	}

	if ( fail > 0 )
		cout << endl << "FAILED: " << fail << endl;
}

void test_p2_a() {
	string pfail1 = "FAIL"; string pfail2 = "FAIL";
	int fail = 2;

	// Generate our vectors
	vector<int> masterVec;
	vector<int> test1;
	vector<int> test2;

	masterVec.push_back(1);masterVec.push_back(2);masterVec.push_back(3);masterVec.push_back(1);masterVec.push_back(4);masterVec.push_back(5);
	test1.push_back(2);test1.push_back(3);test1.push_back(1);
	test2.push_back(3);test2.push_back(1);test2.push_back(5);

	// Expected
	bool expected1 = true;
	bool expected2 = false;

	// Actual
	bool actual1 = iterative_sub_vector(test1, masterVec);
	bool actual2 = iterative_sub_vector(test2, masterVec);

	// Update passfail
	if ( expected1 == actual1 ) { pfail1 = "PASS"; fail--; }
	if ( expected2 == actual2 ) { pfail2 = "PASS"; fail--; }

	cout << "[test_p2_a : test1 | " << pfail1 << " ] expected: " << expected1 << " | actual: " << actual1 << endl;
	cout << "[test_p2_a : test2 | " << pfail2 << " ] expected: " << expected2 << " | actual: " << actual2 << endl;

	if ( fail > 0 )
		cout << endl << "FAILED: " << fail << endl;
}

void test_p2_b() {
	string pfail1 = "FAIL"; string pfail2 = "FAIL";
	int fail = 2;

	// Generate our vectors
	vector<int> masterVec;
	vector<int> test1;
	vector<int> test2;

	masterVec.push_back(1);masterVec.push_back(2);masterVec.push_back(3);masterVec.push_back(1);masterVec.push_back(4);masterVec.push_back(5);
	test1.push_back(2);test1.push_back(3);test1.push_back(1);
	test2.push_back(3);test2.push_back(1);test2.push_back(5);

	// Expected
	bool expected1 = true;
	bool expected2 = false;

	// Actual
	bool actual1 = recursive_sub_vector(test1, masterVec, 0);
	bool actual2 = recursive_sub_vector(test2, masterVec, 0);

	// Update passfail
	if ( expected1 == actual1 ) { pfail1 = "PASS"; fail--; }
	if ( expected2 == actual2 ) { pfail2 = "PASS"; fail--; }

	cout << "[test_p2_b : test1 | " << pfail1 << " ] expected: " << expected1 << " | actual: " << actual1 << endl;
	cout << "[test_p2_b : test2 | " << pfail2 << " ] expected: " << expected2 << " | actual: " << actual2 << endl;

	if ( fail > 0 )
		cout << endl << "FAILED: " << fail << endl;
}

void test_p3() {
	int fail = 0;

	vector<int> test = p3_makeVector();
	
	bool expected1 = true;
	bool expected2 = true;
	bool expected3 = false;
	bool expected4 = true;
	bool expected5 = true;
	bool expected6 = true;
	
	bool actual1 = sum_to_target(test, 0, 0);     // Always true
	bool actual2 = sum_to_target(test, 19, 0);    // 10+0
	bool actual3 = sum_to_target(test, 20000, 0); // Invalid
	bool actual4 = sum_to_target(test, 55, 0);    // 1+2+3+4+5+6+7+8+9+10
	bool actual5 = sum_to_target(test, 46, 0);    // 1+2+3+4+5+6+7+8+10
	bool actual6 = sum_to_target(test, 11, 0);    // 1+10
	
	string pfail1 = "PASS"; string pfail2 = "PASS"; string pfail3 = "PASS"; string pfail4 = "PASS"; string pfail5 = "PASS";
    string pfail6 = "PASS";
	
	if ( expected1 != actual1 ) { fail++; pfail1 = "FAIL"; }
	if ( expected2 != actual2 ) { fail++; pfail2 = "FAIL";  }
	if ( expected3 != actual3 ) { fail++; pfail3 = "FAIL";  }
	if ( expected4 != actual4 ) { fail++; pfail4 = "FAIL";  }
	if ( expected5 != actual5 ) { fail++; pfail5 = "FAIL";  }
	if ( expected6 != actual6 ) { fail++; pfail6 = "FAIL";  }
	
	cout << "[test_p3 : test1 | " << pfail1 << " ] expected: " << expected1 << " | actual: " << actual1 << endl;
	cout << "[test_p3 : test2 | " << pfail2 << " ] expected: " << expected2 << " | actual: " << actual2 << endl;
	cout << "[test_p3 : test3 | " << pfail3 << " ] expected: " << expected3 << " | actual: " << actual3 << endl;
	cout << "[test_p3 : test4 | " << pfail4 << " ] expected: " << expected4 << " | actual: " << actual4 << endl;
	cout << "[test_p3 : test5 | " << pfail5 << " ] expected: " << expected5 << " | actual: " << actual5 << endl;
	cout << "[test_p3 : test6 | " << pfail6 << " ] expected: " << expected6 << " | actual: " << actual6 << endl;

	if ( fail > 0 )
		cout << endl << "FAILED: " << fail << endl << endl;
}

void test_cs() {
	ifstream a5("a5.cpp");
	string line;
	int linenum = 1;
	int fails = 0;
	
	while ( getline(a5, line) ) {
		// Lines
		if ( line.size() > 80 ) {
			cout << "[test_cs : line : lines:" << linenum << "] Line " << linenum << " has " << line.size() << " charactersc, over the recommended value of 80" << endl;
			fails++;
		}
		
		// Tabs
		for ( size_t i=0; i < line.size(); i++ ) {
			if ( line[i] == '\t' ) {
				cout << "[test_cs : tab : lines:" << linenum << "] Line " << linenum << " a tab. Change that to 4 spaces!" << endl;
				fails++;
			}
		}
		
		linenum++;
	}
	
	if ( fails > 0 ) {
		cout << "FAILED: " << fails << endl << endl;
	} else {
		cout << "PASSED!" << endl << endl;
	}
}

// Helper Methods
stack<int> p1_makeStack(int amt) {
	stack<int> s;

	for ( int i=0; i < (amt*2); i++ ) {
		int num = rand() % 100 + 1; // Pesky 0's
		if ( i % 2 ) {
			s.push((num * -1));
		} else {
			s.push(num);
		}
	}

	return s;
}

vector<int> p3_makeVector() {
	vector<int> vec;
	
	for ( int i=0; i <= 10; i++ ) {
		vec.push_back(i);
	}
	
	return vec;
}