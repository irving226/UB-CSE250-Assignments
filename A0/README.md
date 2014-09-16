#Assignment 0, Due at 11:59pm, Sunday Aug 31

-----

## Objectives
* Edit and compile your first (?) C++ program.
* Get used to the submit system.
* Report on what you did the first week in terms of getting a hold of g++ and a text editor on your $
* Try a simple Makefile
* Get free points as a gift from me!

## What to do
Please perform the following tasks.

1. In (a subdirectory) of your home directory of your CSE account, create a sub-directory called A0 by typing

    ```
    mkdir A0
    cd A0
    ```

2. Create three files in that sub-directory named report.cpp, Makefile, and README. File names are case sensitive! It is recommended that you use either emacs/xemacs or vi/vim to edit those files. nano would be OK too if you are not yet comfortable with vi/emacs. You can also edit the files using your favorite editor (Eclipse, Nodepad++, sublime text, etc.) from your home/laptop OS and upload them to your CSE account. There's no way I know how you did it.

3. Type the following piece of code to report.cpp (please do not cut-and-paste, though I wouldn't know if you cut-and-pasted or typed, I'd recommend typing to get a sense of the editor, the C++ syntax, and indentation, ...)

    ```c
    // report.cpp
    #include <iostream>
    using namespace std;

    int main() {
    string my_name = "David Blaine"; // edit this
    string my_text_editor = "emacs"; // edit this
    string my_home_os = "Windows";   // edit this
    bool i_worked = true;            // set to false if you didn't do work
    
    cout << "My name is " << my_name << endl;

    if (i_worked) {
        cout << "I was able to install and test g++ and "
             << "the text editor " << my_text_editor << '\n'
             << "in my home computer/laptop, which runs "
             << my_home_os << endl;
    } else {
        cout << "I wasn't able to install and test g++ and/or a text "
             << "editor because ... " // give a lame reason here
             << endl;
    }
    return 0;
}
    ```

    You must modify the program so that it reports things about you. Now, to compile the above program, you can do g++ report.cpp and run it with a.out. However, I'd like you to try an extremely simple Makefile too.


4. Create a file named Makefile in the same directory whose content consists of the following lines:

    ```
    all:
    	g++ report.cpp

    clean:
        rm -f a.out
    ```

    For the Makefile to work, it is crucial that there is exactly one tab before g++ on the second line, and there is exactly one tab before rm on the 5th line. (The 3rd line is empty.) Then, when you type make at the command line you'll get the same effect as if you were typing g++ report.cpp. You can run the program by typing a.out or ./a.out if your $PATH variable was not set correctly.


5. Create a file named README with the following content:

    ```
    Name: David Blaine       // please replace with YOUR name
    Person number: 1234-5678 // please replace with YOUR person numer
    ```

## How to submit
Now that you have three files (hopefully working!) in the directory. There might also be the a.out file that was compiled and run. We do not want you to submit executables, only the source files. Hence, please type

    make clean

at the prompt before submitting. The effect is to remove the a.out file, if any, that was created.
Finally, to submit, create a tar ball of the directory as follows.

    cd ..
    tar -cvf A0.tar A0/*
    submit_cse250 A0.tar

Note that the last line only works if you logged in to your CSE account and the tar file is there. All previous things can be done at home, as long as you remember to upload the final tar file to your CSE account and run the submit script from there.

