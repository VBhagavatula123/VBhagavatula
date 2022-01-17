#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(char* first, char* last, int ID, float GPA){
  strcpy(s_firstName, first);
  strcpy(s_lastName, last);
  s_id = ID;
  s_GPA = GPA;
}


Student::~Student() {
    
}
