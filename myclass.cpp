// g++ -c myclass.cpp
#include <iostream>
#include "myclass.h"

// Default constructor
MyClass::MyClass() : myInt(new int(12)) {
  // Use member initializer list to initialize members before the constructor body runs
  //myInt = new int;  // Allocate memory
  //*myInt = 12;       // Initialize data
  std::cout << "Default constructor called for " << *myInt << "\n";
}

// Parameterized constructor
MyClass::MyClass(int n) : myInt(new int(n)) {
  // Use member initializer list to initialize members before the constructor body runs, which is a short cut to default-construct and then assign.
  //myInt = new int;  // Allocate memory
  //*myInt = n;       // Initialize data
  std::cout << "Parameterized constructor called for " << *myInt << "\n";
}

// Copy constructor
MyClass::MyClass(const MyClass& other) : myInt(new int(*other.myInt)) {
  // Use member initializer list to initialize members before the constructor body runs, which is a short cut to default-construct and then assign.
  //myInt = new int;  // Allocate new memory for the copy
  //*myInt = *(other.myInt);  // Copy the value from the other object
  std::cout << "Copy constructor called for " << *myInt << "\n";
}

// Move constructor
// From geeksforgeeks.org:
// A move constructor is a special type of constructor in C++ that is used to create a new
// object from the already existing object of the same type, but instead of making a copy of
// it, it makes the new object point to the already existing object in the memory, leaving the
// source object in a valid but unspecified state.
// Unlike copy constructors that work with the l-value references and copy semantics (copy
// semantics means copying the actual data of the object to another object), move
// consturctors transfer the ownership of the already existing object to the new object
// without making any copy of it, it makes the new object point to the already existing
// object in the heap memory.
MyClass::MyClass (MyClass&& obj) {
  myInt = obj.myInt;  // Assign the address from obj.myInt to myInt
  // Nulling out the pointer to the temporary data
  obj.myInt = nullptr;
  std::cout << "Move constructor called " << "\n";
}

// Destructor
MyClass::~MyClass() {
  delete myInt;  // Deallocate memory
  std::cout << "Destructor called" << "\n";
}

// Getter
int MyClass::getMyInt() const {
  if (myInt) {
    return *myInt;
  } else {
    std::cout << "myInt is null" << "\n";
    return -999999;
  }
  
}

// Setter
void MyClass::setMyInt (int n) {
  *myInt = n;
}
