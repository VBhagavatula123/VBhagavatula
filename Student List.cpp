#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void getStudentInfo(char a[20], char b[20]);

struct student{

  char display[8];
  char first[20];
  char lastName[20];
  int studentID = 0;
  float GPA = 0;

};


int main()
{

  vector<student*> v;
  student s;
  cout << "what is the first and last name of this student" << endl;
  getStudentInfo(s.first, s.lastName);

}

void getStudentInfo(char a[20], char b[20]) {
  cin >> a;
  cin >> b;
  cout << a << " " << b;
}


void add (vector<student*> &in) {
  student* s = new student();
  in.push_back(s),
    s-> first;
}

void displayList(vector<student*> &in) {
  cout << "display the list if you want to display the list, type display" << endl;
  cin >> s.display;
  if (s.display == "DISPLAY") {

    cout << student << endl;

  }
}








