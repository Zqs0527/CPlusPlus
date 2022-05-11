#include <cstdio>
#include <cstdint>

void func() { puts("this is func"); }

class SimpleClass {
private:
  int i = 0;

public:
  void setValue(int value) { i = value; };
  int getValue() { return i; };
};

const char *inputString = "This is a null-terminated string.";

class CheckQualifier {
public:
  int static_value() {
    static int x = 7; // this static integer in this class has a global storage
    return ++x;
  }
};

int functionSimple() {
  static int x = 7;
  return ++x;
};

int &f(int &i) { return ++i; };

union ipv4 {
  uint32_t i32;
  struct {
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
  } octets;
};

struct LibraryCatalogCard {
  const char *title;
  const char *author;
  const char *publisher;
  const char *subject;
  const char *ISBN;
  const char *worldCat;
  float deweyDecimal;
  int yearPublished;
  int yearAcquired;
  int quantityInStock;
};

void printp(uint8_t *p) { printf("pointer is %p, value is %d\n", p, *p); }

int main(int, char **) {
  uint8_t arr[] = {4, 3, 2, 1};
  uint8_t *p1 = arr;
  printp(p1++);
  printp(p1++);
  printp(p1++);

  struct LibraryCatalogCard lbc = {};

  union ipv4 adrs;
  adrs.octets = {192, 168, 73, 42};
  printf("address is %d.%d.%d.%d is %08x\n", adrs.octets.a, adrs.octets.b,
         adrs.octets.c, adrs.octets.d, adrs.i32);

  int inputNumber = 5;
  f(inputNumber) = 43;

  printf("f(i) is %d\n", f(inputNumber));
  printf("i is %d\n", inputNumber);

  puts("Hello world. \' \" \x40 \u03bc");
  CheckQualifier cq1;
  CheckQualifier cq2;
  CheckQualifier cq3;
  printf("The value of i is %d\n", cq1.static_value());
  printf("The value of i is %d\n", cq2.static_value());
  printf("The value of i is %d\n", cq3.static_value());

  // int testValue = functionSimple();
  // testValue = functionSimple();
  // testValue = functionSimple();
  // printf("The value of i is %d\n", testValue);

  float f;
  double d;
  long double ld;
  printf("size of float is %zd bits\n", sizeof(f) * 8);
  printf("size of double is %zd bits\n", sizeof(d) * 8);
  printf("size of long double is %zd bits\n", sizeof(ld) * 8);

  char c = 0;
  short si = 0;
  int i = 0;
  long int li = 0;
  long long int lli = 0;
  printf("size of char is %zd bits\n", sizeof(c) * 8);
  printf("size of short int is %zd bits\n", sizeof(si) * 8);
  printf("size of int is %zd bits\n", sizeof(i) * 8);

  printf("size of long int is %zd bits\n", sizeof(li) * 8);
  printf("size of long long int is %zd bits\n", sizeof(lli) * 8);

  int count = 0;
  for (const char *cp = inputString; *cp; ++cp) {
    count++;
  }
  printf("The number of characters is: %d\n", count);

  puts("this is main");
  int inputValue = 9;
  SimpleClass simpleClass;
  simpleClass.setValue(inputValue);
  printf("value is %d\n", simpleClass.getValue());

  func();
  struct structure {
    int i;
    double d;
    const char *s;
  };

  structure str = {1, 1.24, "this a string"};

  char s[] = {'s', 't', 'r', 'i', 'n', 'g', 0};
  printf("s is %s\n", s);

  // for (int i = 0; s[i] != 0; i++)
  // {
  //     printf("%c\n", s[i]);
  // }
  for (char *cp = s; *cp; ++cp) {
    printf("%c\n", *cp);
  }

  int arrayInit[] = {1, 2, 3, 4};
  for (int &x : arrayInit) {
    printf("%d ", x);
  }
  puts("\n");

  int x = 42;
  const int &y = x;
  int *ip = &x;

  printf("the value of x is %d\n", x);
  printf("the value of y is %d\n", y);
  printf("the value of *ip is %d\n", *ip);

  printf("the value of x is %d\n", x);
  printf("the value of y is %d\n", y);
  printf("the value of *ip is %d\n", *ip);

  int z = 10;
  ip = &z;
  printf("the value of *ip is %d\n", *ip);

  // x = 6;
  // printf("the value of *ip is %d\n", *ip);
  puts("Hello, world!\n");
}
