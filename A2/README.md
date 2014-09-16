#Assignment 2, Due at 11:59pm, Sunday Sep 14

-----

## Objectives
* Getting slightly more comfortable with C++: make use of vector and set data structures, and learn how to sort elements of a vector.
* Get a sense of how different data structure (and algorithm) choices can have a huge effect on the runtime of your program. Later on in the course, you will see that we could have known "in advanced" which of the two algorithms (sba and vba below) we should have chosen without even implementing them. We will have much more to say about analyzing the kind of data structures and algorithms to solve more complicated problems than this one.
* Get a sense of the asymptotic behavior of your program once the input gets big. This is one of the key points of this course: proper use of data structures and algorithms will make programs much more robust and scalable.
* Learn how to work within the constraints of a code-base which is already given to you. (In the wild, programmers rarely write codes from scratch: we improve, modify, maintain a code-base that other people have written.)

## Overview of what to do
You are to write a C++ program that does roughly the following. The program reads a file -- in a specific format to be described below -- that stores the set of edges of a graph. The file might (or might not) store some edges more than once. The task of the program is to count the number of distinct edges. There are many ways to do this task. You will implement two different algorithms for performing the task.
    
* Algorithm 1, called the vector-based algorithm (or vba for short) does the following:
    * it reads the set of edges stored in the file into a vector.
    * Sort the vector.
    * Then, it loops through the elements of the vector one by one. If an element is equal to the next element, i.e. a duplicate edge is found, then the element is removed.

    This algorithm uses the built-in sort algorithm and the erase function. When all elements of the vector have been traversed, the vector's size is reported.

* Algorithm 2, called the set-based algorithm (or sba for short) does the following: it reads the edges stored in the file one by one, for each edge read the algorithm inserts the edge into a std::set. Since std::set is a data structure that stores unique elements, duplicated edges will not be inserted. In the end, the algorithm reports the size of the resulting set.

## Example Input
```
# Graph : p2p-Gnutella04.txt 
# Directed Gnutella P2P network from August 4 2002
# Nodes: 6 Edges: 11
# FromNodeId	ToNodeId
1	3
1	4
2	4
3	1
6	2
3	5
3	6
4	2
1	3
4	4
6	2

```

