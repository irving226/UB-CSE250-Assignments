#Assignment 3, Due at 11:59pm, Tuesday Sep 23

-----

## Objectives
* Practice using stack to solve a common problem in parsing. And perhaps make use of a map too.
* Practice using a Lexer class that I provided
* Learn a very rough idea of how HTML parsing and rendering might be done by web browsers.
* Learn how to use many more built-in data structures in C++: map, vector, stack, set.
* Learn how to work within the constraints of a code-base which is already given to you. (In the wild, programmers rarely write codes from scratch: we improve, modify, maintain a code-base that other people have written.)

## The 250HTML markup language
Recall that in HTML we can change text attributes by surrounding the text with a pair of tags, e.g.

```
<b>This is bold</b>, <i>this is italic</i>, 
<b>bold again <i>and italic at the same time</i></b>, 
and <u>underlined</u>, and back to normal.
```

Of course, not all HTML files are correctly tagged. For example, the following is not tagged correctly

```
<b>Bold text<i> and italic</b>
```

The World Wide Web Consortium (W3C) has a service allowing us to validate any HTML file, confirming whether the file is well-formed. In this assignment, we will make up our own HTML-like language, and implement a "validator" for the language. Also, we will write a function that renders (displays) a text string (or expression) marked up in our language correctly.
Let's call our language "250HTML". The language accepts the following tags:
* Foreground color tags: <red>, <green>, <yellow> <blue> <magenta> <cyan>, and their corresponding closing tags </red>, </green>, </yellow> </blue> </magenta> </cyan>.
* Three more text attribute tags and their closing counterparts <dim>, <underline>, <bright>, </dim>, </underline>, </bright>

The tags correspond to a subset of the text attributes and colors that we can easily set using terminal control codes I discussed already. Valid input expressions in 250HTML look as follows.

```
<red>Red <dim>dim and red</dim> back to red</red>

<yellow>Yellow <underline>underlined yellow <dim>dim</dim> underlined yellow</underline> and <cyan>cyan</cyan> and yellow again</yellow>
```

An invalid 250HTML expression consists of the following type of errors:
* INVALID TOKEN: Tags are not formatted correctly, such as a tag with < but no closing > (whether or not the tag is valid)
* UNKNOWN TAG: An unknown tag is included, such as <some tag>
* EXPRESSION NOT WELL-FORMED:
    * Improperly nested tag pairs, such as in the following line

    ```
    <blue>Blue <underline>underlined blue <dim>dim</dim> underlined blue</blue> </underline>
    ```

    * An open tag with no matching close tag or vice versa.

We verify whether the expression is well-formed using a stack as I discuss in class.

