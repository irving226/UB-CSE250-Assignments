//===========================
// a5.h
// -------
// @author: James Droste <james@droste.im>
//===========================

#ifndef A5_H_
#define A5_H_

#include <stack>
#include <vector>
using namespace std;

// Problem 1
size_t iterative_num_negatives(stack<int> int_stack);
size_t recursive_num_negatives(stack<int> int_stack);

// Problem 2
bool iterative_sub_vector(vector<int>& a, vector<int> b);
bool recursive_sub_vector(vector<int>& a, vector<int> b, size_t k);

// Problem 3
bool sum_to_target(vector<int>& int_vec, int target, size_t k);

#endif
