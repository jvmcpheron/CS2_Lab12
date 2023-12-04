# CS2_Lab12

## Introduction
In this lab we are simply going to practice using smart pointers instead of raw pointers.  I gave you code for a Binary Search Tree in the three files:

BinaryTree.h
BinaryTree.cpp
bintree-main.cpp
Reimplement the code to remove ALL of the raw pointers and replace them with shared_ptr.  Your resulting code should not have any * operations anywhere or any delete commands in the code.  You should show that nodes still get deleted by adding a destructor to the BinaryNode class that looks like this:

~BinaryNode() {
    cout << "Deleting node with data " << data << "\n";
}
## What to Submit
Submit your solution as a CPP file. Give the file the name AssignmentTypeNumberLastNameFirstName.cpp (so, for example, my submission for Lab 3 would be named Lab3MaclinRichard.cpp). You should also include your first and last name in the file as a comment. Add a long comment in your code showing examples of the results produced from your code making sure to show that nodes are getting automatically deleted.