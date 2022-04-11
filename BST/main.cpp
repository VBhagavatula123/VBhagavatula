        tree = NEW;
        return;

    }
    else if(VAL > tree->val) {// if it's greater pass the right child
        if(tree->right != NULL) {
            insert(tree->right, VAL);
        }
        else  {// if it's great and the right child is NULL, the right child is the new node.
            node* NEW = new node();
            NEW->val = VAL;
            tree->right = NEW;
            return;
        }
    }
    else if(VAL < tree->val) {// if it's less, pass the left child.
        if(tree->left != NULL) {
            insert(tree->left, VAL);
        }
        else  {// if the left child is NULL, make it the new node.
            node* NEW = new node();
            NEW->val = VAL;
            tree->left = NEW;
            return;
        }
    }
}

int nextLargest(node* &tree) {// find the next largest element in the array whilst modifying the tree
    if(tree->left == NULL) {// if the left is finally null
        int a = tree->val;// make a variable to hold the node's value
        if(tree->right != NULL) {// if there is a right subtree
            node* NEW = tree->right;
            tree = NEW;
        }
        else {// if there isn't
            tree = NULL;
        }
        return a;// return the valu
    }
    if(tree->left != NULL) {// if there is a left child, pass it.
        nextLargest(tree->left);
    }
}

void DELETE(node* &tree, int VAL) {// deletion method
    if(tree == NULL) {// if there isn't anything
        cout << "there is nothing stored in the tree" << endl;
        return;
    }
    else if(VAL == tree->val) {// if you have reached the value wished to be deleted
        if(tree->left == NULL && tree->right == NULL) {// if both children are null
            tree = NULL;// delete it
            return;
        }
        else if(tree->left == NULL && tree->right != NULL) {// if the left child is NULL
          node* NEW = tree->right;// make it the right child
            tree = NEW;
            return;
        }
        else if(tree->right == NULL && tree->left != NULL) {// if the right child is NULL
          node* NEW = tree->left;// make it the left child
            tree = NEW;
            return;
        }
        else if(tree->right != NULL && tree->left != NULL) {// if both are NULL
            tree->val = nextLargest(tree->right);// make the value the next largest
        }
            return;

    }
    else if(VAL > tree->val) {// if the value wished to be deleted is > than the traa value, pass the right child
        if(tree->right != NULL) {
            DELETE(tree->right, VAL);
        }
        else  {// if the right child is NULL, the number has not been stored
          cout << "that number has not been stored in the tree" << endl;
            return;
        }
    }
    else if(VAL < tree->val) {// if the value wished to be deleted is < than the traa value, pass the left child
        if(tree->left != NULL) {
            DELETE(tree->left, VAL);
        }
        else  {// if it is NULL, it isn't stored
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
    else if(tree->val == VAL) {//when you reach the number, it exits
        cout << "yes, this number is in the tree" << endl;
        return;
    }
    else if(VAL > tree->val) {// if the number is greater, pass the right child
        if(tree->right != NULL) {
            search(tree->right, VAL);
        }
        else  {// if it's NULL, it doesn't exist
          cout << "that number is not in the tree" << endl;
            return;
        }
    }
    else if(VAL < tree->val) {// if the number is smaller, pass the left child
        if(tree->left != NULL) {
            search(tree->left, VAL);
        }
        else  {// if it's NULL, it doesn't exist.
            cout << "that number is not in the tree" << endl;
            return;
        }
    }
}




int main() {

  node* tree = NULL;//  intialize the tree to empty

  while(true) {
      cout << "type your command: I to insert, D to delete, S to search, P to print, Q to quit" << endl;
      char inputString[20];
      cin.get(inputString, 20);
    if(strcmp(inputString, "I") == 0) {// insertion command
      int input;
      cout << "how many would you like to insert" << endl;// ask for number to input
      cin >> input;
      int arr[input];
      cout << "enter your numbers in a line" << endl;// input
      for(int i = 0; i < input; i++) {
          cin >> arr[i];
      }
      for(int i = 0; i < input; i++) {//run
          insert(tree, arr[i]);
      }
      print(tree, 0);// print
      cin.get();
      cout << endl;
    }
    else if(strcmp(inputString, "D") == 0) {// deletion command
      cin.get();
        int input;
        cout << "how many would you like to delete" << endl;// ask for number to input
        cin >> input;
        int arr[input];
        cout << "enter your numbers in a line" << endl;// input
        for(int i = 0; i < input; i++) {
            cin >> arr[i];
        }
        for(int i = 0; i < input; i++) {// run
            DELETE(tree, arr[i]);
        }
        print(tree, 0);// print
        cin.get();
        cout << endl;
    }
    else if(strcmp(inputString, "P") == 0) {// print command
        print(tree, 0);
        cin.get();
        cout << endl;
    }
    else if(strcmp(inputString, "Q") == 0) {// quit command
        exit(0);
    }
    else if(strcmp(inputString, "S") == 0) {// search command
        int input;
        cout << "enter a number to search" << endl;
        cin >> input; //enter a number to search
        search(tree, input);// search;
        cin.get();
        cout << endl;
    }
    else {
        cout << "please type a real command" << endl;// if it isn't a real command, tell them to type one.
        cin.get();
    }

  }


}
