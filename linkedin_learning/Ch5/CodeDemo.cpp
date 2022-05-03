#include <iostream>
#include <string>
#include "records.cpp"

using namespace std;
void initialize();
StudentRecords studentRecord;
int id;
float gpa;
int main(){
    initialize();
    cout << "Please enter student id: ";
    cin >> id;
    gpa = studentRecord.get_gpa(id);

    cout << "The GPA of " << studentRecord.get_student_name(id) << " is " << gpa << endl; 

}
void initialize(){
    studentRecord.add_students(1, "George P. Burdell");
	studentRecord.add_students(2, "Nancy Rhodes");

	studentRecord.add_courses(1, "Algebra", 5);
	studentRecord.add_courses(2, "Physics", 4);
	studentRecord.add_courses(3, "English", 3);
	studentRecord.add_courses(4, "Economics", 4);

	studentRecord.add_grades(1, 1, 'B');
	studentRecord.add_grades(1, 2, 'A');
	studentRecord.add_grades(1, 3, 'C');
	studentRecord.add_grades(2, 1, 'A'); 
	studentRecord.add_grades(2, 2, 'A');
	studentRecord.add_grades(2, 4, 'B');
}