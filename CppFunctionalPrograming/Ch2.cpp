#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

namespace A::B::C {
  int i;
}

bool greaterThan(const int &firstValue, const int &secondValue) {
  return firstValue >= secondValue;
}

int main() {

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