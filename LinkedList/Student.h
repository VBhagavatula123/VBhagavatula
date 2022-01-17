//going to be used to copy in the data inputed from main and then eventually a pointer to an instantiation of it will passed into a Node contructor to add the info to each node.
#pragma once
#include <iostream>
#include <cstring>


using namespace std;

class Student {
    public:
    
    char s_firstName[10];
    char s_lastName[10];
    int s_id;
    float s_GPA;
    void getStudentInfo();
    Student(char* first,char* last, int ID, float GPA);
    ~Student(); 
};

