#include <iostream>
using namespace std;

class Background {
protected:
  const char *_color;

public:
  Background(){};
  virtual void CreateBackground() = 0;
};

class GeneralText {
protected:
  const char *_name;

public:
  GeneralText(){};
  virtual void CreateText() = 0;
};

class UiDesginFactory {
public:
  virtual Background *CreateBackgroundFactory() = 0;
  virtual GeneralText *CreateTextFactory() = 0;
};

class LightBackground : public Background {
public:
  LightBackground() {
    cout << "Create a light background.." << endl;
  };
  void CreateBackground() { _color = "Light"; }
};

class DarkBackground : public Background {
public:
  DarkBackground() {
    cout << "Create a dark background.." << endl;
  };
  void CreateBackground() { _color = "Dark"; }
};

class WhiteText : public GeneralText {
public:
  WhiteText() { cout << "Create white texts.." << endl; };
  void CreateText() { _name = "White"; }
};

class BlackText : public GeneralText {
private:
  /* data */
public:
  BlackText(/* args */) { cout << "Create black texts.." << endl; };
  void CreateText() { _name = "Black"; }
};

class WhiteUiFactory : public UiDesginFactory {

public:
  WhiteUiFactory(/* args */){};
  Background *CreateBackgroundFactory() { return new LightBackground(); }
  GeneralText *CreateTextFactory() { return new WhiteText(); }
};

class BlackUiFactory : public UiDesginFactory {

public:
  BlackUiFactory(/* args */){};
  Background *CreateBackgroundFactory() { return new DarkBackground(); }
  GeneralText *CreateTextFactory() { return new BlackText(); }
};

int main() {
  UiDesginFactory *uiFactory;
  int choice;
  cout << "Select a type of theme to make: " << endl;
  cout << "1: Black theme" << endl;
  cout << "2: White theme" << endl;
  cout << "Selection: " << endl;
  cin >> choice;
  cout << endl;

  switch (choice) {
  case 1:
    uiFactory = new BlackUiFactory();
    break;
  case 2:
    uiFactory = new WhiteUiFactory();
    break;

  default:
    cout << "Selection doesn't exist.." << endl;
    uiFactory = NULL;
    break;
  }

  if (uiFactory != NULL) {
    Background *backGround = uiFactory->CreateBackgroundFactory();
    GeneralText *text = uiFactory->CreateTextFactory();
    backGround->CreateBackground();
    text->CreateText();
  }
}
