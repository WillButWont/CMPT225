/*
 * Name: William The
 * Student ID: 301586358
 * Login ID: wta57
 * Copyright: William The, 2025
 * Assignment: Assignment 3 Part A
 * Purpose: To implement an indexed priority queue using a heap and a hash map to efficiently support priority updates.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include "IndPQ.h"

using namespace std;

int main() {
    IndPQ pq;
    pq.insert("task1", 7);
    pq.insert("task2", 3);
    pq.insert("task3", 1);
    pq.insert("task4", 5);
    
    cout << "Initial queue Contents: " << endl;
    pq.display();       // prints queue contents

    cout << "Intiial representation of the data structures: " << endl;
    pq.ddisplay();      // prints representation of the data structures

    cout << "Min: " << pq.getMin() << endl;

    cout << "Update priority of task1 to 0:" << endl;
    pq.updatePriority("task1", 0);

    cout << "Min after update: " << pq.getMin() << endl;
    
    cout << "Delete min: " << pq.deleteMin() << endl;
    cout << "Min after delete: " << pq.getMin() << endl;
    
    cout << "Queue Contents: " << endl;
    pq.display();       // prints queue contents
    
    cout << "Representation of the data structures: " << endl;
    pq.ddisplay();      // prints representation of the data structures
    
    return 0;
}