#include <iostream>
#include <boost/hana.hpp>
#include <vector>
#include <string>
namespace hana = boost::hana;
using namespace hana::literals;
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

template <int summation> struct Factorial<1, summation> {
  enum { value = summation };
}; // specialization

template <int n>
struct Fibonacci {
  enum {
    value = Fibonacci<n-1>::value + Fibonacci<n-2>::value
  };
};

template<>
struct Fibonacci<0>{
  enum{
    value = 0
  };
};

template<>
struct Fibonacci<1>{
  enum{
    value = 1
  };
};

struct MotorCycle {
  string name;
};

struct Truck {
  string name;
  float bedLength;
};

struct Car {
  string name;
};

int main() {
  cout << "Fibonacci(2): " << Fibonacci<2>::value << endl;
  cout << "Fibonacci(3): " << Fibonacci<3>::value << endl;
  cout << "Fibonacci(5): " << Fibonacci<5>::value << endl;

  auto vehicles =
      hana::make_tuple(Car{"Ford"}, Truck{"F-145", 8.8}, MotorCycle{"Ninja"});
  auto hasBedLength = hana::is_valid(
    [](auto &&c)->decltype((void) c.bedLength){});
  
  auto trucks = hana::filter(vehicles, hasBedLength);
  auto nonTrucks = hana::filter(vehicles, hana::compose(hana::not_, hasBedLength));

  hana::for_each(trucks, [](auto &vehicle){
    cout << "Truck = " << vehicle.name << ", bed length = " << vehicle.bedLength << endl;
  });
  hana::for_each(nonTrucks, [](auto &vehicle){
    cout << "Vehicle = " << vehicle.name << endl;
  });

  cout << "8 cubed = " << cube(8) << endl;
  cout << "5 cubed = " << Cube<5>::value << endl;

  return 0;
}