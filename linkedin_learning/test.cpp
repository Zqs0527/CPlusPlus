#include <iostream>
#include <string>
#include <typeinfo>
#include <cstring>

#define CAPACITY 5000
// #define DEBUG

using namespace std;

// int a, b = 5; // single line comment
/* Multiple
* Line
* comment */
auto a = 8;
auto b = 12345789;
auto c = 3.14f;
auto d = 3.14;
const int LENGTH1 = 25;

char arrayStr1[LENGTH1] = "Hello guys! ";
char arrayStr2[] = "What's up";

string stdStr1 = "Hi everybody! ";
string stdStr2 = "How is it going?";

float flt = -7.44f;
int32_t sgn;
uint32_t unsgn;

int array[] = {1, 3, 4, 5, 6};

int main() {
  int summation = array[0] + array[1] + array[2] + array[3] + array[4];
  float average = (float)summation / 5;
  cout << "Sum:     " << summation << endl;
  cout << "Average: " << average << endl;
  float weight = 10.99;
  cout << "Float:           " << weight << endl;
  cout << "Integer:         " << (int)weight << endl;
  cout << "Fraction part:   " << (weight - (int)weight) * 10000 << endl;

  int fahrenheit = 100;
  int celsius;

  celsius = (5.0f / 9) * (fahrenheit - 32);
  cout << "Fahrenheit: " << fahrenheit << endl;
  cout << "Celsius: " << celsius << endl;

  //   sgn = flt;
  //   unsgn = sgn;

  //   cout << "Float: " << flt << endl;
  //   cout << "Signed: " << sgn << endl;
  //   cout << "Unsigned: " << unsgn << endl;

  //   strcat_s(arrayStr1, LENGTH1, arrayStr2);
  //   cout << arrayStr1 << endl;
  //   cout << stdStr1 + stdStr2 << endl;
  //   int32_t large = CAPACITY;
  // #ifdef DEBUG
  //   cout << "[About the if condition]" << endl;
  // #endif

  //   cout << typeid(a).name() << endl;
  //   cout << typeid(b).name() << endl;
  //   cout << typeid(c).name() << endl;
  //   cout << typeid(d).name() << endl;

  //   bool myFlag;
  //   a = 7;
  //   myFlag = false;
  //   cout << "a = " << a << endl;
  //   cout << "b = " << b << endl;
  //   cout << "flag = " << myFlag << endl;

  //   unsigned int positive;
  //   positive = b - a;
  //   cout << "b-a (unsigned) = " << positive << endl;

  // string inputString;
  // cout << "Please enter your name: ";
  // cin >> inputString;
  // cout << "Hi " << inputString << "!" << endl;
  // cout << "Hello world" << endl;
  return 0;
}