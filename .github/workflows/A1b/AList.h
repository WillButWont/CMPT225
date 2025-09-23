/*
 * Name: William The
 * Student ID: 301586358
 * Login ID: wta57
 * Copyright: William The 2025
 * Assignment: Assignment 1 Part B
 * Purpose: Add assertions that exactly check the requirements, and print out an appropriate message when they fail.
 */

#ifndef ALIST_H
#define ALIST_H

#include <iostream>
#include <cassert>      // add assert function
using namespace std;

template <typename Object>
class AList 
{
  public:
    AList()
      {  
         theCapacity = 12;
         objects = new Object[theCapacity]; 
         theSize = 0;
         left = 0; // array index of location just before the left-most list element 
         right = 1; // array index just past the right-most list element
      }
      
    ~AList()
      { delete[] objects; }

    bool empty() const  { return size() == 0; }
    int size() const { return theSize; }
    
    void clear()
    {
        theSize = 0;
        left = 0;
        right = 1;
    }

    // Operations 

    void addLeft(const Object x) // Insert a new object at the left end 
    {
        // Before: The list must not be full (theSize < theCapacity)
        // After: The object is added to the left end, and the size is incremented by 1
        assert(theSize < theCapacity && "Error: Cannot addLeft, AList is at full capacity");
        
        left = (left - 1 + theCapacity) % theCapacity;
        objects[(left + 1) % theCapacity] = x;
        theSize++;
    }

    void addRight(const Object x) // Insert a new object at the right end
    {
        // Before: The list must not be full (theSize < theCapacity)
        // After: The object is added to the right end, and the size is incremented by 1
        assert(theSize < theCapacity && "Error: Cannot addRight, AList is at full capacity");
        
        objects[right] = x;
        right = (right + 1) % theCapacity;
        theSize++;
    }

    Object removeRight() // Remove and return the object at the right end
    {
        // Before: The list must not be empty (theSize > 0)
        // After: The object at the right end is removed, the size is decremented by 1, and the list is updated accordingly
        assert(!empty() && "Error: Cannot removeRight, AList is empty");
        
        right = (right - 1 + theCapacity) % theCapacity;
        Object result = objects[right];
        objects[right] = 0;
        --theSize;
        return result; 
    }

    Object removeLeft() // Remove and return the object at the left end
    {
        // Before: The list must not be empty (theSize > 0)
        // After: The object at the left end is removed, the size is decremented by 1, and the list is updated accordingly
        assert(!empty() && "Error: Cannot removeLeft, AList is empty");
        
        left = (left + 1) % theCapacity;
        Object result = objects[left];
        objects[left] = 0;
        --theSize;
        return result;
    }

    void display() const // Print out the contents of the deque
    {
        for (int i = 0; i < theSize; ++i)
        {
            cout << objects[(left + i + 1) % theCapacity] << " ";
        }
        cout << endl;
    }

    void ddisplay() const // Print out the contents of the objects array for debugging
    {
        cout << "Size: " << theSize << ", Left: " << left << ", Right: " << right << endl;
        cout << "Array contents: ";
        for (int i = 0; i < theCapacity; ++i) {
            cout << objects[i] << " ";
        }
        cout << endl;
    }

  private:
    int theSize;
    int left;
    int right;
    int theCapacity;
    Object * objects;
};

#endif
