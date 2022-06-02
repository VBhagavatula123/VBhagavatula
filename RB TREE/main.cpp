#include <iostream>
#include <cstring>
#include <fstream>

/* RBT insertion by vivek bhagavatula 5/11/22 Deletion, June 2nd

sources: https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/
https://medium.com/analytics-vidhya/deletion-in-red-black-rb-tree-92301e1474ea

program that takes file and user input to sort a tree for very efficient worst case traversal*/

using namespace std;



struct node {
    int val;
    char color = 'R';
    node* right;
    node* left;
    node* parent;
    int tag = 0;
};// RBT node struct including parent pointers and value as well as color


void DB(node *&head, node *&n);
void rebalance(node* &NODE, node*&head);
void DELETE(node* &tree, node* root);
void R(node* &t, node* &n);
void L(node* &t, node* &n);
int height(node* NODE, int key, int level);
void rotate(node* &tree, node* &t);
void print(node* tree, int tabs);
void insert(node*& head, node*& NODE, node*& Parent, int VAL);
void rebalance(node*& NODE, node* &head);
node* nextLargest(node* &tree, node* root);
int FileAdd(int target);
void DB2 (node* &DBnode, node* root);
void search(node* tree, int VAL);

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

node* nextLargest(node* &tree, node* root) {// find the next largest element in the array whilst modifying the tree
    if(tree->left == NULL) {// if the left is finally null
        return tree;// return the value
    }
    if(tree->left != NULL) {// if there is a left child, pass it.
        nextLargest(tree->left, root);
    }
}

node* getSibling(node *& node)
{ // gets node's parent's other child
  if(node->parent == NULL) return NULL;
  return (node == node->parent->left) ? node->parent->right : node->parent->left;
}

// geeks for geeks ideas.

node *replace(node* tree, node* root) {// grab to see who is going to replace the node you delete.
    // when node have 2 children
    if (tree->left != NULL and tree->right != NULL)
      return nextLargest(tree->right, root);
 
    // when leaf
    if (tree->left == NULL && tree->right == NULL)
      return NULL;
 
    // when single child
    if (tree->left != NULL)
      return tree->left;
    else
      return tree->right;
  }

void DELETE(node* &tree, node* root) {
    
    node* replacement = replace(tree, root);
    node* parent = tree->parent;
  if(replacement == NULL) {
    if (tree == root) {
      root = NULL;
    }
    else
    {
      if ((replacement == NULL || replacement->color == 'B') && (tree == NULL || tree->color == 'B')) {
        DB(root, tree);
      } else {
        if (getSibling(tree) != NULL) {
          getSibling(tree)->color = 'R';
        }
      }
      // remove from tree
      if (tree == parent->left) {
        parent->left = NULL;
      }
      else {
        parent->right = NULL;
      }
    }
    tree = NULL;
    return;
  }

  
  if(tree->left == NULL || tree->right == NULL) {// left or right = NULL, one doesn't equal NULL
    if (tree == root) {// if it's the root replace it
      
      tree->val = replacement->val;
      tree->left = NULL;
      tree->right = NULL;
    } else { // else if it is an internal node
      node* p = tree->parent;
      if (tree == p->left) {
        p->left = replacement;
      } else {
        parent->right = replacement;
      }
      replacement->parent = parent;
      if ((replacement == NULL || replacement->color == 'B') && (tree == NULL || tree->color == 'B')) {//if a double black conflict then oyu must fix.
        DB(root, tree);
      }
      else {
        replacement->color = 'B';
      }
    }
    return;
  }

  // 2 children
  // swap 
  int t = replacement->val;
  tree->val = replacement->val;
  replacement->val = t;

  DELETE(replacement, root);// re run with replacement as the node. 
    
    
}

bool isRedChild(node *&node)
{ // determines if node's chlid is red
  if ((node->left != NULL && node->left->color == 'R') || (node->right != NULL && node->right->color == 'R'))
  {
    return true;
  }
  return false;
}

node* GetP(node* DBnode) {
    return DBnode->parent;
}

node* GetS(node* DBpar, node* DBnode) {
    if(DBnode == DBpar->right) {
        return DBpar->left;
    } else {
        return DBpar->right;
    }
}

node* GetSN(node* DBsib, node* DBpar) {
    if(DBsib == DBpar->right) {
        return DBsib->left;
    } else  {
        return DBsib->right;
    }
}

