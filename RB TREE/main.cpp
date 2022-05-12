#include <iostream>
#include <cstring>
#include <fstream>

/* RBT insertion by vivek bhagavatula 5/11/22

program that takes file and user input to sort a tree for very efficient worst case traversal*/

using namespace std;

struct node {
    int val;
    char color = 'R';
    node* right;
    node* left;
    node* parent;
};// RBT node struct including parent pointers and value as well as color



void rebalance(node* &NODE, node*&head);

void R(node* &t, node* &n) {// right rotation
    node* temp = n->left;// place a temp variable for the rotation
    n->left = temp->right;
    
    if(n->left != NULL) {// set the nodes new parent
        n->left->parent = n;
    }
    temp->parent = n->parent;
    if(n->parent == NULL) {// if the parent is null it's the root
        t = temp;
    }
    else  {
        if(n == n->parent->right) {// set the nodes parent to the temp which is now on top
            n->parent->right = temp;
        }
        else if(n == n->parent->left) {
            n->parent->left = temp;
        }
    }
    temp->right = n;// set pointers
    n->parent = temp;// setting pointers.
}



void L(node* &t, node* &n) {// left rotation mirror of left
    node* temp = n->right;
    n->right = temp->left;
    
    if(n->right != NULL) {
        n->right->parent = n;
    }
    temp->parent = n->parent;
    
    if(n->parent == NULL) {
        t = temp;
    }
    else  {
        if(n == n->parent->left) {
            n->parent->left = temp;
        }
        else {
            n->parent->right = temp;
        }
    }
    temp->left = n;
    n->parent = temp;
}



int height(node* NODE, int key, int level) {// get the node's height fore the tree cases
    if(NODE ==  NULL) {
        return 0;
    }
    else if(NODE->val ==  key) {
        return level;
    }
    else if(key > NODE->val) {
        height(NODE->right, key, level+1);
    }
    else if(key < NODE->val) {
        height(NODE->left, key, level+1);
    }
}



void rotate(node* &tree, node* &t) {// rotation function for figuring out the rotation
    if(tree->parent->left == tree) {
        if(tree->parent->parent->left == tree->parent) {// LL case
            R(tree->parent->parent, t);
            tree->color = 'R';
            tree->parent->color = 'B';
            if(tree->parent->right != NULL) {
                tree->parent->right->color = 'R';
            }
            return;
        }
        tree->color = 'B';
        tree->right->color = 'R';
        tree->left->color = 'R';
        return;
    }
    else if(tree->parent->right == tree) {
        if(tree->parent->parent->right == tree->parent) {//LL
            L(tree->parent->parent, t);
            tree->color = 'R';
            tree->parent->color = 'B';
            if(tree->parent->left != NULL) {
                tree->parent->left->color = 'R';
            }
            return;
        }
        tree->color = 'B';
        tree->right->color = 'R';
        tree->left->color = 'R';
        return;
    }
}

void print(node* tree, int tabs) {
    
    if(tree == NULL){// if the tree is empty there's nothing to print
        return;
    }
      tabs++;

      print(tree->right, tabs);// go as far out right
      cout << endl;
      for(int i = 1; i < tabs; i++){
        cout << '\t';
      }
      cout << tree->val << "(" << tree->color << ")" <<  "\n";
      print(tree->left, tabs); //then do the left
      
}// printing function geeks for geeks


void insert(node*& head, node*& NODE, node*& Parent, int VAL){ // inserts node with value "value" into head
	if(head == NULL){
		head = new node();
		head->val = VAL;
		head->color = 'B';
		NODE = head;
		return;
	}
	if(VAL < NODE->val){
		Parent = NODE;
		NODE = NODE->left;
		if(NODE == NULL){// if it is empty add a new node and set pointers
			NODE = new node();
			NODE->val = VAL;
			Parent->left = NODE;
			NODE->parent = Parent;
			
			rebalance(NODE, head);// fix the tree
			return;
		}
		else{
			insert(head, NODE, Parent,VAL);// otherwise call
		}
	}
	else{// for values greater
		Parent = NODE;
		NODE = NODE->right;
		if(NODE == NULL){// add new node
			NODE = new node();
			NODE->val = VAL;
			Parent->right = NODE;
			NODE->parent = Parent;
			
			rebalance(NODE, head);// fix
			return;
		}
		else{
			insert(head, NODE, Parent, VAL);// recall
		}
	}
}



void rebalance(node*& NODE, node* &head){ //balancing function geeks for geeks
    node* P = NULL;
    node* GP = NULL;
    while ((NODE != head) && (NODE->color != 'B') && (NODE->parent->color == 'R')) {
        P = NODE->parent;
        GP = P->parent;
        // left of granparent
        if (P == GP->left) {
            node* U = GP->right;
            // recolor uncle
            if (U != NULL && U->color != 'B') {
                GP->color = 'R'; 
                P->color = 'B'; 
                U->color = 'B'; 
                NODE = GP;
            }
            else {
                // left rotate
                if (NODE == P->right) {
                    L(head, P);
                    NODE = P;
                    P = NODE->parent;
                }
                //right rotate
                R(head, GP);
                // switch colors
                
                char temp = P->color;
                P->color = GP->color;
                GP->color = temp;
                NODE = P;
            }
        }
        // right of grandparent
        else {
            node* U = GP->left;
            // recolor, uncle is red
            if (U != NULL && U->color == 'R') {
                GP->color = 'R';
                P->color = 'B';
                U->color = 'B';
                NODE = GP;
            }
            else {
                //right rotation
                if (NODE == P->left) {
                    R(head, P);
                    NODE = P;
                    P = NODE->parent;
                }
                //left rotation
                L(head, GP);
                // switch colors colors
                char temp = P->color;
                P->color = GP->color;
                GP->color = temp;
                NODE = P;
            }
        }
    }
    head->color = 'B';
}// function to rebalance the tree after insertion

int FileAdd(int target) {// gets a  VAL
    ifstream numbers;
    numbers.open("num.txt");
       int temp;// get a temp place holder to loop
       int counter = 0;
       while(numbers >> temp && counter < 31) {
           if(counter == target) {
               return temp;
               break;
           }
           counter++;
           
       }
       numbers.close();
}

int main()
{
    node* HEAD = NULL;
    int target = 1;
    while(true) {
        char inputString;
        cout << "R to read, A to Add, P to print, Q to quit" << endl;
        cin >> inputString;
        
        if(inputString == 'R') {// FILE command
            int VAL = FileAdd(target);
            target++;
            node* NODE = HEAD;
            node* parent = NULL;
            insert(HEAD, NODE, parent, VAL);
            print(HEAD, 0);
            cin.get();
        }
        else if(inputString == 'A') {// Manual Command
            int VAL;
            cin >> VAL;
            node* NODE = HEAD;
            node* parent = NULL;
            insert(HEAD, NODE, parent, VAL);
            print(HEAD, 0);
        }
        else if(inputString == 'P') {
            print(HEAD,0);
        }
        else if(inputString == 'S') {
            
        }
        else if(inputString == 'Q') {
            exit(0);
        }
    }

    return 0;
}









