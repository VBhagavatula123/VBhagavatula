#include <iostream>
#include <cstring>

using namespace std;

class Node {
    public:
    Node();
    ~Node(); 
    void setValue(int newvalue);
    int getValue();
    void setNext(Node* newnext);
    Node* getNext();
    
    
    private:
    int value;
    Node* next;
};

//Node* getNext()
//Student* getStudent()

//Node(Student*) 

//~Node() 

//void setNext(Node*)
