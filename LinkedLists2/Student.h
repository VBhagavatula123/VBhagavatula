#pragma once
#include <iostream>
#include <cstring>


using namespace std;

class Student
{
public:

  char s_firstName[10];
  char s_lastName[10];
  int s_id;
  float s_GPA;
  void getStudentInfo ();
    Student (char *first, char *last, int ID, float GPA);
   ~Student ();
};
