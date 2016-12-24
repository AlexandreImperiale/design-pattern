#include <iostream>
#include <vector>

// Including overtype class.
#include "over-typing.h"

// Definition of first overtype A.
struct TagA {};
using VA = OverType<std::vector<double>, TagA>;

// Definition of second overtype B.
struct TagB {};
using VB = OverType<std::vector<double>, TagB>;

// Definition of function with overtyped input parameters.
void fooAB(const VA&, const VB&) { std::cout << "foo A - B" << std::endl;}
void fooBA(const VB&, const VA&) { std::cout << "foo B - A" << std::endl;}
void fooVector(const std::vector<double>&) { std::cout << "foo vector." << std::endl; }

int main() {

  VA va0;
  VB vb0;

  fooAB(va0, vb0);
//fooAB(vb0, va0); // => error ! no matching function for call to 'fooAB'
  fooBA(vb0, va0);
//fooBA(ta0, tb0); // => error ! no matching function for call to 'fooBA'

  va0 = {2.0, 3.0};
  std::cout << va0.size() << std::endl;
  std::cout << va0[0] << " " << va0[1] << std::endl;
  fooVector(va0);
}
