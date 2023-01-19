/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */
/*
*  this method takes the linked list and sets it to the tail
*/
void reachEnd(Node*& n) ;

void split(Node*& in, Node*& odds, Node*& evens)
{
  //checks if the linked list is empty
  if (in != nullptr) {
    //gets the next value in 
    int val = in->value;

    //case for evens
    if (val % 2 == 0) {
      //case for empty array
      if (evens == nullptr) {
        evens = in;  //sets the head to current Node
        in = in->next; //increments in so that current element's next is not modified
        evens->next = nullptr;  //sets the next to NULL
      }
      //case for nonempty array
      else {
        //temp node* to come back to
        Node* head = evens;
        reachEnd(evens);

        evens->next = in;  //sets the new Node
        evens = evens->next;  //increments the element
        in = in->next; //increments in so that the current element's next is not modified
        evens->next = nullptr;  //sets the tail's next to NULL
        evens = head;  //resets back to head
      }
    }
    //case for odds
    else {
      //case for empty array
      if (odds == nullptr) {
        odds = in;  //sets the head to current Node
        in = in->next; //increments in so that current element's next is not modified
        odds->next = nullptr;  //sets the next to NULL
      }
      //case for nonempty array
      else {
        //temp node* to come back to
        Node* head = odds;
        reachEnd(odds);

        odds->next = in;  //sets the new Node
        odds = odds->next;  //increments the element
        in = in->next; //increments in so that the current element's next is not modified
        odds->next = nullptr;  //sets the tail's next to NULL
        odds = head;  //resets back to head
      }
    }

    split(in, odds, evens);  //recursive call
  }
  /* Add code here */
// WRITE YOUR CODE HERE
}

/* If you needed a helper function, write it here */
void reachEnd(Node*& n) {
  if (n->next != nullptr) {
    n = n->next;
    reachEnd(n);
  }
}