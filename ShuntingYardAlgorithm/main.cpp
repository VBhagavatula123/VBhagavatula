#include <iostream>
#include <cstring>

using namespace std;
struct Node {
    Node* next;
    int value;
};

class BSTnode {
    Node* right;
    Node* left;
    int a;
};

//stack functions
void print(Node * head) {
  while (head != NULL) {
    cout << head->value << " ";
    head = head->next;
  }
  cout << endl;
}

void push(Node * &head, int inputValue) {
Node* insert = new Node();
insert->value = inputValue;
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

int pop(Node * &head) {
    Node* previous = head;
    Node* current = head;
    while(current->next != NULL) {
        previous = current;
        current = current->next;
    }
    
    int c = current->value;
    previous->next = NULL;
    delete current;
    cout << endl;
    
    return c;
}

int peek(Node * head) {
    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    int c = current->value;
    return c;
}

//queue functions
int getLength(Node * head) {
    int counter = 0;
    Node*current  = head;
    while(current != NULL) {
        current = current->next;
        counter++;
    }
    
    return counter;
}

void enqueue(Node * &head, int inputValue) {
    Node* insert = new Node();
    insert->value = inputValue;
    if(head == NULL) {
      head = insert;
      cout <<"hello" << endl;
    }
    else if(head != NULL) {
        insert->next = head;
        head = insert;
    }
    if(getLength(head) >= 6) {
        Node* current = head;
        Node* previous = head;
        int counter = 0;
        while (current->next != NULL && counter < 6) {
            previous = current;
            current = current->next;
            counter++;
        }
        
        previous->next = NULL;
        delete current;
    }
}

void dequeue(Node * &head) {
    Node* current = head;
    Node* previous = head;
    while(current->next != NULL) {
        previous = current;
        current = current->next;
    }
    previous->next = NULL;
    delete current;
}


int main()
{
    Node* stack = NULL;
    Node* queue = NULL;
    
    while (true) {
    char inputString[20];
    cin.get(inputString, 20);
    if(strcmp(inputString, "push") == 0) {
    int inputValue;
    
    cin >> inputValue;
    cin.get();
    
    push(stack, inputValue);
    print(stack);
    }
    if(strcmp(inputString, "pop") == 0) {
        cin.get();
        cout << pop(stack)  << "   ";
        print(stack);
     }
     
    if(strcmp(inputString, "peek") == 0) {
        cin.get();
        cout << peek(stack) << "   ";
        print(stack);
    }
    if(strcmp(inputString, "enqueue") == 0) {
        int inputValue;
        cin >> inputValue;
        cin.get();
        enqueue(queue, inputValue);
        print(queue);
    }
    if(strcmp(inputString, "dequeue") == 0) {
        cin.get();
        dequeue(queue);
        print(queue);
    }
    
        
    }
}
