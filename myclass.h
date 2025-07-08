#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
  public:
    // Default constructor
    MyClass();

    // Parameterized constructor
    MyClass(int);

    // Copy constructor
    MyClass(const MyClass&);

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
    MyClass (MyClass&&) noexcept;

    // Destructor
    ~MyClass();

    // Copy assignment operator
    MyClass& operator=(const MyClass& other);

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept;

    // Operator <
    friend bool operator<(const MyClass& m1, const MyClass& m2);

    // Operator ==
    friend bool operator==(const MyClass& m1, const MyClass& m2);

    // Getter
    int getMyInt() const;

    // Setter
    void setMyInt (int);

  private:
    int* myInt;  // Pointer to dynamically allocated memory
};

#endif
