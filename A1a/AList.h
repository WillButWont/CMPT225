#ifndef ALIST_H
#define ALIST_H

#include <iostream>
using namespace std;

template <typename Object>
class AList 
{
  public:
    AList()
      {  
         theCapacity = 12 ;
         objects = new Object[ theCapacity ]; 
         theSize = 0 ;
         left = 0 ; // array index of location just before the left-most list element 
         right = 1 ; // array index just past the right-most list element
      }
      
    ~AList( )
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }
    void clear( ){
        // remove all list contents 
        // 
        // Implement this...

        theSize = 0;
        left = 0;
        right = 1;
    }

    // Operations 

    void addLeft( const Object x )// Insert a new object at the left end 
    {
	// Implement this....
      theSize++;
      objects[left] = x;
      left = (left - 1 + theCapacity) % theCapacity;
    }

    void addRight( const Object x )// Insert a new object at the right end
    {
	    theSize++ ;
      objects[right] = x ;
      right = (right + 1) % theCapacity;
    }

    Object removeRight( )// Remove and return the object at the right end
    {
        // Implement this
        right = (right - 1 + theCapacity) % theCapacity;
        Object result = objects[right];
        objects[right] = 0;
        --theSize;
        return result; 
    }

    Object removeLeft( )// Remove and return the object at the left end
    {
        // Implement this 
      left = (left + 1) % theCapacity;
      Object result = objects[left];
      objects[left] = 0;
      --theSize;
      return result;
    }

    void display() const // print out the contents of the deque
    {
       // Implement this.
      for (int i = 0; i < theSize; ++i)
       {
        cout << objects[(left + i + 1) % theCapacity] << " ";
       }
        cout << endl;

    }

    void ddisplay() const // print out the contents of the objects 
    // array, and relevant variables, for debugging or verifying 
    // correctness. 
    {
        // Implement this. 
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
