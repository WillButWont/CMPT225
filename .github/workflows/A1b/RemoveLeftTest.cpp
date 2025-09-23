/*
 * Name: William The
 * Student ID: 301586358
 * Login ID: wta57
 * Copyright: William The 2025
 * Assignment: Assignment 1 Part B
 * Purpose: Add assertions that exactly check the requirements, and print out an appropriate message when they fail.
 */

#include "AList.h"
#include <iostream>

int main() {
    AList<int> list;

    // remove from left when list is empty
    list.addLeft(10);
    list.addLeft(20);
    list.display();  // display 20 10
    list.removeLeft();
    list.display();  // display 10

    list.removeLeft();   // empty the list

    // trigger an assertion failure
    list.removeLeft();  // should trigger assertion error since list is empty

    return 0;
}
