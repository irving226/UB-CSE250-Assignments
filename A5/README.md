## Assignment 5, Due at 11:59pm, Tue Oct 14

### Objectives

### Sample problems and sample solutions

##### Sample problem 1

A string of characters is a [palindrome](http://en.wikipedia.org/wiki/Palindrome) if it reads the same from left to right as from right to left. For example, the names "anna", "bob",and "otto" are palindromes. A former prime minister of Cambodia was "lon nol", which is a palindrome. Phrases such as "step on no pets" and "rats live on no evil star" are palindromes.

You are to write a function that takes an input string and returns `true` if the input is a palindrome, and `false` otherwise. You will write an iterative and a recursive version of the function, whose signatures are as follows. 
You **must** use the signature (i.e. prototype) given. **No helper function is accepted**.

Note that by definition an empty string is a palindrome. So your function must return `true` if the input string is empty. Also, you can assume that all characters are in lower case.

`bool iterative_palindrome(const string& str) 
{
    // your code goes here
}
`

For the recursive solution, given an input string `str` we will call the following function with 

`recursive_palindrome(str, 0, str.length())` 

In particular, note that `end` is one more than the index of the last character. (Recall the `size_t` issue with iterative binary search 2 in the lecture slides.)

`bool recursive_palindrome(const string& str, size_t start, size_t end) 
{
    // your code goes here
}
`

##### Sample solution 1

The iterative solution
`
// Would you agree that it's much cleaner than the recursive one?
bool iterative_palindrome(const string& str) 
{
    for (size_t i=0; i<str.length()/2; i++) {
        if (str[i] != str[n-1-i]) return false;
    }
    return true;
}
`

The recursive solution
`
// the initial call is recursive_palindrome(str, 0, str.length()) 
bool recursive_palindrome(const string& str, size_t start, size_t end) 
{
    if (start >= end) return true;
    return (str[start] == str[end-1]) && 
           recursive_palindrome(str, start+1, end-1);
}
`

##### Sample problem 2

Given a non-negative integer `n`, write the iterative and recursive versions of a function that takes a non-negative integer `n` and returns a string which represents `n` in binary. For example,

You **must** use the signature (i.e. prototype) given. **No helper function is accepted**.

`
// the iterative solution
string iterative_binrep(size_t n) 
{
    // your code goes here
}

// the recursive solution
string recursive_binrep(size_t n) 
{
    // your code goes here
}
`

##### Sample solution 2

`
// the iterative solution
string iterative_binrep(size_t n) {
    string ret;
    do {
        ret.insert(0, (n%2 == 0? "0" : "1"));
        n = n/2;
    } while (n > 0);
    return ret;
}

// the recursive solution. Would you agree that it's much cleaner?
string recursive_binrep(size_t n) {
    if (n == 0) return "0";
    if (n == 1) return "1";
    return recursive_binrep(n/2) + (n%2 == 0? "0" : "1");
}
`

### What to do? Solve the following problems

##### Problem 1

Write the iterative and recursive versions of a function that takes in a 
stack of integers and returns the number of negative integers from the stack.
You **must** use the signature (i.e. prototype) given. 
**No helper function is accepted**.

`
// the iterative solution
size_t iterative_num_negatives(stack<int> int_stack)
{
    // your code goes here
}

// the recursive solution, the initial call is 
size_t recursive_num_negatives(stack<int> int_stack)
{
    // your code goes here
}
`

##### Problem 2

Write the iterative and recursive versions of a function that takes in two vectors `a` and `b`, both are `vector<int>`, and returns whether one vector is a _sub-vector_ of the other. 

`a` is a sub-vector of `b` if we can find an exact copy of `a` in some contiguous block of elements of `b`. For example, `[1 -2 5 3]` is a sub-vector of `[10 -2 1 -2 5 3 4 6 8]`, but it is not a sub-vector of `[10 -2 1 -2 5 4 3 6 8]`.

You **must** use the signature (i.e. prototype) given. **No helper function is accepted**.

`
// the iterative solution
int iterative_sub_vector(vector<int>& a, vector<int> b)
{
    // your code goes here
}

/** 
 * the recurive solution, you CAN NOT call erase NOR copy many elements of 
 * b into a separate vector. The function prototyp is already a hint
 * the initial call is recursive_sub_vector(a, b, 0)
 */
int recursive_sub_vector(vector<int>& b, vector<int> b, size_t k)
{
    // your code goes here
}
`

##### Problem 3

In this problem, you are free to pick any type of solution (iterative or recursive) you want. You are to write a function called `sum_to_target` that takes a vector of integers `int_vec` and a target integer `target`. The function returns `true` if there is a subset of integers in `int_vec` that sums to `target`, and `false` otherwise. If `target == 0`, then the answer is always `true`, because the empty subset sums to `0`. If your solution is recursive, feel free to add extra parameters to your function to accomodate the recursion. (For example, `recursive_sub_vector` above has an extra parameter.) In that case, please indicate the initial call to get the recursion started.

### How to submit

Please type **all** your functions in properly indented cpp; put them in the same text file, named `a5.cpp`. 

Please only include those functions in the submission; You can (and should) 
compile and test your functions, but when you submit please remove the extra 
pieces of codes you use to test them. (For example, 
`#include<iostream>` and `main()` should not be 
included in the submission. We grade the submission by reading only the code 
you put in the functions' bodies.
