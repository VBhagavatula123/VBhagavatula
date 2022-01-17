//all of these functions are the functions that are needed for the main function, therefore, every function will be declared public
// private members are members that we are using for our functions over in Node.cpp.
//for the Node constructor we need to pass a pointer to the new instantiation of a student class, which just copies the input strings from main and stores them
// for the next functions setNext sets(as in establishes) the next node, where as getNext gets the next node it as in(grabs for use) by just reurning next which is of type Node*
//pragma once is a line of code to clean up complilation errors.
//getStudent is to return the specific student info of type Student*, which was instantiatied in Node()

#pragma once
#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;


class Node {
    public:
    Node();
    ~Node(); 
    void setNext(Node*);
    Node(Student*);
    Node* getNext();
    Student* getStudent();
    
    
    private:
    Node* next;
    Student* stdinfo;
};
