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
MyClass::MyClass (MyClass&& obj) noexcept {
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

// Copy assignment operator
MyClass& MyClass::operator=(const MyClass& other) {
  delete myInt;  // Release existing resources
  myInt = new int(*other.myInt);
  std::cout << "Copy assignment operator called" << "\n";
  return *this;
}

// Move assignment operator
MyClass& MyClass::operator=(MyClass&& other) noexcept {

  if (this != &other) {
    // Release our current resources
    delete myInt;
    // Take resources from 'other' and make them our own
    myInt = other.myInt;
    // Reset 'other' to a valid but unspecified state
    other.myInt = nullptr;
  }

  std::cout << "Move assignment operator called" << "\n";
  return *this;
}

// Operator <
// This is a non-member friend function.
bool operator<(const MyClass& m1, const MyClass& m2) {
  return *m1.myInt < *m2.myInt;
}

// Operator ==
// This is a non-member friend function.
bool operator==(const MyClass& m1, const MyClass& m2) {
  return *m1.myInt == *m2.myInt;
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

// Hash specialization implementation
// std::size_t - Return type of the hash function - an unsigned integral type for hash values
// std::hash<MyClass>::operator() - We're defining the function that was declared in the specialization
// (const MyClass& p) const - Takes a constant reference to a MyClass, and doesn't modify its state
// Placement Outside the Class: You define this operator outside the class because we're implementing a method of a template specialization for std::hash, not a member function of MyClass.
std::size_t std::hash<MyClass>::operator()(const MyClass& p) const {
  std::size_t h1 = std::hash<int>{}(p.getMyInt());           // Call the default hash function for int
  return h1;
}
