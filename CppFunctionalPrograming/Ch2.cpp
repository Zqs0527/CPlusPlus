#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <numeric>
using namespace std;

namespace A::B::C {
  int i;
}

bool greaterThan(const int &firstValue, const int &secondValue) {
  return firstValue >= secondValue;
}

void demoFunction() { cout << "Demo function is called" << endl; }

void adder(const int &a, const int &b) {
  cout << "Called adder, a+b = " << a + b << endl;
}

class functors {
public:
  void operator()() const { cout << "Called functors" << endl; }
};

auto addCurry = [](auto a) {
  return [a](auto b) { return [a, b](auto c) { return a + b + c; }; };
};

auto incrementer = []() {
  int increment = 0;
  return [increment]() mutable { return increment++; };
};

auto continuousAdd = [](int initial, int addBy) {
  int i = initial;
  return [i, addBy]() mutable { return i += addBy; };
};

int main() {

  auto x = continuousAdd(100, 20);

  cout << "The first increment: " << x() << endl;
  cout << "The second increment: " << x() << endl;
  cout << "The third increment: " << x() << endl;

  auto myInc = incrementer();
  cout << "The first increment: " << myInc() << endl;
  cout << "The second increment: " << myInc() << endl;
  cout << "The third increment: " << myInc() << endl;

  auto add1 = addCurry(2);
  auto add2 = add1(2);
  auto addResults = add2(34);

  cout << "Add curry results: " << addResults << endl;
  cout << "Give all three values: " << addCurry(10)(20)(30) << endl;

  vector<function<void()>> funcs;
  funcs.push_back(demoFunction);

  functors functor_object;
  funcs.push_back(functor_object);

  funcs.push_back([]() { cout << "Called lambda function" << endl; });
  funcs.push_back(bind(&adder, 10, 15));

  for (auto &v : funcs) {
    v();
  }

  vector<int> ages{9, 20, 15, 6, 7, 12, 56, 78, 53};
  int over21 = 0;
  for (const int &value : ages) {
    if (value >= 21) {
      over21 += 1;
    }
  }
  cout << "Number over 21 = " << over21 << endl;

  //   auto numberOf21 = count_if(ages.begin(), ages.end(),
  //                              [](const int &value) { return value >= 21; });

  auto numberOf21 = count_if(ages.begin(), ages.end(),
                             bind(&greaterThan, placeholders::_1, 21));
  cout << "New number over 21 = " << numberOf21 << endl;

  auto values = [](auto collection) {
    for (const auto &x : collection) {
      cout << x << endl;
    }
  };

  vector<int> inCollection = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<int> outCollection(inCollection.size(), 0);
  transform(inCollection.begin(), inCollection.end(), outCollection.begin(),
            [](const int &value) { return value * 3; });

  cout << "Transform" << endl;
  values(outCollection);

  vector<int> filteredCollection(inCollection.size(), 0);
  copy_if(inCollection.begin(), inCollection.end(), filteredCollection.begin(),
          [](const int &x) { return x % 2 != 0; });
  cout << "Copy if" << endl;
  values(filteredCollection);

  int accumulated = accumulate(
      filteredCollection.begin(), filteredCollection.end(), 0,
      [](const int &total, const int &current) { return total + current; });
  cout << "Accumulated" << endl;
  cout << accumulated << endl;
  A::B::C::i = 42;
  std::cout << "Nested namespace are available: " << A::B::C::i << std::endl;
  return 0;
}