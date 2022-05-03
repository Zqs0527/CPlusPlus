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

void StudentRecords::add_students(int sid, std::string sname){
	students.push_back(Student(sid, sname));
}

void StudentRecords::add_courses(int cid, std::string cname, float ccredits){
	courses.push_back(Course(cid, cname, ccredits));
}

void StudentRecords::add_grades(int sid, int cid, unsigned char grade){
	grades.push_back(Grade(sid, cid, grade));
}

float StudentRecords::get_grade_num(unsigned char letter) {
  float num_grade;
  switch (letter) {
  case 'A':
    num_grade = 4.0f;
    break;
  case 'B':
    num_grade = 3.0f;
    break;
  case 'C':
    num_grade = 2.0f;
    break;
  case 'D':
    num_grade = 1.0f;
    break;

  default:
    num_grade = 0.0f;
    break;
  }

  return num_grade;
};

std::string StudentRecords::get_student_name(int id_i) {
  std::string student_name;
  for (Student &s : students) {
    if (s.get_id() == id_i) {
      return s.get_name();
    }
    /* Throw exception if given id is not in the list*/
    
  }
}

float StudentRecords::get_credits(int id_course) {
  for (Course &c : courses) {
    if (c.get_id() == id_course) {
      return c.get_credits();
    }
  }
}

float StudentRecords::get_gpa(int id_student) {
  float totalPoints;
  float totalCredits;
  for (Grade &g : grades) {
    if (g.get_student_id() == id_student) {
      totalCredits += get_credits(g.get_course_id());
      totalPoints += get_grade_num(g.get_grade()) * get_credits(g.get_course_id());
    }
  }
  return totalPoints / totalCredits;
}
