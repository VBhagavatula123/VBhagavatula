#include <iostream>
#include <stdlib.h>
#include "Node.h"

using namespace std;
void print (Node * next, Node * &head);
void add (Node * &head, Node * previous, Node * current, int ID, Student* newStudent);
void DEL (Node * &h, Node * previous, Node * current, int inputID);
float AVG (Node * current);

int
main ()
{
  Node *head = NULL;

  while (true)
    {
      char inputString[10];
      char first[30];
      char last[30];
      int ID;
      float GPA;

      cout << endl;
      cout << "Enter 'add' to add a student, 'print' to print the list, 'quit' to quit after you have came back to this message." << endl;
      cout << " 'average' for the average of all students stored and delete to delete a student by ID" << endl;

      cin.get (inputString, 10);
      cin.get ();

      if (strcmp (inputString, "add") == 0)
	{
	  cin.get (first, 30);
	  cin.get ();
	  cin.get (last, 30);
	  cin.get ();
	  cin >> ID;
	  cin >> GPA;
	  cin.get ();
	  Student* newStudent = new Student (first, last, ID, GPA);
	  add(head, head, head, ID, newStudent);
	}
      else if (strcmp (inputString, "print") == 0)
	{
	  print (head, head);
	}
      else if (strcmp (inputString, "quit") == 0)
	{
	  break;
	}
      else if (strcmp (inputString, "delete") == 0)
	{
	  int inputID;
	  cout << "which student would you like to delete?" << endl;
	  cin >> inputID;
	  cin.get ();

	  Node *previous = head;
	  Node *current = head;

	  DEL (head, previous, current, inputID);
	  print (head, head);

	}
      else if (strcmp (inputString, "average") == 0)
    	{
    	  Node *current = head;
    	  cout.setf(ios::fixed,ios::floatfield);
        cout.setf(ios::showpoint);
        cout.precision(2);
    	  cout << "the average gpa of the students stored is: " << AVG (current)
    	    << endl;
    	}
    }

  return 0;
}

void
add(Node * &head, Node * previous, Node * current, int ID, Student* newStudent)
{
  if (head == NULL) {
    head = new Node(newStudent);
    head->getStudent ()->s_id = ID;
  }
else if (ID < head->getStudent ()->s_id)
  {
    Node *temp = head;
    head = new Node (newStudent);
    head->setNext (temp);
  }
else if (current == NULL)
  {
    previous->setNext (new Node (newStudent));
    previous->getNext ()->setNext (NULL);
  }
else if (ID < current->getStudent ()->s_id)
  {
    previous->setNext (new Node (newStudent));
    previous->getNext()->setNext (current);
  }
else {
   add(head, current, current->getNext (), ID, newStudent);
  }
}


void print (Node * next, Node * &head)
{
  if (next == head)
    {
      cout << "list:" << endl;
    }
  if (next != NULL)
       
    {
      cout << next->getStudent ()->s_firstName << "," << next->getStudent ()->
	s_lastName << ",";
	cout.setf(ios::fixed,ios::floatfield);
        cout.setf(ios::showpoint);
        cout.precision(2);
	 cout << next->getStudent ()->s_id << "," << next->
	getStudent ()->s_GPA << endl;
      print (next->getNext (), head);

    }
}


void DEL (Node * &head, Node * previous, Node * current, int inputID)
{
  if (inputID == current->getStudent ()->s_id)
    {
      previous->setNext (current->getNext ());
      delete current;
    }
  else if (inputID != current->getStudent ()->s_id)
    {
      DEL(head, current, current->getNext (), inputID);
    }

}


float AVG (Node * current)
{
  float counter = 0;
  int counter2 = 0;
  while (current != NULL)
    {
      counter += current->getStudent ()->s_GPA;
      current = current->getNext ();
      counter2++;
    }

  return counter/counter2;
}
