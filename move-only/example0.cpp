#include <iostream>

// Including move-only class..
#include "move-only.h"

// User-defined class to be only moved.
struct T : MoveOnly { };

int main() {

  T t;
//T tt(t); // error ===> call to implicitly-deleted copy constructor of 'T'
}
