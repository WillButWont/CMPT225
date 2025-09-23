/*
 * Name: William The
 * Student ID: 301586358
 * Login ID: wta57
 * Copyright: William The 2025
 * Assignment: Assignment 2 Part A
 * Purpose: To modify the code for a hash table implemented by the textbook author.
 */

#ifndef BIMAP_H
#define BIMAP_H

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
using namespace std;

int nextPrime( int n );

/**
 * Internal method to test if a positive number is prime
 * Not an efficient algorithm.
 */
bool isPrime( int n )
{
    if( n == 2 || n == 3 )
        return true;

    if( n == 1 || n % 2 == 0 )
        return false;

    for( int i = 3; i * i <= n; i += 2 )
        if( n % i == 0 )
            return false;

    return true;
}

/**
 * Internal method to return a prime number at least as large as n.
 * Assumes n > 0.
 */
int nextPrime( int n )
{
    if( n % 2 == 0 )
        ++n;

    for( ; !isPrime( n ); n += 2 )
        ;

    return n;
}

template <typename KeyType, typename ValType>
class BiMap
{
  public:
    explicit BiMap( int size = 11 ) : array( nextPrime( size ) )
      { makeEmpty( ); }

    int getSize() const
    {
        return currentSize;
    }

    bool containsKey( const KeyType & key ) const
    {
        return isActive( findPos( key ) );
    }

    bool containsVal( const ValType & val ) const
    {
        return isActive( findPosByVal( val ) );
    }
    
    void makeEmpty( )
    {
        currentSize = 0;
        for( auto & entry : array )
            entry.info = EMPTY;
    }

    bool insert( const KeyType & key , const ValType & val)
    {
        if (containsKey(key) || containsVal(val))
        return false;

            // Insert key as active
        int currentPos = findPos( key );
        if( isActive( currentPos ) )
            return false;

        if( array[ currentPos ].info != DELETED )
            ++currentSize;

        array[ currentPos ].first = key;
        array[ currentPos ].second = val;
        array[ currentPos ].info = ACTIVE;

            // Rehash; see Section 5.5
        if( currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }
    
    bool insert( KeyType && key , ValType && val)
    {
            // Insert key as active
        int currentPos = findPos( key );
        if( isActive( currentPos ) )
            return false;

        if( array[ currentPos ].info != DELETED )
            ++currentSize;

        array[currentPos] = { std::move(key), std::move(val), ACTIVE };
        array[ currentPos ].info = ACTIVE;

            // Rehash; see Section 5.5
        if( currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }

    bool removeKey( const KeyType & key )
    {
        int currentPos = findPos( key );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }

    bool removeVal( const ValType & val )
    {
        int currentPos = findPosByVal( val );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }

    const ValType & getVal( const KeyType & key ) const 
    {
        int currentPos = findPos(key);
        if (!isActive(currentPos)) 
            throw std::runtime_error("Key not found");

        return array[currentPos].second;
    }

    const KeyType & getKey( const ValType & val ) const
    {
        int currentPos = findPosByVal(val);
        if (!isActive(currentPos)) 
            throw std::runtime_error("Value not found");

        return array[currentPos].first;
    }

    // display active key-value entries/pairs
    void display() const 
    {
        for (const auto& entry : array) 
        {
            if (entry.info == ACTIVE)
                cout << entry.first << " -> " << entry.second << endl;
        }
    }

    // display entire array structure
    void ddisplay() const 
    {
        for (size_t i = 0; i < array.size(); ++i) 
        {
            cout << "[" << i << "] ";
            if (array[i].info == EMPTY)
                cout << "EMPTY";
            else if (array[i].info == DELETED)
                cout << "DELETED";
            else
                cout << array[i].first << " -> " << array[i].second;
            cout << endl;
        }
    }


    enum EntryType { ACTIVE, EMPTY, DELETED };

  private:
    struct HashEntry
    {
        KeyType first;
        ValType second;
        EntryType info;

        HashEntry( const KeyType & key = KeyType{ }, const ValType& val = ValType{}, EntryType i = EMPTY )
          : first{ key }, second{val}, info{ i } { }
        
        HashEntry( KeyType && key, ValType && val, EntryType i = EMPTY )
          : first{ std::move( key ) }, second{ std::move(val) }, info{ i } { }
    };
    
    vector<HashEntry> array;
    int currentSize;

    bool isActive( int currentPos ) const
    { 
        return array[ currentPos ].info == ACTIVE;
    }

    int findPos( const KeyType & key ) const
    {
        int offset = 1;
        int currentPos = myhash( key );

        while( array[ currentPos ].info != EMPTY &&
               array[ currentPos ].first != key )
        {
            currentPos += offset;  // Compute ith probe
            offset += 2;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    int findPosByVal(const ValType& value) const 
    {
        for (int i = 0; i < array.size(); ++i) {
            if (array[i].info == ACTIVE && array[i].second == value)
                return i;
        }
        return -1;
    }

    void rehash( )
    {
        vector<HashEntry> oldArray = array;

            // Create new double-sized, empty table
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for( auto & entry : array )
            entry.info = EMPTY;

            // Copy table over
        currentSize = 0;
        for( auto & entry : oldArray )
            if( entry.info == ACTIVE )
                insert(std::move(entry.first), std::move(entry.second));
    }

    size_t myhash( const KeyType & key ) const
    {
        static hash<KeyType> hf;
        return hf( key ) % array.size( );
    }
    
};

#endif
