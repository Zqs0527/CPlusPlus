#include <iostream>

using namespace std;

class Coffee
{
protected:
    const char *_type;
public:
    Coffee(/* args */){};
    const char * getType(){
        return _type;
    }
};

// One concrete class
class Espresso: public Coffee
{
private:
    /* data */
public:
    Espresso() : Coffee(){
        _type = "Espresso";
        cout << "Making a cup of espresso" << endl;
        cout << "Grind and brew one scoop of espresso beans." << endl;
    }
    ~Espresso();
};

class Cappucino: public Coffee
{
private:
    /* data */
public:
    Cappucino() : Coffee(){
        _type = "Cappucino";
        cout << "Making a cup of cappucino" << endl;
        cout << "Grind and brew one scoop of cappucino beans. Foam" << endl;
    }
    ~Cappucino();
};

class CoffeFactory
{
private:
    Coffee * _coffee;
public:
    Coffee * GetCoffee(){
        int choice;
        cout << "Select a type of coffe to make: " << endl;
        cout << "1: Espression" << endl;
        cout << "2: Cappucino" << endl;
        cout << "Selection: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            return new Espresso;
            break;
        case 2:
            return new Cappucino;
            break;
        
        default:
            cout << "Selection doesn't exist.." << endl;
            return nullptr;
            break;
        }
    }
};

int main(){
    CoffeFactory coffecMachine;
    Coffee * cup;
    cup = coffecMachine.GetCoffee();
    cout << "You have selected a(n) type: " << cup->getType() << endl;
}



