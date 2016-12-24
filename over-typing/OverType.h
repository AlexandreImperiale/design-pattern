
// Definition of the generic class used for over typing.
// The idea is to defing this class as a template class over the type T
// to be "over typed" and a Tag type used to discremenate instances of type T.
//
// The OverType class inherits from the type T publicly in order to recover any
// public members defined in T. Moreover, the constructer of any OverTypes is
// simply forwarding any arguments to the constructor of type T.

template<typename T, typename Tag> struct OverType : public T {

  template<typename... Args> explicit OverType(Args&&... args) : T(std::forward<Args>(args)...) {}

};
