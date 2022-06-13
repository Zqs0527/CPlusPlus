#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> alpha{1,2,3};
    // auto beta{1,2,3}; // error: initializer for variable beta with auto type contains three values
    auto gama = {1,2,3}; // this is a list of int event
    auto delta = vector<int>{1,2,3,4};
    vector<int> epsilon;
    // auto zeta; // error : declaration of variable zeta with deduced type auto required initialization
}