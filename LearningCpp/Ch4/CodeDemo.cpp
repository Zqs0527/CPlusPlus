#include <iostream>
#include <string>
#include <vector>
#include "records.cpp"

using namespace std;

vector<int> vectorOfInt = {12, 13, 14, 15, 23};
float average;
int id;
float GPA;

vector<Student> students = {Student(1, "George P. Burdell"),
                            Student(2, "Nancy Rhodes")};

vector<Course> courses = {Course(1, "Algebra", 5), Course(2, "Physics", 4),
                          Course(3, "English", 3), Course(4, "Economics", 4)};

vector<Grade> grades = {Grade(1, 1, 'B'), Grade(1, 2, 'A'), Grade(1, 3, 'C'),
                        Grade(2, 1, 'A'), Grade(2, 2, 'A'), Grade(2, 4, 'B')};
int main() {
  string student_str;
  int grade;
  float GPA = 0;
  int totalCredits = 0;
  cout << "Enter a student id: ";
  cin >> id;
  switch (id) {
  case 1:
    student_str = students.begin()->get_name();
    for (Grade& g : grades) {
      if (g.get_grade() == 'A') {
        grade = 4;
      } else if (g.get_grade() == 'B') {
        grade = 3;
      } else if (g.get_grade() == 'C') {
        grade = 2;
      }
      if (g.get_student_id() == id) {
        switch (g.get_course_id()) {
        case 1:
          totalCredits += 5;
          GPA += 5 * grade;
          break;
        case 2:
          totalCredits += 4;
          GPA += 4 * grade;
          break;
        case 3:
          totalCredits += 3;
          GPA += 3 * grade;
          break;
        case 4:
          totalCredits += 4;
          GPA += 4 * grade;
          break;

        default:
          break;
        }
      }
    }
    GPA /= totalCredits;
    break;
  case 2:
    student_str = students.end()->get_name();
    for (Grade g : grades) {
      if (g.get_grade() == 'A') {
        grade = 4;
      } else if (g.get_grade() == 'B') {
        grade = 3;
      } else if (g.get_grade() == 'C') {
        grade = 2;
      }
      if (g.get_student_id() == id) {
        switch (g.get_course_id()) {
        case 1:
          totalCredits += 5;
          GPA += 5 * grade;
          break;
        case 2:
          totalCredits += 4;
          GPA += 4 * grade;
          break;
        case 3:
          totalCredits += 3;
          GPA += 3 * grade;
          break;
        case 4:
          totalCredits += 4;
          GPA += 4 * grade;
          break;
        default:
          break;
        }
      }
    }
    GPA /= totalCredits;
    break;

  default:
    break;
  }

  cout << "The GPA for " << student_str << " is " << GPA << endl;
  average = 0.0f;
  for (int i = 0; i < vectorOfInt.size(); i++) {
    average += vectorOfInt[i];
  }
  average /= vectorOfInt.size();
  cout << "The average is: " << average << endl;

  average = 0.0f;
  for (int x : vectorOfInt) {
    average += x;
  }
  average /= vectorOfInt.size();
  cout << "The average is: " << average << endl;

  vector<int>::iterator ptr = vectorOfInt.begin();
  while (ptr != vectorOfInt.end()) {
    cout << *ptr << " ";
    ptr = next(ptr, 1);
  }
  cout << endl;
  int i = 0;
  do {
    cout << vectorOfInt[i] << " ";
    i += 1;
  } while (i < vectorOfInt.size());
  cout << endl;

  return 0;
}