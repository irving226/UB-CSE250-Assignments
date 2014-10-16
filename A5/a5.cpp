//===========================
// a5.cpp
// -------
// @author: James Droste <james@droste.im>
//===========================

// *
#include <stack>
#include <vector>

using namespace std;
//*/

/*
 * (Problem 1A) iterative_num_negatives
 * Initial usage: iterative_sub_vector(int_stack)
 *
 * Looks through a stack of int's, returns the count of ints that
 * are negative.
 *
 * @param stack<int> int_stack The stack we're looking through
 * 
 * @return size_t The number of negatives contained in int_stack
 */
size_t iterative_num_negatives(stack<int> int_stack) {
    size_t num = int_stack.size();
    while ( !int_stack.empty() ) {
        if ( int_stack.top() >= 0 ) num--;
        int_stack.pop();
    }

    return num;
}

/*
 * (Problem 1B) recursive_num_negatives
 * Initial usage: recursive_num_negatives(int_stack)
 *
 * Looks through a stack of int's, returns the count of ints that
 * are negative.
 *
 * @param stack<int> int_stack The stack we're looking through
 * 
 * @return size_t The number of negatives contained in int_stack
 */
size_t recursive_num_negatives(stack<int> int_stack) {
    if ( int_stack.empty() ) return 0;

    int t = (int_stack.top() < 0);
    int_stack.pop();

    return t + recursive_num_negatives(int_stack);
}

/*
 * (Problem 2A) iterative_sub_vector
 * Initial usage: iterative_sub_vector(a, b)
 *
 * Looks through a vector(b), and see's if it contains the
 * another vector(a)
 *
 * @param vector<int> a The vector we want to find, inside of b
 * @param vector<int> b The vector we're looking through
 * 
 * @return bool If a is contained inside of b
 */
bool iterative_sub_vector(vector<int>& a, vector<int> b) {
    if ( a.size() > b.size() ) return false;
    if ( a.empty() ) return true;

    for ( size_t i=0, k=0; i < b.size(); i++, k++ ) {
        // Reset
        if ( k > 0 && b[i] != a[k] ) k = 0;
        
        // At the "end" of a
        if ( k == a.size()-1 ) return true;
    }

    return false;
}

/*
 * (Problem 2B) recursive_sub_vector
 * Initial usage: recursive_sub_vector(a, b, 0)
 *
 * Looks through a vector(b), and see's if it contains the
 * another vector(a)
 *
 * @param vector<int> a The vector we want to find, inside of b
 * @param vector<int> b The vector we're looking through
 * @param size_t      k The current position we're on
 * 
 * @return bool If a is contained inside of b
 */
bool recursive_sub_vector(vector<int>& a, vector<int> b, size_t k) {
    if ( a.size() > b.size() ) return false;
    if ( a.empty() ) return true;

    for ( size_t i=0; k < b.size(); i++,k++ ) {
        // i is already inc, so we don't have to do size-1
        if ( i == a.size() ) {
            return true;
        } else if ( b[k] != a[i] ) {
            return recursive_sub_vector(a, b, ++k);
        }
    }

    return false;
}

/*
 * (Problem 3) sum_to_target
 * Initial usage: sum_to_target(int_vec, target)
 *
 * Checks if any permutation of int_vec will add up to the target.
 *
 * @note: tl;dr this is basically brute forcing...
 *
 * @param vector<int> int_vec The vector that we're looking through
 * @param int         target  The target number
 * 
 * @return bool If the target is a subsum of int_vec
 */
bool sum_to_target(vector<int>& int_vec, int target) {
    if ( target == 0 ) return true;
    int amt = 0; size_t size = int_vec.size();
    
    for( size_t bitset=0, end=(1 << size); bitset < end; bitset++, amt=0 ) {
        for ( size_t pos=0; pos < size; pos++ ) {
            if ( bitset & (1 << pos) ) amt += int_vec[pos];
            if ( amt > target ) break;
        }
        
        if ( amt == target ) return true;
    }
    
    return false;
}
