#include <iostream>
#include <cstring>

using namespace std;

struct node {
  int val;
  node* right;
  node* left;
};

void print(node* tree, int tabs) {
    
    if(tree == NULL){
        return;
    }
      tabs++;

      print(tree->right, tabs);
      cout << endl;
      for(int i = 1; i < tabs; i++){
        cout << '\t';
      }
      cout << tree->val << "\n";
      print(tree->left, tabs);
      
}

void insert(node* &tree, int VAL) {
    if(tree ==  NULL) {
        node* NEW = new node();
        NEW->val = VAL;
        tree = NEW;
        return;
        
    }
    else if(VAL > tree->val) {
        if(tree->right != NULL) {
            insert(tree->right, VAL);
        }
        else  {
            node* NEW = new node();
            NEW->val = VAL;
            tree->right = NEW;
            return;
        }
    }
    else if(VAL < tree->val) {
        if(tree->left != NULL) {
            insert(tree->left, VAL);
        }
        else  {
            node* NEW = new node();
            NEW->val = VAL;
            tree->left = NEW;
            return;
        }
    }
}

int nextLargest(node* &tree) {
    if(tree->left == NULL) {
        int a = tree->val;
        if(tree->right != NULL) {
            node* NEW = tree->right;
            tree = NEW;
        }
        else {
            tree = NULL;
        }
        return a;
    }
    if(tree->left != NULL) {
        nextLargest(tree->left);
    }
}

void DELETE(node* &tree, int VAL) {
    if(tree == NULL) {
        cout << "there is nothing stored in the tree" << endl;
        return;
    }
    else if(VAL == tree->val) {
        if(tree->left == NULL && tree->right == NULL) {
            tree = NULL;
            return;
        }
        else if(tree->left == NULL && tree->right != NULL) {
          node* NEW = tree->right;
            tree = NEW;
            return;
        }
        else if(tree->right == NULL && tree->left != NULL) {
          node* NEW = tree->left;
            tree = NEW;
            return;
        }
        else if(tree->right != NULL && tree->left != NULL) {
            tree->val = nextLargest(tree->right);
        }
            return;

    }
    else if(VAL > tree->val) {
        if(tree->right != NULL) {
            DELETE(tree->right, VAL);
        }
        else  {
          cout << "that number has not been stored in the tree" << endl;
            return;
        }
    }
    else if(VAL < tree->val) {
        if(tree->left != NULL) {
            DELETE(tree->left, VAL);
        }
        else  {
            cout << "that number has not been stored in the tree" << endl;
            return;
        }
    }
}

void search(node* tree, int VAL) {
    if(tree == NULL) {
        cout << "tree is empty" << endl;
        return;
    }
    else if(tree->val == VAL) {
        cout << "yes, this number is in the tree" << endl;
        return;
    }
    else if(VAL > tree->val) {
        if(tree->right != NULL) {
            DELETE(tree->right, VAL);
        }
        else  {
          cout << "that number is not in the tree" << endl;
            return;
        }
    }
    else if(VAL < tree->val) {
        if(tree->left != NULL) {
            DELETE(tree->left, VAL);
        }
        else  {
            cout << "that number is not in the tree" << endl;
            return;
        }
    }
}




int main() {

  node* tree = NULL;

  while(true) {
      cout << "type your command" << endl;
      char inputString[20];
      cin.get(inputString, 20);
    if(strcmp(inputString, "insert") == 0) {
      int input;
      cin >> input;
      insert(tree, input);
      print(tree, 0);
      cin.get();
      cout << endl;
    }
    else if(strcmp(inputString, "delete") == 0) {
      cin.get();
        int input;
        cin >> input;
        DELETE(tree, input);
        print(tree, 0);
        cin.get();
        cout << endl;
    }
    else if(strcmp(inputString, "print") == 0) {
        print(tree, 0);
        cin.get();
        cout << endl;
    }
    else if(strcmp(inputString, "quit") == 0) {
        exit(0);
    }
    else if(strcmp(inputString, "search") == 0) {
        int input;
        cin >> input;
        search(tree, input);
        cin.get();
        cout << endl;
    }
    else {
        cout << "please type a real command" << endl;
        cin.get();
    }

  }


}
