#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

template <typename T> void disp_v(const vector<T> &v) {
  if (!v.size()) {
    return;
  }
  for (T element : v) {
    cout << element << ", ";
  }

  cout << endl;
}

template <typename T> bool isPrime(const T n) {
  if (n <= 1) {
    return false;
  }
  bool isPrime = true;

  for (T i = 2; i < n; i++) {
    if (n%i == 0) {
      isPrime = false;
      break;
    }
  }

  return isPrime;
}

template <typename T> bool isOdd(const T n){
    return n%2 != 0;
}

int main() {
  int n = 47;

  const vector<int> v1 = {4, 56, 65, 71, 13, 59, 7, 53, 29, 3, 97, 5, 11, 47, 2};

  disp_v(v1);

//   sort(v1.begin(), v1.end());

  disp_v(v1);

  if (binary_search(v1.begin(), v1.end(), n)) {
    cout << "found " << n << endl;
  } else {
    cout << "did not find " << n << endl;
  }

  if (all_of(v1.begin(), v1.end(), isPrime<int>))
  {
      cout << "true" << endl;
  }
  else{
      cout << "false" << endl;
  }

  auto it = find_if_not(v1.begin(), v1.end(), isOdd<int>);
  if (it != v1.end())
  {
      size_t index = it - v1.begin();
      cout << "found at index " << index << ": " << *it << endl;
  }
  else{
      cout << "Not found.." << endl;
  }
}