
// Definition of the generic class used for over typing.
// The idea is to defing this class as a template class over the type T
// to be "over typed" and a Tag type used to discremenate instances of type T.
//
// The OverType class inherits from the type T publicly in order to recover any
// public members defined in T. Moreover, the constructer of any OverTypes is
// simply forwarding any arguments to the constructor of type T.

template<typename T, typename Tag> struct OverType : public T {

  OverType(const T& t) : T(t) {}
  OverType(T&& t) : T(std::move(t)) {}

  OverType& operator=(const T& t) { T::operator=(t); return *this; }
  OverType& operator=(T&& t) { T::operator=(std::move(t)); return *this; }

  template<typename... Args> explicit OverType(Args&&... args) : T(std::forward<Args>(args)...) {}
};
