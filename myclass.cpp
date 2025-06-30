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

// Destructor
MyClass::~MyClass() {
  delete myInt;  // Deallocate memory
  std::cout << "Destructor called" << "\n";
}

// Getter
int MyClass::getMyInt() const {
  return *myInt;
}

// Setter
void MyClass::setMyInt (int n) {
  *myInt = n;
}
