#include "classroom.hpp"
#include <iostream>
#include <sys/types.h>
#include <vector>

// Definitions for ClassRoom class Functions
uint ClassRoom::getStudentCount() const { return n; }
void ClassRoom::addStudent(Student student) {
  students.push_back(student);
  students.back().setClassRoom(this);
}

// Definitions for Student class Functions
std::string Student::getName() const { return name; }
unsigned int Student::getRollNum() const { return rollNum; }

void Student::setName(std::string studentName) { name = studentName; }
void Student::setRollNum(unsigned int roll) { rollNum = roll; }
void Student::setClassRoom(ClassRoom *classroom) {
  this->classRoom = classroom;
}

std::ostream &operator<<(std::ostream &stream, const Student &student) {
  stream << student.name << " -> " << student.rollNum << std::endl;
  return stream;
}

int main() {
  Student ali{"Ali", 13};
  Student Usman;

  ClassRoom class1{1};
  class1.addStudent(ali);
  class1.addStudent(Usman);

  std::cout << "Class 1 -> " << class1.getStudentCount() << " Students !!"
            << std::endl;

  for (Student &stud : class1.students) {
    std::cout << stud;
  }

  return 0;
}
