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

    // test to add to left when list is full
    for (int i = 0; i < 12; ++i) { 
        list.addLeft(i);
    }
    list.display();  // list should have 12 elements (11 to 0)

    // trigger an assertion failure
    list.addLeft(30);  // should trigger assertion error since list is full

    return 0;
}
