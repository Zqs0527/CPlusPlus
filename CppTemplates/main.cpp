#include <iostream>
using namespace std;
template<typename T> T pi = T(3.1415926535897932385L); // template variable

int main(int, char**) {
    cout.precision(20);
    cout << pi<long double> << endl;
    return 0;
}
