# design-pattern
The goal of this repo is to regroup various design patterns that may be useful
when building C++ libraries.

## pympl pattern
Light pattern used to seperate the algorithm from the data in a class.
This pattern is close to the Pimpl idiom and the way member function are implemented in python.

## over-typing pattern
This pattern can be used to add tag to already defined type while keeping its API intact.

## move-only pattern
Imposing a user-defined type to be move only by simple inheritence from a "Move-Only" class.

## builder pattern
Helper class used to create instances of a class with large number of internal data that
should potentially satisfy contrains.
