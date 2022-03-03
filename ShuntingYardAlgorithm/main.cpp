#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
struct Node {
    Node* next;
    char token;
};
class Node2 {
    public:
    Node2* right;
    Node2* left;
    Node2* subtree;
    Node2* next;
    char token;
};
void push2(Node2 * &head, Node2* insert) {
    if(head == NULL) {
        head = insert;
    }
    else if(head != NULL) {
        Node2* current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = insert;
        insert->next = NULL;
    }
}
 Node2* pop2(Node2 * &head) {
    int count = 0;
    Node2* previous = head;
    Node2* current = head;
    while(current->next != NULL) {
        previous = current;
        current = current->next;
        count++;
    }
    if(count == 0) {
        Node2* c = head;
        head = NULL;
    }
    
    Node2* c = current;
    previous->next = NULL;
    cout << endl;
    
    return c;
}
//stack functions
void print(Node * head) {
  while (head != NULL) {
    cout << head->token << " ";
    head = head->next;
  }
  cout << endl;
}
void push(Node * &head, char inputValue) {
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
char pop(Node * &head) {
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
Node2* buildTree(vector<char> output) {
    Node2* stack2 = NULL;
    for(int i = 0; i < output.size(); i++) {
        if(output[i] >= '0' && output[i] <= '9') {
            Node2* Operand = new Node2();
            Operand->token = output[i];
            push2(stack2, Operand);
        }
        else if(output[i] == '+' || '-' || '^' || '*' || '/') {
            Node2* Operator = new Node2();
            Operator->token = output[i];
            Operator->right = pop2(stack2);
            Operator->left = pop2(stack2);
            push2(stack2, Operator);
        }
    }

    return stack2;
}

void postfix(Node2* head) {
    if(head == NULL) return;
        postfix(head->left);
        postfix(head->right);
        cout << head->token;
    }
    

void prefix(Node2* head) {
    if(head == NULL) return;
    cout << head->token;
    prefix(head->left);
    prefix(head->right);
    
}
void infix(Node2* head) {
    if(head == NULL) return;
    infix(head->left);
    cout << head->token;
    infix(head->right);
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
       vector<char> OUTPUT = INFIX();
       Node2* TREE = buildTree(OUTPUT);
       char inputString[10];
       cin >> inputString; 
       if(strcmp(inputString, "infix") == 0) {
           infix(TREE);
           cout << endl;
       }
       else if(strcmp(inputString, "prefix") == 0) {
           prefix(TREE);
           cout << endl;
       }
       else if(strcmp(inputString, "postfix") == 0) {
           postfix(TREE);
           cout << endl;
       }
    }
    if(strcmp(inputString, "length") == 0) {
        cout << getLength(stack);
    }
    
    }
}
