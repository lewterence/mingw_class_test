// g++ -c myclass.cpp
// g++ -c main.cpp
// g++ -o class_test myclass.o main.o
#include <iostream>
#include "myclass.h"

// Function taking an object by value (triggers copy constructor)
void printValue(MyClass);

int main() {
  std::cout << "Testing copy constructor" << "\n";
  MyClass myObj;  // Creation and initialization using default constructor
  MyClass mySecondObj = myObj;  // Creation of a new object using an existing object (triggers copy constructor)
  printValue (myObj);  // Passing by value to a function (triggers copy constructor)
  mySecondObj.setMyInt(30);    // Modify mySecondObj, myObj remains independent
  std::cout << myObj.getMyInt() << "\n";
  std::cout << mySecondObj.getMyInt() << "\n";

  std::cout << "Testing parameterized constructor" << "\n";
  MyClass myThirdObj(40); // Test parameterized constructor

  return 0;
}

void printValue(MyClass obj) {
  std::cout << "Value in function: " << obj.getMyInt() << "\n";
}