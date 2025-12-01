/*
 * Name: William The
 * Student ID: 301586358
 * Login ID: wta57
 * Copyright: William The 2025
 * Assignment: Assignment 2 Part A
 * Purpose: To modify the code for a hash table implemented by the textbook author.
 */

#include <iostream>
#include "BiMap.h"

using namespace std;

int main() {
    // Create a BiMap of string -> int
    BiMap<int, string> bimap;
    
    // Test initial state
    cout << "Initial BiMap size: " << bimap.getSize() << endl;
    cout << "\nInitial active entries:" << endl;
    bimap.display();
    cout << "Initial BiMap structure:" << endl;
    bimap.ddisplay();

    // Test insert function
    cout << "\nInsert key-value pairs and display:" << endl;
    bimap.insert(0, "January");
    bimap.insert(1, "February");
    bimap.insert(2, "March");
    bimap.insert(3, "April");
    bimap.insert(4, "May");
    bimap.insert(5, "June");
    
    // Display updated state after insertion
    cout << "BiMap size: " << bimap.getSize() << endl;

    cout << "\nActive entries:" << endl;
    bimap.display();
    
    cout << "\nBiMap structure (rehash occurs):" << endl;
    bimap.ddisplay();
    
    // Test containsKey and containsVal
    cout << "\nChecking if keys exist:" << endl;
    cout << "Contains '0'? " << (bimap.containsKey(0) ? "Yes" : "No") << endl;      // expect Yes
    cout << "Contains '10'? " << (bimap.containsKey(10) ? "Yes" : "No") << endl;    // expect No
    
    cout << "\nChecking if values exist:" << endl;
    cout << "Contains 'January'? " << (bimap.containsVal("January") ? "Yes" : "No") << endl;    // expect Yes
    cout << "Contains 'December'? " << (bimap.containsVal("December") ? "Yes" : "No") << endl;  // expect No
    
    // Test getVal and getKey and throw an exception if invalid
    cout << "\nRetrieving values by key:" << endl;
    try {
        cout << "Value for key '1': " << bimap.getVal(1) << endl;   // expect February
    } catch (const exception &e) {
        cout << e.what() << endl;
    }
    
    cout << "\nRetrieving keys by value:" << endl;
    try {
        cout << "Key for value 'March': " << bimap.getKey("March") << endl;   // expect 2
    } catch (const exception &e) {
        cout << e.what() << endl;
    }
    
    // Test remove functions
    cout << "\nRemove pair with key '1' and pair with value 'March':" << endl;
    bimap.removeKey(1);
    bimap.removeVal("March");
    
    // Display updated BiMap
    cout << "Updated BiMap size: " << bimap.getSize() << endl;

    cout << "\nUpdated active entries:" << endl;
    bimap.display();
    
    cout << "\nUpdated full BiMap structure:" << endl;
    bimap.ddisplay();

    // Remove all the pairs in the array
    cout << "\nRemove all pairs:" << endl;
    bimap.makeEmpty();

    cout << "Emptied BiMap size: " << bimap.getSize() << endl;

    cout << "\nEmptied active entries:" << endl;
    bimap.display();
    
    cout << "\nEmptied BiMap structure:" << endl;
    bimap.ddisplay();

    return 0;
}
