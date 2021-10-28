#include <iostream>
#include <cstring>

using namespace std;



void printBoard(int** arrParam);
void printX(char* arr, int** arrParam);
void printO(char* arr, int** arrParam);
bool checkWinO(int** arrParam);
bool checkWinO(int** arrParam);
bool checkTie(int** arrParam);

struct board{ // struct containing board and input strings

  int board1[3][3];
  char inputStringX[1];
  char inputStringO[1];

};

int main()
{

  int xWincounter = 0;// win counters
  int oWincounter = 0;

  board game1;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      game1.board1[i][j] = 0; //set everything in the board to 0
    }
  }
  printBoard(game1.board1);



  while (checkWinX && checkWinO && checkTie != true) {
    cout << "please enter your X by choosing a number between 1 and 9" << endl; // ask for inputs for X and O until checkWin = truw for x or O
  cin >> game1.inputStringX;

  printX(game1.inputStringX, game1.board1);

  checkWinX(game1.board);
  checkwinO(game1.board);
  checkTie(game1.board);

  cout << "please enter your O by choosing a number between 1 and 9" << endl;
  cin >> game1.inputStringO;

  printO(game1.inputStringO, game1.board1);

   checkWinX(game1.board);
  checkwinO(game1.board);
  checkTie(game1.board);


  }

  if(checkWinX == true) {// if they equal true reset the board and add to the counter
    xWincounter++;
    cout << xWincounter << endl;
    nextGame = new board();
  }
  if(checkWinO == true) {
    oWincounter++;
    cout << oWincounter << endl;
    nextGame = new board();
  }




  return 0;
}

void printBoard(int** arrParam) {// function for printing board
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

void printX(char* arr, int** arrParam) {//function for printing X
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

    printBoard(int** arrParam);

}

void printO(char* arr, int** arrParam) {//function for printing O
  if(arr[0] == 1 && arrParam[0][0] == 0) {
    arrParam[0][0] = 2;
  }
    if(arr[0] == 1 && arrParam[0][1] == 0) {
    arrParam[0][1] = 2;
  }
    if(arr[0] == 1 && arrParam[0][2] == 0) {
    arrParam[0][2] = 2;
  }
    if(arr[0] == 1 && arrParam[1][0] == 0) {
    arrParam[1][0] = 2;
  }
    if(arr[0] == 1 && arrParam[1][1] == 0) {
    arrParam[1][1] = 2;
  }
    if(arr[0] == 1 && arrParam[1][2] == 0) {
    arrParam[1][2] = 2;
  }
    if(arr[0] == 1 && arrParam[2][0] == 0) {
    arrParam[2][0] = 2;
  }
    if(arr[0] == 1 && arrParam[2][1] == 0) {
    arrParam[2][1] = 2;
  }
    if(arr[0] == 1 && arrParam[2][2] == 0) {
    arrParam[2][2] = 2;
  }

    printBoard(int** arrParam);



}

bool checkWinX(int** arrParam) {// checks win for X

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (arrParam[0][0] == 1 && arrParam[0][1] == 1 && arrParam[0][2] == ) {
        return true;
      }
       if (arrParam[1][0] == 1 && arrParam[1][1] == 1 && arrParam[1][2] == 1) {
        return true;
      }
        if (arrParam[2][0] == 1 && arrParam[2][1] == 1 && arrParam[2][2] == 1) {
        return true;
      }
        if (arrParam[0][0] == 1 && arrParam[1][0] == 1 && arrParam[2][0] == 1) {
        return true;
      }
        if (arrParam[0][1] == 1 && arrParam[1][1] == 1 && arrParam[2][1] == 1) {
        return true;
      }
        if (arrParam[0][2] == 1 && arrParam[1][2] == 1 && arrParam[2][2] == 1) {
        return true;
      }
        if (arrParam[0][0] == 1 && arrParam[1][1] == 1 && arrParam[2][2] == 1) {
        return true;
      }
        if (arrParam[0][2] == 1 && arrParam[1][1] == 1 && arrParam[2][0] == 1) {
        return true;
      }

    }
  }

}

bool checkWinO(int** arrParam) {//Checks win for O

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (arrParam[0][0] == 2 && arrParam[0][1] == 2 && arrParam[0][2] == 2) {
        return true;
      }
       if (arrParam[1][0] == 2 && arrParam[1][1] == 2 && arrParam[1][2] == 2) {
        return true;
      }
        if (arrParam[2][0] == 2 && arrParam[2][1] == 2 && arrParam[2][2] == 2) {
        return true;
      }
        if (arrParam[0][0] == 2 && arrParam[1][0] == 2 && arrParam[2][0] == 2) {
        return true;
      }
        if (arrParam[0][1] == 2 && arrParam[1][1] == 2 && arrParam[2][1] == 2) {
        return true;
      }
        if (arrParam[0][2] == 2 && arrParam[1][2] == 2 && arrParam[2][2] == 2) {
        return true;
      }
        if (arrParam[0][0] == 2 && arrParam[1][1] == 2 && arrParam[2][2] == 2) {
        return true;
      }
        if (arrParam[0][2] == 2 && arrParam[1][1] == 2 && arrParam[2][0] == 2) {
        return true;
      }

    }
  }



}

bool checkTie(int** arrParam) {//Checks for tie

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (arrParam[0][0] != 0 && arrParam[0][1] != 0 && arrParam[0][2] != 0 && arrParam[0][0] != 0 && arrParam[0][0] != 0 && arrParam[0][0] != 0 && arrParam[0][0] != 0 && arrParam[0][0] != 0 && arrParam[0][0] != 0){
        return true;
      }
    }
  }


}



