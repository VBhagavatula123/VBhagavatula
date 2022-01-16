
#include <iostream>
#include "Node.h"

using namespace std;
void print(Node* next);
void add(Student* newStudent);

Node* head = NULL;

int main()
{
    
    while (true){
        char inputString[10];
        char first[10];
        char last[10];
        int ID;
        float GPA;
   
   
        cout << endl;
        cout << "enter add to add a student and print to print the list" << endl;
        
        cin.get(inputString, 10);
        cin.get();
    

        if(strcmp(inputString, "add") == 0) {
            cin.get(first, 10);
            cin.get();
            cin.get(last, 10);
            cin.get();
            cin >> ID;
            cin >> GPA;
            cin.get();
            Student* newStudent = new Student(first, last,  ID,  GPA);
            add(newStudent);
        }
        else if(strcmp(inputString, "print") == 0) {
             print(head);
        }
        else if(strcmp(inputString, "quit") == 0) {
             break;
        }

    }
    
    
    

    return 0;
}

void add(Student* newStudent){
    Node* current = head;
    if(current == NULL) {
        head = new Node(newStudent);
       
    }
    else {
        while (current->getNext() != NULL) {
            current = current->getNext();
        }
        current->setNext(new Node(newStudent));
        //current->getNext()->setValue(newStudent);
    }
}

void print(Node* next) {
    if(next == head) {
        cout << "list:" << endl;
    }
    if(next != NULL){
        cout << next->getStudent()->s_firstName << "," << next->getStudent()->s_lastName << "," << next->getStudent()->s_id << "," << next->getStudent()->s_GPA << endl;
        print(next->getNext());
        
    }
}
