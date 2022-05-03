/*
define a structure
    - Containers of heterogeneous data members
    - Implement simple models
    - Also C construct
*/

/*
define a class
    - Basic elements of OOP
    - Useful for implementing models
    - Contain data and function members
    - Same as the class in java and python
*/

/*
Pointer is used for dynamically memory allocation
*/
#include <vector>
#include <iostream>
#include <string>
#include "cow.cpp"
#include "records.cpp"

using namespace std;

int a = 37;
int *ptr;

cow *myCow;

vector<int> primes;
vector<cow> cattle;

Student my_student(1, "Hilda Jones");
Course my_course(7, "Physics 101", 3);
Grade my_grade(1, 7, 'B');

int main() {

  cout << "Student: " << my_student.get_name() << endl;
  cout << "Course: " << my_course.get_name() << endl;
  cout << "Credits: " << my_course.get_credits() << endl;
  cout << "Grade: " << my_grade.get_grade() << endl;
  cattle.push_back(cow("jack", 3, hide));
  cattle.push_back(cow("jane", 5, meat));
  cattle.push_back(cow("bob", 23, dairy));
  cattle.push_back(cow("tom", 32, pet));

  cout << "the first cow is called " << cattle.begin()->get_name() << endl;
  cout << "the index 1 cow is called " << cattle[1].get_name()
       << " and the age is " << cattle[1].get_age() << endl;
  cout << "the name of the next to last cow is "
       << prev(cattle.end(), 2)->get_name() << endl;
  cout << "the name of the last cow is " << (cattle.end() - 1)->get_name()
       << endl;

  primes.push_back(2);
  primes.push_back(3);
  primes.push_back(6);
  primes.push_back(7);

  cout << "The vetor has " << primes.size() << " elements." << endl;

  ptr = &a;
  cout << "The content of a is:             " << a << endl;
  cout << "ptr is pointing to address:      " << ptr << endl;
  cout << "The address of a is:             " << &a << endl;
  cout << "Where ptr is pointing, we have   " << *ptr << endl;
  cout << "The address if ptr is            " << &ptr << endl;

  myCow = new cow("Alice", 7, pet);
  myCow->set_age(5);
  cout << "The age of cow is: " << myCow->get_age() << endl;

  cout << myCow->get_name() << " is a type of " << (int)myCow->get_purpose()
       << " cow." << endl;
  delete myCow;
  return 0;
}