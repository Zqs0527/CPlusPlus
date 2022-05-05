#include <iostream>
#include "records.cpp"
#include <fstream>
#include <string>

using namespace std;
ifstream inFile;
ofstream outFile;
string str;
int number;
char letter;

StudentRecords studentRecords;

void initialize(ifstream&);

int main(int, char **) {
  initialize(inFile);
  studentRecords.report_file(outFile);
  return 0;
}

void initialize(ifstream& inFile) {
  int idStudent;
  string nameStudent;

  int idCourse;
  string nameCourse;
  float credits;

  unsigned char grade;
  inFile.open("students.txt");
  if (inFile.fail()) {
    cout << "File is not found.." << endl;
  } else {
    while (!inFile.eof()) {
      getline(inFile, str);
      idStudent = stoi(str);
      getline(inFile, str);
      nameStudent = str;
      studentRecords.add_students(idStudent, nameStudent);
    }
    inFile.close();
  }

  inFile.open("courses.txt");
  if (inFile.fail()) {
    cout << "File is not found.." << endl;
  } else {
    while (!inFile.eof()) {
      getline(inFile, str);
      idCourse = stoi(str);
      getline(inFile, str);
      nameCourse = str;
      getline(inFile, str);
      credits = (float)stoi(str);
      studentRecords.add_courses(idStudent, nameCourse, credits);
    }
    inFile.close();
  }

  inFile.open("grades.txt");
  if (inFile.fail()) {
    cout << "File is not found.." << endl;
  } else {
    while (!inFile.eof()) {
      getline(inFile, str);
      idStudent = stoi(str);
      getline(inFile, str);
      idCourse = stoi(str);
      getline(inFile, str);
      grade = str[0];
      studentRecords.add_grades(idStudent, idCourse, grade);
    }
    inFile.close();
  }
}
