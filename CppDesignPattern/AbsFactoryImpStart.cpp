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

class Engine {
protected:
  const char *_sound;

public:
  Engine() {};
  virtual void Run() = 0;
  ~Engine() {};
};

class GasEngine : public Engine {
private:
  /* data */
public:
  GasEngine(/* args */) {
    _sound = "vroom";
    cout << "Make a gas engine." << endl;
  }
  void Run() { cout << _sound << endl; }
  ~GasEngine();
};

class ElectricEngine : public Engine {
private:
  /* data */
public:
  ElectricEngine(/* args */) {
    _sound = "wuwuwu";
    cout << "Make a electric engine." << endl;
  }
  void Run() { cout << _sound << endl; }
  ~ElectricEngine();
};

class CarFactory {
private:
  /* data */
public:
  virtual Door *BuildDoor() = 0;
  virtual Engine *BuildEngine() = 0;
};

class GasCarFactory : public CarFactory {
private:
  /* data */
public:
  Door *BuildDoor() { return new GasCarDoor(); }

  Engine *BuildEngine() { return new GasEngine(); }
};

class ElectricCarFactory : public CarFactory {
private:
  /* data */
public:
  Door *BuildDoor() { return new ElectricCarDoor(); }

  Engine *BuildEngine() { return new ElectricEngine(); }
};

int main() {
  CarFactory *carFactory;

  int choice;
  cout << "Select a type of car to make: " << endl;
  cout << "1: Gas car" << endl;
  cout << "2: Electric car" << endl;
  cout << "Selection: " << endl;
  cin >> choice;
  cout << endl;

  switch (choice) {
  case 1:
    carFactory = new GasCarFactory();
    break;
  case 2:
    carFactory = new ElectricCarFactory();
    break;

  default:
    cout << "Selection doesn't exist.." << endl;
    carFactory = nullptr;
    break;
  }

  if (carFactory != NULL)
  {
    Door *myDoor = carFactory->BuildDoor();
    Engine *myEngine = carFactory->BuildEngine();
    myDoor->Open();
    myEngine->Run();
  }
  
}