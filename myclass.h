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

    // Destructor
    ~MyClass();

    // Getter
    int getMyInt() const;

    // Setter
    void setMyInt (int);

  private:
    int* myInt;  // Pointer to dynamically allocated memory
};

#endif
