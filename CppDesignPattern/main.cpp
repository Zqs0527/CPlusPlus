#include <iostream>

using namespace std;

class Entree {
protected:
  char _entree[10];

public:
  Entree(/* args */);
  const char *getEntree() { return _entree; }
  ~Entree();
};

class Side {
protected:
  char _side[10];

public:
  Side(/* args */);
  const char *getSide() { return _side; }
  ~Side();
};

class Drink {
protected:
  char *_drink;

public:
  Drink(char * s): _drink(s){
    cout << "Fill in the cup with soda" << endl;
  }
  const char *getDrink() { return _drink; }
  ~Drink();
};

int main(int, char **) { cout << "Hello, world!\n"; }
