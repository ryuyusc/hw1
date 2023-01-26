#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  std::vector<std::string> content = {"sup", "er", "cal", "i", "frag", "il", "istic", "expi", "alo", "doc", "ious"};

  ULListStr list;

  for (int i = 0; i < 11; i++) {
    list.push_back(content[i]);
  }
  cout << list.get(10) << endl;
	list.pop_back();
  cout << list.get(9) << endl;

}
