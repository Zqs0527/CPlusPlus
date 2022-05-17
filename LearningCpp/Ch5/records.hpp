#pragma once
#include <string>
#include <vector>

class Student {
private:
  int32_t id;
  std::string name;

public:
  Student(int32_t id_i, std::string name_i);
  int32_t get_id();
  std::string get_name();
};

class Course {
private:
  int32_t id;
  std::string name;
  float credits;

public:
  Course(int32_t id_i, std::string name_i, float credits_i);
  int32_t get_id();
  std::string get_name();
  float get_credits();
};

class Grade {
private:
  int32_t student_id;
  int32_t course_id;
  unsigned char grade;

public:
  Grade(int32_t student_id_i, int32_t course_id_i, unsigned char grade_i);
  int32_t get_student_id();
  int32_t get_course_id();
  unsigned char get_grade();
};

class StudentRecords {
private:
  std::vector<Student> students;
  std::vector<Course> courses;
  std::vector<Grade> grades;

public:
  void add_students(int, std::string);
  void add_courses(int, std::string, float);
  void add_grades(int, int, unsigned char);
  float get_grade_num(unsigned char);
  std::string get_student_name(int);
  float get_credits(int);
  float get_gpa(int);
  void report_card(int);
};