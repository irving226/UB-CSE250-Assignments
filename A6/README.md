## Assignment 6, Due at 11:59pm, Tue Oct 28

### Objectives
* Practice manipulating linked lists.
* Practice implementing a class (whose interface has already been designed).
* In the previous assignments, we have dealt quite extensively with the most basic data structure: a vector. Vectors and arrays allow for constant-time random access. (E.g., you can say vec[10] and get the answer in constant time. This is due to the fact, illustrated in our UBVector implementation, that the internal storage of a vector is a contiguous block of memory.) Lists and pointer-based trees do not allow for random access like that. To access and modify the lists we often have to manipulate the pointers and traverse the pointers to find elements or rearrange elements in the lists.
* The first main objective of this assignment is for you to practice manipulating singly linked lists. In "practice," you will occasionally have to do some of the tasks specified in this assignment.
* The second main objective of this assignment is for you to get really comfortable with pointer manipulation. I cannot emphasize enough the importance of being able to deal with pointers in your future jobs.
* The third main objective of this assignment is for you to get used to implementing a C++ class.


### What to do

You are to write a C++ program that does the following. 

* It keeps reading user's inputs, line by line. Each input line the user
 types is supposed to be in one of the following forms:

```
new    listname [list of non-negative integers separated by space]
print  listname
remove listname [an int]
merge  listname1 listname2
sort   listname
exit
```

where 
* `exit` tells your program to quit 
* `listname` is an identifier (you can just think of it 
 as a valid C++ variable name). For example, `a, _a34, counter` are 
 all valid variable names.
* `[list of non-negative integers separated by space]` is ...  
 a list of non-negative integers separated by spaces, such as 
 `3 8 10 2 0`
* `[an int]` is any integer, such as `531`
* `new` tells your program to create a new linked list of
 `Node`s of the following type

```
struct Node 
{
    int   key;                                                                  
    Node* next;                                                                 
    Node(int k=0, Node* n=NULL) : key(k), next(n) {};                           
};
```

 the linked list constains a list of `Node`s whose keys are the 
 integers provided in the input list, in the order given. You can then print 
 out the list with the next command

 * `print listname` prints the list held by the list
 `listname`.

 * `remove x` takes a list and remove from the list all nodes
 whose key is equal to `x`. (`delete` those pointers!) 

 * `merge l1 l2` merges two lists that are already sorted into
 one, destroying `l2` and keep the result in `l1`. 
 If the input lists are not already sorted then an exception is
 thrown and the error is reported to the screen.

 * `sort listname` sorts the linked list held by 
 `listname`. You will have to implement the merge sort algorithm.
 (See the [sorting lectures](http://cse250.wordpress.com/2014/10/16/basic-searching-and-sorting/) for more information.) This time, however, you are 
 sorting linked lists so you'll need to understand the key idea of merge sort
 to adapt to the linked list case. 

 Unlike in the vector/array sorting case, here **you must not modify 
 any key** in the nodes, in particular **do not swap keys**. 
 Sorting is done by manipulating the pointers 
 (`head` and `next` and so on). There are two reasons for 
 this. As stated above, this is a pointer manipultion exercise -- a super 
 important skill to master. Second, in practice there are cases where it is not 
 a good idea to move the content of the nodes (say, they are on disks) which 
 can be massive. Modifying the pointers are much cheaper oprations.

 * **The real task**: 
 I have written the program already, leaving a few functions blank.
 Your task is to understand my code and implement the three functions 
 `UBList.remove()`,
 `UBList.merge()`,
 `UBList.sort()`.

 **Please do make sure that you understand the code base completely!
     In particular, you should understand what each of the data members and
     function members (which have been implemented) does.**

 * First, to get a sense of what the program is supposed to do, please
 download [its binary](listmanip) named `listmanip`. 
 The binary can run under `timberlake` as usual. You can get it by
 typing
```
wget http://www.cse.buffalo.edu/~hungngo/classes/2014/Fall/250/assignments/listmanip
chmod 700 listmanip
```

 Here is a sample run of `listmanip`:

```
[HQN@mymachine] $ listmanip
UBList: practice manipulating linked lists
> new a =  1 6 3 5 8 1 2 8 5 3
> print a
[10 NODES] : 1 6 3 5 8 1 2 8 5 3 
> new b = 2 6 2 6 2
> print b
[5 NODES] : 2 6 2 6 2 
> remove a 5
> print a
[8 NODES] : 1 6 3 8 1 2 8 3 
> sort a
> print a
[8 NODES] : 1 1 2 3 3 6 8 8 
> sort b
> print b
[5 NODES] : 2 2 2 6 6 
> merge a b
> print a
[13 NODES] : 1 1 2 2 2 2 3 3 6 6 6 8 8 
> print b
[0 NODES] : 
> exit
```

To download the code base, click [here](A6.tar), or
 from your timberlake account type

```wget http://www.cse.buffalo.edu/~hungngo/classes/2014/Fall/250/assignments/A6.tar```

 It is a tarred file. You can untar it using

```
tar -xvf A6.tar
```

 After those two commands, you'll see a directory named `A6`
 which contains all source files, including a `Makefile`. 
 You can already compile and run it! It does `new` and `print` already. Compile with `make`, and run it to see what's going on. 
 * Finally, **the only file you can modify is
 `UBList.cpp`**. You are to supply the body of 
 the functions that have `YOUR CODE GOES HERE` in the body.
 What each function is supposed to do is described in the comments inside the
 function's body in `UBList.cpp`.
 **Do not add any auxiliary functions**.

* When you submit your assignment, you will only submit **one**
 file: `UBList.cpp`. We will copy this file to a directory 
 containing all other files and compile and grade. 
 **Don't** modify any other files. This is to illustrate how you 
work within a code base that someone else has written. 

