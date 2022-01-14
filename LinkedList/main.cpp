#include <iostream>
#include "Node.h"

using namespace std;
void print(Node* next, Node* head1);
void add(int newvalue, Node* head);

//Node* head = NULL;

int main()
{
    Node* head = NULL;
 
    
    add(5, head);
    print(head, head);
    add(7, head);
    print(head, head);
    add(2, head);
    print(head, head);

    return 0;
}

void add(int newvalue, Node* head){
    Node* current = head;
    if(current == NULL) {
        head = new Node();
        head->setValue(newvalue);
    }
    else {
        while (current->getNext() != NULL) {
            current = current->getNext();
        }
        current->setNext(new Node());
        current->getNext()->setValue(newvalue);
    }
}

void print(Node* head, Node* head1) {
    if(head == head1) {
        cout << "list:" << endl;
    }
    if(head != NULL){
        cout << head->getValue() << " ";
        print(head->getNext(), head);
    }
}
