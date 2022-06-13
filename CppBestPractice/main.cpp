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


template <typename T>
T rcatenate(T v){
    return v;
}

template <typename T, typename ... Args>
T rcatenate(T first, Args... args){
    return rcatenate(args...) + " " + first;
}

int main(){
    string s1 = "big", s2 = "cat", s3 = "time";
    string cc = rcatenate(s1, s2, s3);
    cout << "reverse concatenated = " << cc << endl;

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