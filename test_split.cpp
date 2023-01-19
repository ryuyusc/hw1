/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
  Node* list = nullptr;
  Node* odds = nullptr;
  Node* evens = nullptr;

  Node seven(7, nullptr);
  Node six(6, &seven);
  Node five(5, &six);
  Node four(4, &five);
  Node three(3, &four);
  Node two(2, &three);
  Node one(1, &two);
  Node zero(0, &one);
 
  list = &zero;

  split(list, odds, evens);

  cout << "evens" << endl;
  while (evens != nullptr) {
    cout << evens->value << endl;
    evens = evens->next;
  }
  cout << "odds" << endl;
  while (odds != nullptr) {
    cout << odds->value << endl;
    odds = odds->next;
  }

  cout << "list" << endl;
  cout << list << endl;
  
}
