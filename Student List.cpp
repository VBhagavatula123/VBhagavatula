
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct StudentInfo {
  char firstName[20];
  char lastName[20];
  int id;
  float GPA;
};

vector<StudentInfo> studentList;


void ADD();
void PRINT();
void DELETE();

int main() {
      
      
  char inputString[7];
  
  do
  {
      cout << "What would you like to do?" << endl;
      cin >> inputString;
      if (strcmp(inputString, "ADD") == 0)
        ADD();
      else if (strcmp(inputString, "PRINT") == 0)
        PRINT();
      else if (strcmp(inputString, "DELETE") == 0)
        DELETE();
      else
        break;
   } while(strcmp(inputString, "QUIT") != 0);
  
   return 0;
}

void ADD() {
    
    StudentInfo newStudent;
    cout << "Type student info:  firstName lastName studentId GPA" << endl;
    cin >> newStudent.firstName;
    cin >> newStudent.lastName;
    cin >> newStudent.id;
    cin >> newStudent.GPA;
    
    studentList.push_back(newStudent);
    
}

void DELETE() {
    int studentId;
    cout << "what is your id to delte the student?" << endl;
    cin >> studentId;
    for(int i=0; i <studentList.size(); i++) {
        if(studentList[i].id == studentId) {
            studentList.erase(studentList.begin()+i-1);
        }
    }
}

void PRINT() {
    
    for(int i =0; i < studentList.size(); i++) {
        cout << studentList[i].firstName << " ";
        cout << studentList[i].lastName << " ";
        cout << studentList[i].id << " ";
        cout.setf(ios::fixed,ios::floatfield);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << studentList[i].GPA << endl; 
    }
    
}

