#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

namespace A::B::C{
    int i;
}

int main(){
    A::B::C::i = 42;
    std::cout << "Nested namespace are available: " << A::B::C::i << std::endl;
    return 0;
}