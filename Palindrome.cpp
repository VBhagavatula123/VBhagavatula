#include <iostream>
#include <cstring>

using namespace std;

int main()
{

  char inputString[81];// acount for null terminating
  char array1[81]; //original input and add 1 to account for null terminating
  char array2[81]; //the one that is going to be the reverse so we can start comparing later, account for null terminating
  char goodChars[37] = {'a','b','c','d','e', 'f','g', 'h', 'i','j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'}; // the only characters that can be used, account for null terminating

  cout << "please enter an input of up to 80 characters, putting in more than 80 characters will either not work or will give you an inaccurate result" << endl;
  cout << endl;
  cin.get(inputString, 81); //getting the users input
  cin.get();


  int counter = 0; // int using for nested loop

  for (int i = 0; i <= strlen(inputString); i++) {//changing all caps to lower-case

             if (inputString[i] == 'A') {
        inputString[i] = 'a';

      }
             if (inputString[i] == 'B') {
        inputString[i] = 'b';

      }

             if (inputString[i] == 'C') {
        inputString[i] = 'c';

      }
              if (inputString[i] == 'D') {
        inputString[i] = 'd';

      }
             if (inputString[i] == 'E') {
        inputString[i] = 'e';

      }

             if (inputString[i] == 'F') {
        inputString[i] = 'f';

      }

              if (inputString[i] == 'G') {
        inputString[i] = 'g';

      }
             if (inputString[i] == 'H') {
        inputString[i] = 'h';

      }

             if (inputString[i] == 'I') {
        inputString[i] = 'i';

      }
              if (inputString[i] == 'J') {
        inputString[i] = 'j';

      }
             if (inputString[i] == 'K') {
        inputString[i] = 'k';

      }

             if (inputString[i] == 'L') {
        inputString[i] = 'l';

      }

              if (inputString[i] == 'M') {
        inputString[i] = 'm';

      }
             if (inputString[i] == 'N') {
        inputString[i] = 'n';

      }

             if (inputString[i] == 'O') {
        inputString[i] = 'o';

      }
              if (inputString[i] == 'P') {
        inputString[i] = 'p';

      }
             if (inputString[i] == 'Q') {
        inputString[i] = 'q';

      }

             if (inputString[i] == 'R') {
        inputString[i] = 'r';

      }
               if (inputString[i] == 'S') {
        inputString[i] = 's';

      }

             if (inputString[i] == 'T') {
        inputString[i] = 't';

      }

              if (inputString[i] == 'U') {
        inputString[i] = 'u';

      }
             if (inputString[i] == 'V') {
        inputString[i] = 'v';

      }

             if (inputString[i] == 'W') {
        inputString[i] = 'w';

      }
              if (inputString[i] == 'X') {
        inputString[i] = 'x';

      }
             if (inputString[i] == 'Y') {
        inputString[i] = 'y';

      }

             if (inputString[i] == 'Z') {
        inputString[i] = 'z';

      }



             for (int j = 0; j <= strlen(goodChars); j++) {//for each char of input string check if it is equal to a char from the goodChar string to move forward



               if(inputString[i] == goodChars[j]){// if it is equal to the good chars then it is good to go
                

                 array1[counter] = goodChars[j];// since it is, you now put that into array1

                 counter++;//add 1 to the counter variable so it is current

               

          }
      }
    }




  cout << endl;


  int count = 0;
  for (int i = 0; i < strlen(array1); i++) { // all building our 2nd array that will be the reverse of our user's input

    array2[count] = array1[strlen(array1)-i-1];// -1 accounts for null terminating
    count++;


  }

  //console comments and method explanations.

  cout << "array one is: " << array1 << endl;
  cout << "array two is: " << array2 << endl;

  cout << endl;

  cout << "we will now compare array2 whichis the reverse of array1 which was coppied from the userInput array to see if your original input was a palindrome" << endl;

  cout << endl;
  int count1 = 0; // counter variable

  for (int i = 0; i < strlen(array1); i++) {


    if(array2[count1] != array1[i]) {// -1 to account for the null character

      cout << "not a palindrome" << endl;// if it doesn't equal write not a palindrome
      break;// if it doesn't equal once, just break the loop it isn't going to be a palindrome anyway.
    }

    count1++;// each time it does equal increase the count by one

  }

  if (count1 == strlen(array1)) {// if the count number at the end was equal to the array length, which was how many times the for loop ran, it's a palindrome
    cout << "is a palindrome" << endl;

  }



  return 0;

}


