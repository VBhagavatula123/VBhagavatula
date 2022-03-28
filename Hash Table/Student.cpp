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

Student** Student::getTable() {
    int size = 100;
    Student* table[size];
    for(int i = 0; i < size; i++) {
        table[i] = NULL;
    }
    return table;
}
