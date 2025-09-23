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

    // remove from right when list is empty
    list.addRight(100);
    list.addRight(200);
    list.display();  // display 100 200
    list.removeRight();
    list.display();  // display 100

    list.removeRight(); // empty the list

    // trigger an assertion failure
    list.removeRight();  // should trigger assertion error since list is empty

    return 0;
}
