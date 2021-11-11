#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

//Declare struct
struct Student {
  char firstName[20];
  char lastName[20];
  int id;
  float GPA;
};

//Prototype the three functions
void ADD(vector<Student*> &studentVector);
void PRINT(vector<Student*> &studentVector);
void DELETE(vector<Student*> &studentVector);

int main() {
   
  vector<Student*> studentVectorPtr;
     
  char inputString[7];
 
  while(true)
  {
      //Prompt for input from user, ADD, PRINT, DELETE or QUIT
      cout << "What would you like to do?" << endl;
      cin >> inputString;
     
      //Based on what the input is, call different functions
      //passing vector pointer to vector of student struct pointers
      if (strcmp(inputString, "ADD") == 0)
            ADD(studentVectorPtr);
      else if (strcmp(inputString, "PRINT") == 0)
            PRINT(studentVectorPtr);
      else if (strcmp(inputString, "DELETE") == 0)
            DELETE(studentVectorPtr);
      else if(strcmp(inputString, "QUIT") == 0)
            break;
   };
 
   return 0;
}



void ADD(vector<Student*> &studVect) {
   
    //newStudent is a struct pointer
    Student* newStudent = new Student();
   
    //Prompt user for student firstname, lastname, id and gpa
    cout << "Type student info: firstName lastName studentId GPA" << endl;
   
    cin >> newStudent->firstName;
    cin >> newStudent->lastName;
    cin >> newStudent->id;
    cin >> newStudent->GPA;

    //Add the newStudent struct pointer to our student vector, studVect
    studVect.push_back(newStudent);
}

void PRINT(vector<Student*> &studVect) {
   
    //Print all the students looping through all struct pointers of the student vector studVect
    cout << endl << "Below is the list of all students currently stored: " << endl;
   
    for(int i =0; i < studVect.size(); i++) {
        cout << studVect[i]->firstName << " ";
        cout << studVect[i]->lastName << ", ";
        cout << studVect[i]->id << ", ";
        //set formatting and precision for GPA to 2 decimal places before printing
        cout.setf(ios::fixed,ios::floatfield);
        cout.setf(ios::showpoint);
        cout.precision(2);
        cout << studVect[i]->GPA << endl;
    }
   
    cout << endl;
   
}

void DELETE(vector<Student*> &studVect) {
    int studentId;
    //Prompt for the student to delete
    cout << "Which student id to delete?" << endl;
    cin >> studentId;
   
    //Loop through each element of the student vector
    for(int i=0; i <studVect.size(); i++) {
        //If the student is student prompted to delete
        if(studVect[i]->id == studentId) {
            //Print student list before deletion
            PRINT(studVect);
           
            //delete the data
            delete studVect[i];
           
            //Remove the student from vector
            studVect.erase(studVect.begin()+i);
           
            //Confirm deletion
            cout << "Student " << studentId << " is now deleted. " << endl;
            //Print student list after deletion
            PRINT(studVect);
           
            break;
        }
    }
   
    //Looping using iterator
    /*for (vector<Student*>::iterator pObj = studVect.begin(); pObj != studVect.end(); ++pObj) {
        if((*pObj)->id == studentId) {
           
            delete *pObj; // this is deleting what pObj points to which is a struct pointer
            studVect.erase(pObj);
            cout << "Student " << studentId << " is now deleted. " << endl;
            PRINT(studVect);
            break;
        }
   }*/
}
