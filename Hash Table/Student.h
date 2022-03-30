#pragma once
#include <iostream>
#include <cstring>

//This file has allthe members for a student, all are made public to use in the node class.

using namespace std;

class Student
{
public:
  Student* next; 
  char s_firstName[30];
  char s_lastName[30];
  int s_id;
  float s_GPA;
  void getStudentInfo ();
    Student (char *first, char *last, int ID, float GPA);
   ~Student ();
};
