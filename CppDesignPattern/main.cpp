#include <iostream>

using namespace std;

class Entree {
protected:
  const char * _entree;

public:
  const char *getEntree() { return _entree; }
};

class Burger: public Entree
{
public:
  Burger(/* args */){
    cout << "\n Grill burger patty, add tomatoes and place them in a bun";
    _entree = "hamburger";
  };

};

class Hotdog: public Entree
{
public:
  Hotdog(/* args */){
    cout << "\n Cook sausage and place it in a bun";
    _entree = "hotdog";
  };

};

class Side {
protected:
  const char * _side;

public:
  const char *getSide() { return _side; }
};

class Fries: public Side
{
public:
  Fries(){
    cout << "\n Fry and season potatoes";
    _side = "fries";
  };
  ~Fries(){};
};

class Salad: public Side
{
public:
  Salad(){
    cout << "\n Make salad";
    _side = "salad";
  };
  ~Salad(){};
};


class Drink {
protected:
  const char *_drink;

public:
  Drink(const char *s) : _drink(s) { cout << "Fill in the cup with soda" << endl; }
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
  ~MealCombo(){};
};

class MealBuilder
{
protected:
  MealCombo *_mealCombo;
public:
 virtual void cookEntree() = 0;
 virtual void cookSide() = 0;
 virtual void fillDrink() = 0;
 MealCombo *getMeal(){
   return _mealCombo;
 }
};



int main(int, char **) { cout << "Hello, world!\n"; }
