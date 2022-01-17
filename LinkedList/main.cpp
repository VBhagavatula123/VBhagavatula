//the purpose of this file is to test that each function in the Node class actually works.
//to confirm delete works, I used explicit syntax for the destructor, which confirms that it's being called rather than anything else.
//instructions: add 3 students of your liking, and call add, and you can add, print and you can print and delete and it will invoke the destructor, and the list will collapse with each delete called
//everything else is proved through add and print.
//the deletion process for this program is incomplete, I'm only proving the destructor works.



#include <iostream>
#include "Node.h"

using namespace std;
void print(Node* next, Node* &head);
void add(Student* newStudent, Node* &head);

int main()
{
    Node* head = NULL;
    
    while (true){
        char inputString[10];
        char first[10];
        char last[10];
        int ID;
        float GPA;
   
        cout << endl;
        cout << "Enter 'add' to add a student, 'print' to print the list, 'quit' to quit any time.." << endl;
        
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
            add(newStudent, head);
        }
        else if(strcmp(inputString, "print") == 0) {
             print(head, head);
        }
        else if(strcmp(inputString, "quit") == 0) {
             break;
        }
        else if(strcmp(inputString, "delete") == 0) {
            Node* current = head->getNext();
            head->~Node();//explicit syntax, proving function is being called when students delete.
            head = NULL;
            print(current, head);
        }

    }
    
    
    

    return 0;
}

void add(Student* newStudent, Node* &head){
    Node* current = head;
    if(current == NULL) {
        head = new Node(newStudent);
    }
    else {
        while (current->getNext() != NULL) {
            current = current->getNext();
        }
        current->setNext(new Node(newStudent));
    }
}

void print(Node* next, Node* &head) {
    if(next == head) {
        cout << "list:" << endl;
    }
    if(next != NULL){
        cout << next->getStudent()->s_firstName << "," << next->getStudent()->s_lastName << "," << next->getStudent()->s_id << "," << next->getStudent()->s_GPA << endl;
        print(next->getNext(), head);
        
    }
}
