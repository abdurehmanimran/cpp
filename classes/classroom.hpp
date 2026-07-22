#pragma once
#include <iostream>
#include <vector>

class Student;
class ClassRoom;

class Student {

public:
  Student() : name{"Student"}, rollNum{0}, classRoom{nullptr} {}
  Student(std::string studentName, unsigned int roll)
      : name{studentName}, rollNum{roll} {}
  Student(std::string studentName, unsigned int roll, ClassRoom *classroom)
      : name{studentName}, rollNum{roll}, classRoom{classroom} {}

  std::string getName() const;
  unsigned int getRollNum() const;
  void setName(std::string studentName);
  void setRollNum(unsigned int roll);
  void setClassRoom(ClassRoom *classroom);

  friend std::ostream &operator<<(std::ostream &stream, const Student &student);

private:
  std::string name;
  unsigned int rollNum;
  ClassRoom *classRoom;
};

class ClassRoom {
public:
  ClassRoom() : id{0}, n{0} {}
  ClassRoom(uint classId) : id{classId}, n{0} {}

  uint getStudentCount() const;
  void addStudent(Student student);
  std::vector<Student> students;

private:
  uint id;
  uint n;
};
