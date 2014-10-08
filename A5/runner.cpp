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

using namespace std;

// Prototypes
void test_p1_a();
void test_p1_b();
stack<int> p1_makeStack(int neg);
void test_p2_a();
void test_p2_b();
void test_p3();

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
		
		cout << "[test_p1_a : test" << i << " | " << pfail << " ] expected: " << neg << "  | actual: " << actual << endl;
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
		
		cout << "[test_p1_b : test" << i << " | " << pfail << " ] expected: " << neg << "  | actual: " << actual << endl;
	}
	
	if ( fail > 0 )
		cout << endl << "FAILED: " << fail << endl;
}

void test_p2_a() { }

void test_p2_b() { }

void test_p3() { }

// Helper Methods
stack<int> p1_makeStack(int amt) {
	stack<int> s;
	int neg = 0;

	for ( int i=0; i < (amt*2); i++ ) {
		int num = rand() % 100 + 1; // Pesky 0's
		if ( i % 2 ) {
			s.push((num * -1));
			neg++;
		} else {
			s.push(num);
		}
	}
	
	return s;
}
