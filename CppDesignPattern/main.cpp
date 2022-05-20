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
  Drink(char *s) : _drink(s) { cout << "Fill in the cup with soda" << endl; }
  const char *getDrink() { return _drink; }
  ~Drink();
};

class MealCombo {
private:
  Entree *entree;
  Side *side;
  Drink *drink;
  char _bag[100];

public:
  MealCombo(const char *type) { sprintf_s(_bag, "/n %s meal combo: ", type); }
  void setEntree(Entree *e) { entree = e; }
  void setSide(Side *s) { side = s; }
  void setDrink(Drink *d) { drink = d; }
  const char *openBag() {
    sprintf_s(_bag, "%s %s %s %s %s", _bag, entree->getEntree(),
              side->getSide(), drink->getDrink());
    return _bag;
  }
  ~MealCombo();
};

int main(int, char **) { cout << "Hello, world!\n"; }
