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
  Drink(const char *s) { 
    _drink = s;
    cout << "\n Fill in the cup with " << s << endl; }
  const char *getDrink() {  return _drink; }
  ~Drink();
};

class MealCombo {
private:
  Entree *entree;
  Side *side;
  Drink *drink;
  char _bag[100];

public:
  MealCombo(const char *mealType) { sprintf_s(_bag, "\n %s meal combo: ", mealType); }
  void setEntree(Entree *e) { entree = e; }
  void setSide(Side *s) { side = s; }
  void setDrink(Drink *d) { drink = d; }
  const char *openBag() {
    sprintf_s(_bag, "%s, %s, %s, %s,", _bag, entree->getEntree(),
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

// Create Builder for a hotdog meal which has a hotdog, fries and a drink
class HotdogMeal: public MealBuilder
{
public:
  HotdogMeal(){
    _mealCombo = new MealCombo("Hotdog");
  };
  void cookEntree(){
    Hotdog *hotdog = new Hotdog;
    _mealCombo->setEntree(hotdog);
  }
  void cookSide(){
    Salad *salad = new Salad;
    _mealCombo->setSide(salad);
  }
  void fillDrink(){
    Drink *drink = new Drink("Cola");
    _mealCombo->setDrink(drink);
  }
};



int main(int, char **) { 
  MealBuilder *mealBuilder;
  MealCombo *mealCombo;

  int choice;
  cout << "Select a type of meal to make: " << endl;
  cout << "1: Hotdog" << endl;
  cout << "2: Hamburger" << endl;
  cout << "Selection: " << endl;
  cin >> choice;
  cout << endl;

  switch (choice) {
  case 1:
    mealBuilder = new HotdogMeal;
    break;
  case 2:
    mealBuilder = new HotdogMeal;
    break;

  default:
    cout << "Selection doesn't exist.." << endl;
    mealBuilder = nullptr;
    break;
  }
  if (mealBuilder != NULL)
  {
    mealBuilder ->cookEntree();
    mealBuilder->cookSide();
    mealBuilder->fillDrink();
    mealCombo = mealBuilder->getMeal();
    cout << mealCombo->openBag() << endl;
  }
  
}
