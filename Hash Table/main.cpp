#include <iostream>
#include "Student.h"
#include <cstring>
#include <fstream>

using namespace std;

int colCount = 0;


Student** setTable(int size) {
    Student** table;
    table = new Student*[size];
    for(int i = 0; i < size; i++) {
        table[i] = NULL;
    }
    return table;
}

int HASH(Student* j, int size) {
    int o = j->s_id % size;
    return o;
}

void ADD(Student* a[], Student* g, int size) {
  if(a[HASH(g ,size)] == NULL) {
      a[HASH(g, size)] = g;
  }
  else if(a[HASH(g, size)] != NULL) {
      colCount++;
      Student *head = a[HASH(g, size)];
      while(head->next != NULL) {
          head = head->next;
      }
      head->next = g;
      head->next->next = NULL;
  }
}


void DELETE() {
    
}

void PRINT(int a, Student** b, int size){
    Student* current = b[a % size];
    while(current != NULL) {
    cout << current->s_GPA << endl;
    current = current->next;
    }
    
    cout << endl;
    
    for(int i = 0; i < size; i++) {
        Student* current = b[i];
        cout << i << ":   ";
        while(current != NULL) {
            cout << current->s_GPA << " ";
            current = current -> next;
        }
        cout << endl;
    }
}

void print2(Student** b, int size) {
    for(int i = 0; i < size; i++) {
        Student* current = b[i];
        cout << i << ":   ";
        while(current != NULL) {
            cout << current->s_GPA << " ";
            current = current -> next;
        }
        cout << endl;
    }
}


void  rehash(Student** &a, int &size) {
    int oldsize = size;
    size *= 2;
    Student** newtable;
    newtable = new Student*[size];
    for(int i = 0; i < size; i++) {
        newtable[i] = NULL;
    }
    
    for(int i = 0; i < oldsize; i++) {
        Student* current = a[i];
        while(current != NULL) {
            int index = HASH(current, size);
            Student* newstud = current;
            if(newtable[index] ==  NULL) {
                newtable[index] = newstud;
                newtable[index]->next = NULL;
            } else {
                  Student* temp = newtable[index]->next;
                  newstud->next = temp;
                  newtable[index]->next = newstud;
            }
            current = current->next;
        }
    }
    
    a = newtable;
 }
 

void QUIT() {
    
}

int main()
{
    int size = 10;
    Student** TABLE = new Student*[10];
    srand(time(NULL));
   
    
    
    while(true) {
        
        
        if(colCount >= 2) {
        cout << "rehashing" << endl;
        int newsize = size*2;
        rehash(TABLE,size);
        colCount = 0;
        } 
      
      char inputString[10];
      char first[30];
      char last[30];
      int ID;
      float GPA;

      cout << endl;
      cout << "Enter 'add' to add a student, 'print' to print the list, 'quit' to quit after you have came back to this message." << endl;
      cout << " 'average' for the average of all students stored and delete to delete a student by ID" << endl;

      cin.get (inputString, 10);
      cin.get ();

          if (strcmp (inputString, "add") == 0)
    	{
    	  ifstream first("FirstNames.txt");
    	  ifstream last("LastNames.txt");  
    	  
    	  int input;
    	  cin >> input;
    	  int studentID = 1;
    	  for(int i = 0; i < input; i++) {
    	      int firstpos = rand()%100;
    	      int lastpos = rand()%100;
    	      char in[100];
    	      char firstName[20];
    	      char lastName[20];
    	      char FIRST[20];
    	      char LAST[20];
    	      float gpa = rand()%5;
    	      int ID = studentID;
    	     
    	      int c = 1;
    	      while (first.getline(in, 100, '\n')) {
                if (c == firstpos) {
            	strcpy(firstName, in);
            	c++;
                  }
                c++;
              }
              int d = 1;
    	      while (last.getline(in, 100, '\n')) {
                if (d == lastpos) {
            	strcpy(lastName, in);
            	d++;
                  }
                d++;
              }
    	     
    	     
    	     
    	     
    	     
    	     
    	      /*if(first.is_open()) {
    	          for(int i = 0; i < 100; i++) {
    	              if(firstpos == i) {
    	                  first >> firstName;
                	      strcpy(FIRST, firstName);
    	              }
    	              else {
    	                  first >> firstName;
    	              }
    	          }
    	      }
    	      if(last.is_open()) {
    	          for(int i = 0; i < 100; i++) {
    	              if(lastpos == i) {
    	                  last >> lastName;
                	      strcpy(LAST, lastName);
    	              }
    	              else {
    	                  last >> lastName;
    	              }
    	          }
    	      }*/
    	      
    	      Student* newstud = new Student(firstName, lastName, ID, gpa);
    	      if(TABLE[HASH(newstud, size)] ==  NULL) {
        	      TABLE[HASH(newstud, size)] = newstud;
    	      }
    	      else  {
    	          Student* temp = TABLE[HASH(newstud, size)]->next;
        	      newstud->next = temp;
        	      TABLE[HASH(newstud, size)]->next = newstud;
    	      }
    	      cout << newstud->s_firstName << newstud->s_lastName << ID << GPA;
    
    	      studentID++;
    	      
    	      /*cin.get (first, 30);
        	  cin.get ();
        	  cin.get (last, 30);
        	  cin.get ();
        	  cin >> ID;
        	  cin >> GPA;
        	  cin.get ();
        	  Student* newStudent = new Student(first, last, ID, GPA);
        	  ADD(TABLE, newStudent, size);*/
        	  cin.get();

    	  }
    	    
    	  
    	  
    	  if(strcmp (inputString, "print") == 0) {
    	    int c;
    	    cin >> c;
    	    cin.get();
    	    PRINT(c,TABLE, size);
    	}
    	
    	if(strcmp (inputString, "size") == 0) {
    	    int ab = sizeof(TABLE);
    	    cout << ab << endl;
    	}
    	
    	if(strcmp (inputString, "print2") == 0)
    	  print2(TABLE, size);
    	}
      
    	
    	
    }
    
    
    
    

    return 0;
}
