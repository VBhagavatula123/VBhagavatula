File Edit Options Buffers Tools C++ Help


  int counter = 0; // int using for nested loop

  for (int i = 0; i < strlen(inputString); i++) {//changing all caps to lower-case

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



             for (int j = 0; j < strlen(goodChars); j++) {//for each char of input string check if it is equal to a char from the goodChar string to move forward



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

    count1++;// each time it doesn't equal increase the count by one

  }

  if (count1 == strlen(array1)) {// if the count number at the end was equal to the array length, which was how many times the for loop ran, it's a palindrome
    cout << "is a palindrome" << endl;

  }



  return 0;

}
