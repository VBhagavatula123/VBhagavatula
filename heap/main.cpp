
#include <cstring>
#include <iostream>
#include <fstream>
#include <time.h>
#include <bits/stdc++.h>
#include <math.h>

//heap by Vivek Bhagavatula
//can print out a max heap using user input or randomly
//can delete but just a resorting method due to me running out of time.
//4/6/22

using namespace std;

struct Node {
    int val;
    Node* next;
};
//my original sorting algorithm that doesn't work unfortuanely.

/*void Heapsort(int *a, int input) {
    int a2[input];
    int index2[input];
    for(int i = 0; i < input; i++) {
        index2[i] = -1;
    }
    for(int i = 0; i < input; i++) {
        
        int max = 0;
        int index = 0;
        for(int j = 0; j < input; j++) {
            if(a[j] > max) {
                bool check = true;
                for(int i = 0; i < input; i++) {
                    if(j == index2[i]) {
                      check = false;
                    }
                }
                if(check == true) {
                   max = a[j];
                   index = j; 
                }
            }
        }
        
        index2[i] = index;
        a2[i] = max;
    }
    a = a2;
    for(int i = 0; i < input; i++) {
        if(a[i] != NULL) {
            cout << a[i] <<  " ";
        }
    }
    cout << endl;
}*/

void push(Node * &head, int inputValue) {
Node* insert = new Node();
insert->val = inputValue;
if(head == NULL) {
  head = insert;
}

else if(head != NULL) {
    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = insert;
    insert->next = NULL;
 }
}

void print(Node * head) {
  while (head != NULL) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}



//Geeks for geeks 
void heapify(int* arr, int position, int root)
{
    int largest = root; // set the largest to the root
    int left = 2 * root + 1; //get right and left children
    int right = 2 * root + 2; //get the left child
   // get the largest child
    if (left < position && arr[left] > arr[largest])
        largest = left;
   
    if (right < position && arr[right] > arr[largest])
        largest = right;
    //make sure the root is the largest so swap.
    if (largest != root) {
        swap(arr[root], arr[largest]);
        heapify(arr, position, largest);
    }
}

//geeks for geeks
void sort(int *arr, int root)
{
    for (int position = root/2 - 1; position >= 0; position--)
        heapify(arr, root, position);
        //build the heap
    for (int position = root - 1; position > 0; position--) {
        //take elements and put em at the top and move them down one by one using heapify
        heapify(arr, position, 0);
    }
}

void print(int *heap, int root, int space) {
    
    int right = root*2+1; // get right and left chilren
    int left = root*2+2;
    
    if(heap[root] == -1){
    return;
  }
  
  space+=5; // add 5 more space everytime you run the function

  print(heap, right, space);// run the function

  cout << "\n" <<endl;
  for(int i = 5; i < space; i++){
    cout << " ";
  }
  cout << heap[root] << "\n";
  
  print(heap, left, space);// after printing call the function
}

void randomAdd(int* heap, int &length, int size) {
    ifstream numbers;
    numbers.open("RandomNum.txt");
       int a = rand()%14 +1;// get a random number from the file
       int temp;// get a temp place holder to loop
       int counter = 0;
       while(numbers >> temp && counter < 14) {
           if(counter == a) {
               heap[length+1] = temp;// once you reach the random number set heap of a certain length equal to temp (it doesn't matter where it is added after heap sort is called)
               cout << "you added" << temp << endl;
               break;
           }
           counter++;
           
       }
       length++;
       sort(heap, size);// resort for good measure
       numbers.close();
       
       print(heap, 0,0);
       
}

void manualAdd(int* heap, int &length, int size) {
    cin.get();
    int input;
    
    cout << "add a number from 1 to 1000" << endl; // the the user choice
    cin >> input;
    if(input > 1000 || input < 1) {
        cout << "follow directions nextime" << endl;
        return;
    }
    if(length == 0) {
        heap[0] = input;
    }
    for(int i = 0; i < length; i++) {
        if(i = length) {
            heap[i] = input; //set i = to the choice of the user
        }
    }
    length++;
    sort(heap, size);
    print(heap, 0, 0);
}

int deletenum(int* heap, int length, int size, int &count, Node* output) {
    int choice;
    cout << "enter a number to delete won't work if there is multiple of a number." << endl; // enter a choice to delete
    cin >> choice;
    for(int i = 0; i < length; i++) {
        if(heap[i] == choice) {
            heap[i] = -1; // set the choice to 0 or NULL;
        }
    }
    length--;
    sort(heap, size);
    print(heap, 0, 0);
    
    return choice;
}


//display code but it doesn't work 

/*void displayHeap(int* heap, int length) {
    int Length = length+1;
    double LOG_LENGTH = log2(length);
    bool isInteger;
    int result = LOG_LENGTH/1;
    int rows = 0;
    if(result*1 == LOG_LENGTH) {
        isInteger = true;
    } else {
        isInteger = false;
    }
    if(isInteger == true) {
        rows = LOG_LENGTH +1;
    } else {
        rows = ceil(LOG_LENGTH);
    }
    int previous = 0;
    for(int k = 0; k < rows; k++) {
        int rowamount = pow(2, k+1) - pow(2, k);
        for(int i = previous; i < rowamount; i++) {
        	if(heap[i] != -1) {
        	  cout << heap[i] << '\t';
        	}
        	else {
        	  cout << '\t';
        	}
        	previous = i+1;
        }
        cout << endl;
    }
}*/

//geeks for geeks 


int main()
{
    Node* output = NULL;
    srand(time(NULL));// set a random seed
    int size = 100; //set the size
    int* heap = new int[size];
    int length = 0; // set the length
    for(int i = 0; i < 100; i++) {
        heap[i] = -1;// make everything NULL or -1 which is NULL
    }
    while(true) {// commands for different inputs
       cout << "enter delete to delete, add to add, print to print and quit to quit" << endl; 
       char inputString[20];
       cin.get(inputString, 20);
       if(strcmp(inputString, "add") == 0) {
       char choice;
       cout << "M for manuel and R for Random" << endl;
       cin >> choice;
       if(choice == 'M') {// manuel
           manualAdd(heap, length, size);
           cin.get();
       } 
           else if(choice == 'R') {// random
               randomAdd(heap, length, size);
               cin.get();
           }
       }
       if(strcmp(inputString, "print") == 0) {// print command
           cin.get();
           print(heap, 0, 0);
       }
       if(strcmp(inputString, "quit") == 0) {// quit function
           exit(0);
       }
       if(strcmp(inputString, "delete") == 0) {// delete commands
           cin.get();
           int count = 0;
           push(output, deletenum(heap, length, size, count, output));
           cout << "OUTPUT: ";
           print(output);
           cin.get();
       }
       if(strcmp(inputString, "PRINT") == 0) {// test print command to print out the heap in array notaiton.
           cin.get();
           for(int i = 0; i < length; i++) {
               cout << heap[i] << " ";
           }
       }
    }
   
   
    
}
