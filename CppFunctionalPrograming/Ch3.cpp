#include <iostream>
#include <vector>
using namespace std;

template <typename T> T cube(const T &value) {
  return value * value * value;
} // generic programming, cube function is created at run time
template <int toCube> struct Cube {
  enum { value = toCube * toCube * toCube };
}; // TMP, it is at compile time

int factorial(const int input, int summation = 1) {
  if (input > 1) {
    return factorial(input - 1, input * summation);
  }
  return summation;
}

template <int input, int summation = 1>
struct Factorial : Factorial<input - 1, input * summation> {};

template <int summation> 
struct Factorial<1, summation> {
  enum { value = summation };
}; // specialization

int main() {
  cout << "8 cubed = " << cube(8) << endl;
  cout << "5 cubed = " << Cube<5>::value << endl;

  return 0;
}