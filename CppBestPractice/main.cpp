#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

enum TrafficLight{
    red,green,yellow
};

enum CarColor{
    black,white,gray,silver
    // yellow // can't have the color green in two enums
};

enum class Pet{
    dog,cat,bird
};
enum class  Mammal{
    bear,cougar,coyote,dog
};

int main(){
    TrafficLight color = TrafficLight::red;
    CarColor camry = CarColor::silver;

    // the surround scope has been polluted
    int colorNumber = red;
    int myCarsColor = black;

    Pet pet = Pet::dog;
    Mammal mammal = Mammal::dog;
    vector<int> alpha{1,2,3};
    // auto beta{1,2,3}; // error: initializer for variable beta with auto type contains three values
    auto gama = {1,2,3}; // this is a list of int event
    auto delta = vector<int>{1,2,3,4};
    vector<int> epsilon;
    // auto zeta; // error : declaration of variable zeta with deduced type auto required initialization

}