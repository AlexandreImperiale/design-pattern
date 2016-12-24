#include <iostream>

// Including overtype class.
#include "OverType.h"

// User-defined class to be overtyped.
struct T {
  T() = default;
  T(double) { std::cout << "Double constructor." << std::endl; }
  T(const T&) { std::cout << "Copy constructor." << std::endl; }
  T(T&&) { std::cout << "Move constructor." << std::endl; }
  T& operator=(const T&) {std::cout << "Assignement operator." << std::endl; return *this; }
};

// Definition of first overtype A.
struct TagA {};
using TA = OverType<T, TagA>;

// Definition of second overtype B.
struct TagB {};
using TB = OverType<T, TagB>;

// Definition of function with overtyped input parameters.
void fooAB(const TA&, const TB&) { std::cout << "foo A - B" << std::endl;}
void fooBA(const TB&, const TA&) { std::cout << "foo B - A" << std::endl;}

int main() {

  TA ta0(1.0);
  TA ta1(ta0);
  TA ta2(std::move(ta0));
  TA ta3; ta3 = ta1;

  TB tb0(1.0);

  fooAB(ta0, tb0);
//fooAB(tb0, ta0); // => error ! no matching function for call to 'fooAB'
  fooBA(tb0, ta0);
//fooBA(ta0, tb0); // => error ! no matching function for call to 'fooBA'

}
