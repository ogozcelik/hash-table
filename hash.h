#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <iostream>
#include <list>

using namespace std;

//HASH IMPLEMENTATION WITH SEP. CHAINING USING LIST

class Hash{
    int bucket; //number of buckets
    list<long long int> *table; //
public:
    Hash (int bucketSize); // constructor
    void insertKey(long long int key, string hashfunc);
    void deleteKey(long long int key, string hashfunc);
    bool searchKey(long long int key, string hashfunc);
    void displayHash();

    //hash functions below
    int Folding(long long int key);
    int MiddleSquaring(long long int key);
    int Truncation(long long int key);
};

#endif // HASH_H_INCLUDED
