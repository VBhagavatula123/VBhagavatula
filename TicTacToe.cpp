
#include <iostream>
#include <cstring>

using namespace std;

//void chartMethod(char a[0],char a[1]);

void printBoard(int arrParam[][3]);
void printX(char arr[], int arrParam[][3]);

struct board{

  int board1[3][3];
  char inputStringX[1];
  char inputStringO[1];

};

int main()
{
  board turn1;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      turn1.board1[i][j] = 0;
    }
  }
  printBoard(turn1.board1);

  cout << "please enter your X by choosing a number between 1 and 9" << endl;
  cin >> turn1.inputStringX;

  printX(turn1.inputStringX, turn1.board1);









  return 0;
}

void printBoard(int arrParam[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if(arrParam[i][j] == 0) {
        cout << "*";
      }
      if(arrParam[i][j] == 1) {
        cout << "X";
      }
      if(arrParam[i][j] == 2) {
        cout << "O";
      }

    }
    cout << endl;
  }
}

void printX(char arr[], int arrParam[][3]) {
    if(arr[0] == 1 && arrParam[0][0] == 0) {
    arrParam[0][0] = 1;
  }
    if(arr[0] == 1 && arrParam[0][1] == 0) {
    arrParam[0][1] = 1;
  }
    if(arr[0] == 1 && arrParam[0][2] == 0) {
    arrParam[0][2] = 1;
  }
    if(arr[0] == 1 && arrParam[1][0] == 0) {
    arrParam[1][0] = 1;
  }
    if(arr[0] == 1 && arrParam[1][1] == 0) {
    arrParam[1][1] = 1;
  }
    if(arr[0] == 1 && arrParam[1][2] == 0) {
    arrParam[1][2] = 1;
  }
    if(arr[0] == 1 && arrParam[2][0] == 0) {
    arrParam[2][0] = 1;
  }
    if(arr[0] == 1 && arrParam[2][1] == 0) {
    arrParam[2][1] = 1;
  }
    if(arr[0] == 1 && arrParam[2][2] == 0) {
    arrParam[2][2] = 1;
  }

    printBoard(arrParam[][3]);

}

void conversion(int arrParam[][3]) {



}
