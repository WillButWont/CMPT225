/*
 * Name: William The
 * Student ID: 301586358
 * Login ID: wta57
 * Copyright: William The, 2025
 * Assignment: Assignment 1 Part B
 * Purpose: Add assertions that exactly check the requirements, and print out an appropriate message when they fail.
 */

#include "AList.h"
#include <iostream>

int main() {
    AList<int> list;

    // test to add to right when list is full
    for (int i = 0; i < 12; ++i) {  
        list.addRight(i);
    }
    list.display();  // list should have 12 elements (from 0 to 11)

    // trigger an assertion failure
    list.addRight(300);  // should trigger assertion error since list is full

    return 0;
}
