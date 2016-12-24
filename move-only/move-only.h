
// Definition of a MoveOnly structure.
// On the client side, this service is used by only inheriting from the MoveOnly class.

struct MoveOnly  {
  MoveOnly() = default;
  MoveOnly(const MoveOnly&) = delete;
  MoveOnly& operator=(const MoveOnly&) = delete;
};
