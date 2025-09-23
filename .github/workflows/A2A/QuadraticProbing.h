/*
 * Name: William The
 * Student ID: 301586358
 * Login ID: wta57
 * Copyright: William The 2025
 * Assignment: Assignment 2 Part A
 * Purpose: To modify the code for a hash table implemented by the textbook author.
 */

#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int nextPrime(int n);     // used for sizing the hash table to the next prime number

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert(x)       --> Insert x
// bool remove(x)       --> Remove x
// bool contains(x)     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hashCode(string str) --> Global method to hash strings

template <typename HashedObj>
class HashTable
{
  public:
    // onstructor: creates hash table with size 101 or the next prime number
    explicit HashTable( int size = 101 ) : array( nextPrime( size ) )
      { makeEmpty( ); }

    // check if x is present in the hash table
    bool contains( const HashedObj & x ) const
    {
        return isActive( findPos( x ) );
    }

    // remove all items from table
    void makeEmpty( )
    {
        currentSize = 0;
        for( auto & entry : array )
            entry.info = EMPTY;
    }

    // insert x into hash table, return false if x is present
    bool insert( const HashedObj & x )
    {
            // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        if( array[ currentPos ].info != DELETED )
            ++currentSize;

        array[ currentPos ].element = x;
        array[ currentPos ].info = ACTIVE;

            // Rehash; see Section 5.5 
            // Rehash if BiMap is 50% full
        if( currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }
    
    // insert x into hash table, return false if x is present
    bool insert( HashedObj && x )
    {
            // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        if( array[ currentPos ].info != DELETED )
            ++currentSize;

        array[ currentPos ] = std::move( x );
        array[ currentPos ].info = ACTIVE;

            // Rehash; see Section 5.5
            // Rehash if BiMap is 50% full
        if( currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }

    // remove x from the hash table, return false if x does not exist
    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }

    // types of entry (or status)
    enum EntryType { ACTIVE, EMPTY, DELETED };

  private:
    struct HashEntry
    {
        HashedObj element;  // stored element
        EntryType info;     // type: ACTIVE, EMPTY, or DELETED

        HashEntry( const HashedObj & e = HashedObj{ }, EntryType i = EMPTY )
          : element{ e }, info{ i } { }
        
        HashEntry( HashedObj && e, EntryType i = EMPTY )
          : element{ std::move( e ) }, info{ i } { }
    };
    
    vector<HashEntry> array;        // hash table storage
    int currentSize;                // number of active elements in hash table

    // check if entry at current position is active
    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    // find position where x is located using quadratic probing
    int findPos( const HashedObj & x ) const
    {
        int offset = 1;
        int currentPos = myhash( x );

        while( array[ currentPos ].info != EMPTY &&
               array[ currentPos ].element != x )
        {
            currentPos += offset;  // Compute ith probe
            offset += 2;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    // rehash if table becomes 50% full
    void rehash( )
    {
        vector<HashEntry> oldArray = array;

        // create a new table with double the size, adjusted to the next prime number
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for( auto & entry : array )
            entry.info = EMPTY;

            // Copy table over
        currentSize = 0;
        for( auto & entry : oldArray )
            if( entry.info == ACTIVE )
                insert( std::move( entry.element ) );
    }

    // find hash index for x
    size_t myhash( const HashedObj & x ) const
    {
        static hash<HashedObj> hf;
        return hf( x ) % array.size( );
    }
};

#endif
