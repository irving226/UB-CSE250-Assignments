#Assignment 1, Due at 11:59pm, Sunday Sep 07

-----

## Objectives
* Write your first non-trivial C++ program, making use of basic control structures.
* Familiarize yourself with elementary processing of strings and files in C++.
* Think about program design: "design, then code." It is very important that you think about the design of your program before sitting down and coding.

## What to do
You are to write a C++ program that does the following.

1. It keeps reading user's inputs, line by line. Each input line the user types is supposed to be in one of the following three forms:

    ```
    numcols filename
    numrows filename
    exit
    ```
    
    where
    
    * filename is the name of a text file. The file contains a set of lines; each line is a list of words separated by spaces or tabs. Each word is a series of (ASCII) characters with no tab nor space in between them. For example, the content of the file test.txt might look like this

    ```
    this is    a file
     that has seven columns and four rows. 
     Note that rows might have 
     different numbers of columns.
    ```
    
    In this file, the first row has 4 words, second has 7, third has 5, and fourth has 4.


    * numcols stands for "number of columns" of filename, which is the maximum number of words that a row has.
    * numrows stands for "number of rows", which is the number of lines in the file.
    * exit tells your program to quit


2. If the user types exit, then your program quits.

3. The other two commands numrows and numcols reports the number of columns and the number of rows the file has.

4. For example, if the file test.txt has the content as shown above, then the output of the program looks as follows.

    ```
    > numrows test.txt
    4
    > numcols test.txt
    7
    > numcols anothertest.txt
    6
    > exit
    ```

    Here, anothertest.txt is some other file that has 6 columns. Your program has to keep running until the user types exit.

