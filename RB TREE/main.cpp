#include <iostream>
#include <cstring>

using namespace std;

struct node {
    int val;
    char color;
    node* right;
    node* left;
    node* parent;
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
      
}

void rotate() {
    
}
    


void insert(node* &tree, int VAL) {// insertion methog
    if(tree ==  NULL) {// if it's NULL make the tree the new node with the value
        node* NEW = new node();
        NEW->val = VAL;
        NEW->color = 'B';
        tree = NEW;
        tree->parent = NULL;
        return;

    }
    else if(VAL > tree->val) {// if it's greater pass the right child
        if(tree->right != NULL) {
            insert(tree->right, VAL);
        }
        else  {// if it's great and the right child is NULL, the right child is the new node.
            node* NEW = new node();
            NEW->val = VAL;
            NEW->color = 'R';
            tree->right = NEW;
            tree->right->parent = tree;
            if(tree->parent->color == 'B') {
               return; 
            }
            else if(tree->parent->parent->left->color == 'R') {
                tree->parent->parent->left->color = 'B';
                tree->parent->color = 'B';
                return;
            }
            else if(tree->parent->parent->left->color == 'B') {
                //rotations
            }
        }
    }
    else if(VAL < tree->val) {// if it's less, pass the left child.
        if(tree->left != NULL) {
            insert(tree->left, VAL);
        }
        else  {// if the left child is NULL, make it the new node.
            node* NEW = new node();
            NEW->val = VAL;
            NEW->color = 'R';
            tree->left = NEW;
            tree->left->parent = tree;
            if(tree->parent->color == 'B') {
               return; 
            }
            else if(tree->parent->parent->right->color == 'R') {
                tree->parent->parent->right->color = 'B';
                tree->parent->color = 'B';
                return;
            }
            else if(tree->parent->parent->right->color == 'B') {
                //rotations
            }
        }
    }
}



int main()
{
    node* tree = NULL;
    
    while(true) {
        if(strcmp(inputString, 'A') == 0) {
            int VAL;
            cin VAL;
            insert(tree, VAL);
        }
        else if(strcmp(inputString, 'D') == 0) {
            
        }
        else if(strcmp(inputString, 'S') == 0) {
            
        }
        else if(strcmp(inputString, 'Q') == 0) {
            exit(0);
        }
    }

    return 0;
}


