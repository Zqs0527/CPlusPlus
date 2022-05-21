#include <iostream>
using namespace std;

class Door {
private:
  /* data */
public:
  Door(){};
  virtual void Open() = 0;
};

class GasCarDoor : public Door {
private:
  /* data */
public:
  GasCarDoor(/* args */) { cout << "Making a door for a gas car.." << endl; };
  void Open() { cout << "click" << endl; }
  ~GasCarDoor();
};

class ElectricCarDoor : public Door {
private:
  /* data */
public:
  ElectricCarDoor() { cout << "This is to make an electric car.." << endl; };
  void Open() { cout << "Use the key" << endl; }
  ~ElectricCarDoor();
};

class Engine
{
private:
    /* data */
public:
    Engine(/* args */);
    ~Engine();
};
