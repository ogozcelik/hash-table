#include <string>
#include <cmath>
#include "hash.h"

Hash::Hash (int bucketSize){
    this->bucket = bucketSize;
    table = new list<long long int>[bucket];
}

void Hash::insertKey(long long int key, string hashfunc){
    int index=0; //0 is just for initialization
    if (hashfunc == "Folding"){
        index = Folding(key); //get the hash index
    }
    else if(hashfunc == "MiddleSquaring"){
        index = MiddleSquaring(key);
    }
    else if(hashfunc == "Truncation"){
        index = Truncation(key);
    }
    table[index].push_back(key); //push it to the list
}

void Hash::deleteKey(long long int key, string hashfunc){
    int index=0; //0 is just for initialization
    if (hashfunc == "Folding"){
        index = Folding(key); //get the hash index
    }
    else if(hashfunc == "MiddleSquaring"){
        index = MiddleSquaring(key); //get the hash index
    }
    else if(hashfunc == "Truncation"){
        index = Truncation(key); //get the hash index
    }

    list<long long int> :: iterator i; //to look at every element in a list one at a time
    for (i= table[index].begin(); i != table[index].end(); i++){
        if(*i == key)
            break;
    }
    if(i != table[index].end()){
        table[index].erase(i);
        cout<< "T.C. ID : "<<key<<" is deleted!" <<endl;
    }
    else{
    cout<<"Key is not valid, no removing occurs!"<<endl;
    }
}


bool Hash::searchKey(long long int key, string hashfunc){
    int index=0; //0 is just for initialization
    if (hashfunc == "Folding"){
        index = Folding(key); //get the hash index
    }
    else if(hashfunc == "MiddleSquaring"){
        index = MiddleSquaring(key); //get the hash index
    }
    else if(hashfunc == "Truncation"){
        index = Truncation(key); //get the hash index
    }

    list<long long int> :: iterator i; //to look at every element in a list one at a time
    for (i= table[index].begin(); i != table[index].end(); i++){
        if(*i == key)
            break;
    }
    if(i != table[index].end()){
        return true;
    }
    else{
        return false;
    }
}

void Hash::displayHash(){
    cout<<endl;
    cout<<"//////////////////////// HASH TABLE ////////////////////////"<<endl;
    for (int i=0; i< bucket; i++){
        cout<< i;
        for (auto x : table[i])
            cout<<" --> "<< x;
        cout<<endl;
    }
}

//HASH FUNCTIONS

int Hash::Folding(long long  int key) {
    int sec1 = key / pow(10,8);
    key = key - sec1*pow(10,8);
    int sec2 = key / pow(10,5);
    key = key - sec2*pow(10,5);
    int sec3 = key / pow(10,2);
    int sec4 = key - sec3*pow(10,2);
    int result = sec1+sec2+sec3+sec4;
    return (result % bucket);
}

int Hash::MiddleSquaring(long long  int key) {
    int sec1 = key / pow(10,7);
    key = key - sec1*pow(10,7);
    int middle = key / pow(10,4);
    int result = middle * middle;
    return (result % bucket);
}

int Hash::Truncation(long long  int key) {
    int sec1 = key / pow(10,2);
    key = key - sec1*pow(10,2);
    return (key % bucket);
}
