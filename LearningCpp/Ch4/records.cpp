#include "records.hpp"

Student::Student(int32_t id_i, std::string name_i) {
  id = id_i;
  name = name_i;
};
int32_t Student::get_id() { return id; };
std::string Student::get_name() { return name; };

Course::Course(int32_t id_i, std::string name_i, float credits_i) {
  id = id_i;
  name = name_i;
  credits = credits_i;
};
int32_t Course::get_id() { return id; };
std::string Course::get_name() { return name; };
float Course::get_credits() { return credits; };

Grade::Grade(int32_t student_id_i, int32_t course_id_i, unsigned char grade_i) {
  student_id = student_id_i;
  course_id = course_id_i;
  grade = grade_i;
};
int32_t Grade::get_student_id() { return student_id; };
int32_t Grade::get_course_id() { return course_id; };
unsigned char Grade::get_grade() { return grade; };
