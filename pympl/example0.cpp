#include <iostream>
#include <vector>

//
// In header file.
//
class T {

public:

  T(std::vector<double>&& data);

  void foo() const;

private:

  friend struct Impl;
  std::vector<double> data_;

};

//
// Implementation of algorithms associated to type T.
//
struct Impl {
  static void foo(const T& self) // ===> Remark the "self" name of T instance.
  {
    for(const auto& e : self.data_) std::cout << e << " ";
    std::cout << std::endl;
  }
};

//
// In implementation file.
//
// Constructors.
T::T(std::vector<double>&& data) : data_(std::move(data)) {}

// Indirections to implementations.
void T::foo() const { Impl::foo(*this); }

//
// Main.
//
int main() {

  T t({0., 1., 2.});
  t.foo();
}
