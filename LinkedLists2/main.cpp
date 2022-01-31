
#include <iostream>
#include <stdlib.h>
#include "Node.h"

using namespace std;
void print (Node * next, Node * &head);
void add (Student * newStudent, Node * &head);
void DEL (Node * &h, Node * previous, Node * current, int inputID);
void AVG(Node* current);

//Node* head = NULL;
     int main ()
{
  Node *head = NULL;

  while (true)
    {
      char inputString[10];
      char first[10];
      char last[10];
      int ID;
      float GPA;

      cout << endl;
      cout <<
	"Enter 'add' to add a student, 'print' to print the list, 'quit' to quit any time.."
	<< endl;

      cin.get (inputString, 10);
      cin.get ();

      if (strcmp (inputString, "add") == 0)
	{
	  cin.get (first, 10);
	  cin.get ();
	  cin.get (last, 10);
	  cin.get ();
	  cin >> ID;
	  cin >> GPA;
	  cin.get ();
	  Student *newStudent = new Student (first, last, ID, GPA);
	  add (newStudent, head);
	}
      else if (strcmp (inputString, "print") == 0)
	{
	  print (head, head);
	}
      else if (strcmp (inputString, "quit") == 0)
	{
	  break;
	}
      else if (strcmp (inputString, "DELETE") == 0)
	{
	  int inputID;
	  cout << "which student would you like to delete?" << endl;
	  cin >> inputID;
	  cin.get();

	  Node *previous = head;
	  Node *current = head;

	 DEL (head, previous, current, inputID);
     print (head, head);

	}
	else if (strcmp (inputString, "AVG") == 0) {
	    Node* current = head;
	    AVG(current);
	    
	}




      /*
         Node* current = head->getNext();
         head->~Node();
         head = NULL;
         print(current, head);
         }

         } */

    }

  return 0;


}

void
add (Student * newStudent, Node * &head)
{
  Node *current = head;
  if (current == NULL)
    {
      head = new Node (newStudent);
    }
  else
    {
      while (current->getNext () != NULL)
	{
	  current = current->getNext ();
	}
      current->setNext (new Node (newStudent));
      //current->getNext()->setValue(newStudent);
    }
}

void
print (Node * next, Node * &head)
{
  if (next == head)
    {
      cout << "list:" << endl;
    }
  if (next != NULL)
    {
      cout << next->getStudent ()->s_firstName << "," << next->
	getStudent ()->s_lastName << "," << next->getStudent ()->
	s_id << "," << next->getStudent ()->s_GPA << endl;
      print (next->getNext (), head);

    }
}


void
DEL (Node * &head, Node * previous, Node * current, int inputID)
{
  if (inputID == current->getStudent ()->s_id)
    {
      previous->next = current->next;
      delete current;
    }
  else if (inputID != current->getStudent ()->s_id)
    {
      DEL (head, current, current->next, inputID);
    }

}

void
AVG(Node* current) {
    float counter = 0;
    int counter2 = 1;
    float product;
    while (current != NULL) {
        current = current->next;
        counter2++;
        counter = counter + current->getStudent ()->s_GPA;
    }
    
    product = counter/counter2;
    cout << product;
}

