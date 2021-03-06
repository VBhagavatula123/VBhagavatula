//cpp file for node
#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

Node::Node() {}

Node::Node(Student* newStudent)
{
  student = newStudent;
  next = NULL;
}

Node* Node::getNext()
{
  return next;
}

Student* Node::getStudent()
{
  return student;
}
void Node::setNext(Node* newNode)
{
  next = newNode;
}
Node::~Node()
{
  delete student;
  next = NULL;
}
