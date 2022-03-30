// Hash table by vivek bhagavatula
// stores random students into a hash table and rehashes them if there is 3 collisions, uses chaining
// 3/30/22


#include <iostream>
#include "Student.h"
#include <cstring>
#include <fstream>
#include <time.h>

using namespace std;


void  rehash(Student** &a, int &size);
bool checkCOL(Student** a, int size);
int HASH(Student* j, int size);
void ADD(Student** &a, int size, int studentID, int input);
void PRINT(int a, Student** b, int size);
void print2(Student** b, int size);
Student* NAMEGEN(int &studentID);


int HASH(Student* j, int size) {// rehashing function that takes the id modulo the table size.
    int o = j->s_id % size;
    return o;
}

void ADD(Student** &a, int size, int &studentID) {// add function
    
    
    Student* g = NAMEGEN(studentID);// make a node with a random student.
    

      
  Student* current = a[HASH(g,size)];// get the head node of the index
  Student* newstud = new Student(g->s_firstName,g->s_lastName,g->s_id, g->s_GPA);// make a new student with random nifo
  newstud->next = NULL;// make sure it's next pointer is NULL
  
  if(current == NULL) {// if the index is empty add
    a[HASH(g,size)] = newstud;
  }
  
  else {// otherwise append to the front.
    newstud->next = a[HASH(g,size)];
    a[HASH(newstud,size)] = newstud;
  }
 
  
}

void ADD2(Student** &a, Student* g, int size) {// second add function that takes a Student* as a parameter instead of randomizing. Specifially for rehashing.
  
  Student* current = a[HASH(g,size)];
  Student* newstud = new Student(g->s_firstName,g->s_lastName,g->s_id, g->s_GPA);
  newstud->next = NULL;
  
  if(current == NULL) {
    a[HASH(newstud,size)] = newstud;
  }
  
  else {
    newstud->next = a[HASH(g,size)];
    a[HASH(newstud,size)] = newstud;
  }
    
}


void DELETE(Student** &a, int size) {// delete a student at a particular index
    cout << "select an id to delete" << endl;
    int input;
    cin >> input; // get the index
    if(a[input%size]->s_id == input) {// if it is the first one of the two
         if(a[input%size]->next != NULL) {// if there is a second one
             Student* c = a[input%size];
             a[input%size] = c->next;
             delete c;
         }
         else {// if there isn't
             a[input%size] = NULL;
         }
    }
    else if(a[input%size]->next->s_id == input) {// if it is the second one.
        a[input%size]->next = NULL;
    }
    
}


void print2(Student** b, int size) {// printing function
    for(int i = 0; i < size; i++) {
        Student* current = b[i];
        cout << i+1 << ":   ";
        while(current != NULL) {
            cout << current->s_firstName << " " << current->s_lastName << " " << current->s_id << " " << current-> s_GPA << "      ";
            current = current -> next;
        }
        cout << endl;
    }
}

void  rehash(Student** &a, int &size) {// rehashing function
    size*=2;// double the size
    Student** newtable;
    newtable = new Student*[size];// make the new table
    for(int i = 0; i < size; i++) {// set everything to empty
        newtable[i] = NULL;
    }
    
    for(int i = 0; i < size/2; i++) {// loop over every student in the original table and add it to the second one.
        Student* current = a[i];
        while(current != NULL){
        
        ADD2(newtable, current, size);
        current = current->next;
      }
    }
    a = newtable; //make the original table = the new one
    print2(a, size);
    
 }
 
 Student* NAMEGEN(int &studentID) {// generate a random student
    	  ifstream first("FirstNames.txt");
    	  ifstream last("LastNames.txt");  
          
    	  
    	      int firstpos = rand()%100  +1; //random line for the firstnames 
    	      int lastpos = rand()%100  +1;  // random line for the lastnames
    	      char firstName[20];
    	      char lastName[20];
    	      char FIRST[20];
    	      char LAST[20];
              double gpa = (double)(rand()%99)/100;// get a decimal with 2 digits between 0 and 100
              gpa += rand() % 5;// add 4 to it
    	      int counter = 1;
    	      while(first >> firstName && counter < 101) {
    	          if(counter == firstpos) {
    	              strcpy(FIRST, firstName);
    	              break;
    	          }
    	          counter++;
    	      }
    	      int counter2 = 1;
    	      while(last >> lastName && counter2 < 101) {
    	          if(counter2 == lastpos) {
    	              strcpy(LAST, lastName);
    	              break;
    	          }
    	          counter2++;
    	      }
    	      
    	      cout << FIRST << " " << LAST << " " << gpa << " " << studentID << endl;
    	     
    	      
    	      
    	      Student* newstud = new Student(FIRST, LAST, studentID, gpa); // make a new student with the info
    	      
    	      
    	      //make sure you properly reset the files for use in the next loop.
    	      first.close();
        	  first.open("FirstNames.txt");
        	  last.close();
        	  last.open("LastNames.txt");
        	  //increment the id so it isn't the same.
    	      studentID++;
    	  
        	  return newstud;
 }
 
 
 
 bool checkCOL(Student** a, int size) {// loop through the table and check if there needs to be rehashing.
     for(int i = 0; i < size; i++) {
         int counter = 0;
         Student* curr = a[i];
         while(curr != NULL) {
             counter++;
             curr= curr->next;
         }
         if(counter >= 3) {// if there is 3 in a chain, rehash
             cout << "rehashing" << endl;
             return true;
         }
     }
     return false;//otherwise don't
 }


// main method consists of the user input logic. It manages the rest of the program.
int main()
{
    int size = 100;
    Student** TABLE = new Student*[size];
    srand(time(NULL)); // set a random seed
    
   
    
    int id = 1; // id variable you pass into functions by reference.
    while(true) {
        
        
      
      
      char inputString[10];
      char first[30];
      char last[30];
      int ID;
      float GPA;

      cout << endl;
      cout << "Enter 'add' to add a random student, 'print' to print the table, 'quit' to quit after you have came back to this message." << endl;
      cout << "  'delete' to delete a student by ID" << endl;

      cin.get (inputString, 10);
      cin.get ();
          if (strcmp (inputString, "add") == 0)
    	  {// add command
    	     int input;
    	     cout << "how many students do you want to add?" << endl;
    	     cin >> input;
    	     while(input--) {
    	         ADD(TABLE, size, id);
    	           if(checkCOL(TABLE, size) == true) {// check for rehashing.
                 rehash(TABLE, size);
               }
    	     }
    	         print2(TABLE, size);
    	         cin.get();
    	  
    	  }
    	
    	if(strcmp (inputString, "print") == 0) {// print command
    	  print2(TABLE, size);
    	}
    	if(strcmp (inputString, "delete") == 0) {// delete command
    	    DELETE(TABLE, size);
    	    cin.get();
    	}
    	if(strcmp(inputString, "quit") == 0) {// quit command
    	    exit(0);
    	}
    	
      
    	
    	
    }
    return 0;
}
    
    
    
    

   