node* GetSF(node* DBsib, node* DBpar) {
    if(DBsib == DBpar->right) {
        return DBsib->right;
    } else  {
        return DBsib->left;
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


void DB(node *&root, node *&NODE)
{ // fixes black black
  if (NODE == root)
    return;

  node *sibling = getSibling(NODE);
  node *parent = NODE->parent;

  if (sibling == NULL)
  {
    DB(root, parent);
  }
  else
  {
    if (sibling->color == 'R')
    { // if red sibling
      parent->color = 'R';
      sibling->color = 'B';
      if (sibling == parent->left)
      {
        R(root, parent);
      }
      else
      {
        L(root, parent);
      }
      DB(root, NODE);
    }
    else
    {
      if (isRedChild(sibling))
      { // if black sibling
        if (sibling->left != NULL && sibling->left->color == 'R')
        { //more than 1 left child. 
          if (sibling == parent->left)
          {
             if(sibling->tag != 0) {
                DB2(root, root);
            }
            sibling->left->color = sibling->color;
            sibling->color = parent->color;
            // right rotation about the parent;
            R(root, parent);
          }
          else
          {
            sibling->left->color = parent->color;
            //right rotation about the sibling
            R(root, sibling);
            //left rotation about the parent
            L(root, parent);
          }
        }
        else
        {
          // sibling right chlid is red
          if (sibling == parent->left)
          {
            sibling->right->color = parent->color;
            L(root, sibling);
            //left rotation about the sibling
            R(root, parent);
            //right rotation about the parent
          }
          else
          {
            sibling->right->color = sibling->color;
            sibling->color = parent->color;
            L(root, parent);
            //left rotation about the parent;
          }
        }
        parent->color = 'B';
      }
      else
      {
        // both children are black
        sibling->color = 'R';
        if (parent->color == 'B')
        {
          DB(root, parent); 
        }
        else
        {
            if(sibling->tag != 0) {
                DB2(root, root);
            }
          parent->color = 'B';
        }
      }
    }
  }
}
void DB2 (node* &DBnode, node* root) {// Double black fixer
    
    if(DBnode == root) {
        return;
    }

    node* DBpar = GetP(DBnode);// parent pointer
    node* DBsib = GetS(DBpar, DBnode);//sibling pointer
    node* DBsibN = GetSN(DBsib, DBpar);// near sibling child
    node* DBsibF = GetSF(DBsib, DBpar);// far sibling child.

    
    
    if(DBnode == root) {//case 2 -> root node becomes black 
        if(DBnode->tag == 1) {
            DBnode = NULL;
        }
        return;
    }
    else if((DBpar->color== 'B' && DBsib->color == 'B' && (DBsibN == NULL && DBsibF == NULL))  || ((DBpar->color == 'B' && DBsibF->color == 'B' && DBsibN->color == 'B' && DBsibF->color == 'B') == 'B')) {//case 3
        // Sibling and Sibling's Children are black. 
        DBsib->color = 'R';
        
        if(DBnode->tag == 1) {
            DBnode = NULL;
        }
        
        if(DBpar->color == 'B') {
            DB(DBpar, root);

        } else  {
            DBpar->color == 'B';
            return;
        }
    }
    else if(DBsib->color == 'R') {//case 4 -> Siblings are red.
        char temp = DBpar->color;// swap
        DBpar->color = DBsib->color;
        DBsib->color = temp;
        if(DBpar->right == DBnode) {// rotaions.
            R(root, DBpar);
        }
        else {
            L(root, DBpar);
        }
        DB(DBnode, root);
    }
    else if(DBsib->color == 'B' && DBsibN->color == 'R' && (DBsibF == NULL|| DBsibF->color == 'B')) {//case 5
        // sibling is black, sibling far child is black, singling near child is red.
        char temp = DBsibN->color;
        DBsibN->color = DBsib->color;
        DBsib->color = temp;// swap
        
        if(DBpar->left == DBnode) {//rotaions
            R(root, DBsib);
        } else  {
            L(root, DBsib);
        }
        
        char temp2 = DBpar->color;
        DBpar->color = DBsib->color;
        DBsib->color = temp2;// swap
        if(DBpar->right == DBnode) {// roations
            R(root, DBpar);
        }
        else {
            L(root, DBpar);
        }
        
        DBsibF->color = 'B';
        if(DBnode->tag == 1) {
            DBnode = NULL;
        }
        return;
    }
    else if(DBsib->color == 'B' && DBsibF->color == 'R') {//case 6
        //sibling is black, sibling far shild is red.
        char temp = DBpar->color;
        DBpar->color = DBsib->color;
        DBsib->color = temp;//swap
        if(DBpar->right == DBnode) {//rotaions
            R(root, DBpar);
        }
        else {
            L(root, DBpar);
        }
        
        DBsibF->color = 'B';
        if(DBnode->tag == 1) {
            DBnode = NULL;
        }
        return;
    }
}

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
        cout << "R to read, A to Add, P to print, Q to quit, S to search, D to delete" << endl;
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
            cout << "pick a number to search" << endl;
            int VAL;
            cin >> VAL;
            search(HEAD, VAL);
        }
        else if(inputString == 'D') {
            cout << "choose a number to delete" << endl;
            int VAL;
            cin >> VAL;
          node* TEMP = HEAD;
          while (TEMP->val != VAL)
          { // find the right node
            if (VAL < TEMP->val){
              TEMP = TEMP->left;
            }
            else if (VAL > TEMP->val){
              TEMP = TEMP->right;
            }
          }
          //get the node and pass it
            DELETE(TEMP, HEAD);
            print(HEAD, 0);
        }
        else if(inputString == 'Q') {
            exit(0);
        }
    }

    return 0;
}
