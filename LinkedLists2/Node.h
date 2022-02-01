//header file for node
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node
{
 public:
  //define functions
  Node(); // default constructor
  Node(Student* newStudent); // constructor, set student pointer to new student
  Node* getNext(); //get next Node pointer
  Student* getStudent(); // get Student pointer
  void setNext(Node* newNode); // set next pointer to corresponding node pointer
  ~Node(); // destructor

 private:
  //variables
  Node* next;
  Student* student;
  
};

#endif
