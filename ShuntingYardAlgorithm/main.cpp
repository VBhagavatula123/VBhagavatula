#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct Node {
    Node* next;
    char token;
};
struct Node2 {
    Node* substree;
};
class BSTnode {
    public:
    Node* right;
    Node* left;
    int a;
};
//stack functions
void print(Node * head) {
  while (head != NULL) {
    cout << head->token << " ";
    head = head->next;
  }
  cout << endl;
}
void push(Node * &head, int inputValue) {
Node* insert = new Node();
insert->token = inputValue;
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
    int count = 0;
    Node* previous = head;
    Node* current = head;
    while(current->next != NULL) {
        previous = current;
        current = current->next;
        count++;
    }
    if(count == 0) {
        char c = head->token;
        head = NULL;
    }
    
    char c = current->token;
    previous->next = NULL;
    delete current;
    cout << endl;
    
    return c;
}
char peek(Node * head) {
    Node* current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    char c = current->token;
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
    insert->token = inputValue;
    if(head == NULL) {
      head = insert;
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
//BST functions
int prec(char c) {
    if(c == '^') {
        return 3;
    }
    else if(c == '/' || c=='*') {
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    else {
        return -1;
    }
}

vector<char> INFIX() {
    Node* stack = NULL;
    int l;
    cin >> l;
    char infix[l];
    vector<char> output;
    vector<char> discard;
    for(int i = 0; i < l; i++) {
        cin >> infix[i];
    }
    
    for(int i = 0; i < l; i++) {
        if (infix[i] >= '0' && infix[i] <= '9') {
            output.push_back(infix[i]);
        }

        else if(infix[i] == '(') {
            push(stack, infix[i]);
        }
        
        else if(infix[i] == ')') {
            while(peek(stack) != '(') {
                output.push_back(pop(stack));
            }
            discard.push_back(pop(stack));
        }
        
        else {
            while(stack != NULL && prec(infix[i]) <= prec(peek(stack))) {
                output.push_back(pop(stack));
            }
            push(stack, infix[i]);
        }
        
        }
        
        while(stack != NULL) {
            output.push_back(pop(stack));
        }
    
    for(int i = 0; i < l; i++) {
        cout << output[i] << " ";
    }
    
    return output;

}

void buildTree() {
    /*Node* stack2 = NULL;
    for(int i = 0; i < l; i++) {
        if(output[i] == '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9' || '0') {
            push(stack2, output[i]);
        }
    }*/
    
}

void infix() {
    /*if (tree not empty)
    postfix (tree left subtree)
    postfix (tree right subtree)
    print (tree token)*/
}
void prefix() {
    
    
}
void postfix() {
    
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
    if(strcmp(inputString, "INFIX") == 0) {
        INFIX();
    }
    if(strcmp(inputString, "length") == 0) {
        cout << getLength(stack);
    }
    
    }
    

}
