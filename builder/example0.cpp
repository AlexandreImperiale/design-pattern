#include <iostream>

// User-defined class.
// We want to be sure that a specific constrain is satisfied by any instances of
// the T class. For example, this class has 4 doubles, and we want to be sure that
// d0 < d1 < d2 < d3, otherwise a specific behavior is followed, e.g. an excpetion is
// thrown.
class T {

public:

  double getSum() const { return d0_ + d1_ + d2_ + d3_; }

private:

  friend class TBuilder;
  double d0_, d1_, d2_, d3_;

};

// Builder class.
class TBuilder {

public:

  // Setters.
  TBuilder& setD0(double d) { t_.d0_ = d; return *this;}
  TBuilder& setD1(double d) { t_.d1_ = d; return *this;}
  TBuilder& setD2(double d) { t_.d2_ = d; return *this;}
  TBuilder& setD3(double d) { t_.d3_ = d; return *this;}

  // Accessing instance. Throw excpetion if badly initialized.
  T get()
  {
    if(t_.d0_ < t_.d1_ && t_.d1_ < t_.d2_ && t_.d2_ < t_.d3_)
    {
      auto t = t_;
      t_ = T();
      return t;
    }
    else throw std::exception();
  }

private:

  T t_;
};

int main() {

  auto t = TBuilder()
    .setD0(0.1)
    .setD1(0.2)
    .setD2(0.3)
    .setD3(10.0)
    .get();

  T tt;
  try {

    tt = TBuilder()
      .setD0(0.1)
      .setD1(-0.2)
      .setD2(0.3)
      .setD3(10.0)
      .get();

  } catch(const std::exception&) { std::cout << "bad initialization" << std::endl; }
}
