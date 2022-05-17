#pragma once
#include <string>
enum cowPurpose { dairy, meat, hide, pet };

class cow {
public:
  cow(std::string name_i, int age_i, unsigned char purpose_i);
  std::string get_name();
  int get_age();
  unsigned char get_purpose();
  void set_age(int newAge);

private:
  std::string name;
  int age;
  unsigned char purpose;
};

