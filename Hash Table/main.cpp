#include <iostream>
#include "Student.h"
#include <cstring>

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
    int o = (j->s_id % (j->s_id % 10))  % size;
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
  }
}


void DELETE() {
    
}

void PRINT(int a, Student* b[], int size){
    Student* current = b[a % size];
    while(current != NULL) {
    cout << current->s_GPA << endl;
    current = current->next;
    }
    
    cout << endl;
    
    for(int i = 0; i < size; i++) {
        Student* current = b[i];
        cout << i << ":   ";
        while(current!= NULL) {
            cout << current->s_GPA << " ";
            current = current -> next;
        }
        cout << endl;
    }
}


void  rehash(Student** &a, int &size) {
    int oldsize = size;
    size = size*2;
    Student** newtable;
    newtable = new Student*[size];
    
    for(int i = 0; i < oldsize; i++) {
        Student* current = a[i];
        while(current != NULL) {
            int index = HASH(current, size);
            Student* newstud = current;
            if(newtable[index] ==  NULL) {
                newtable[index] = newstud;
            } else {
                Student* head = newtable[index];
                while(head->next != NULL) {
                    head = head->next;
                }
                head->next = newstud;
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
    int size = 20;
    Student** TABLE = new Student*[20];
    
    
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
    	  cin.get (first, 30);
    	  cin.get ();
    	  cin.get (last, 30);
    	  cin.get ();
    	  cin >> ID;
    	  cin >> GPA;
    	  cin.get ();
    	  Student* newStudent = new Student(first, last, ID, GPA);
    	  ADD(TABLE, newStudent, size);
    	  
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
    }
    
    
    
    

    return 0;
}
