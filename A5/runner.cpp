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
vector<int> p3_makeVector(int amount);

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

	for ( int i=1; i < 10; i++ ) {
		int amount = rand() % 1000;
		vector<int> vec = p3_makeVector(amount);
		string pfail = "FAIL";

		int target;
		bool expected;

		if ( (rand() % 100) > 50 || amount == 0 ) {
			target = amount;
			expected = true;
		} else {
			target = amount / 2;
			expected = false;
		}

		int actual = sum_to_target(vec, target);

		if ( expected == actual ) {
			pfail = "PASS";
		} else {
			fail++;
		}

		cout << "[test_p3 : test" << i << " | " << pfail << " ] expected: " << expected << " | actual: " << actual << endl;
	}

	if ( fail > 0 )
		cout << endl << "FAILED: " << fail << endl << endl;
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

vector<int> p3_makeVector(int amount) {
	vector<int> v;
	int needed = amount;

	for ( int i=0; i < amount; i++ ) {
		int num1 = rand() % 100 + 1; // Pesky 0's
		int num2 = rand() % 10 + 1;

		if ( i % 2 ) {
			if ( needed - num2 > 0 ) {
				v.push_back(needed-num2);
				needed -= num2;
			} else {
				v.push_back(num1);
			}
		} else {
			v.push_back(num1);
		}
	}

	return v;
}
