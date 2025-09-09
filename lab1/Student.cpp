#include <iostream>
#include<string>
#include "Student.h"
#include "Role.h"

using namespace Students;

Student::Student() : Person(), course(1), averageScore(0) {

    role = Role::Student;
    std::cout << "The Student's default constructor is called" << std::endl;
}

Student::Student(const std::string& surname,
    const std::string& name,
    const std::string& patronymic,
    const std::string& groupName,
    const std::string& speciality,
    int course,
    float averageScore) : Person(surname, name, patronymic),
                          groupName(groupName),
                          speciality(speciality),
                          course(course),
                          averageScore(averageScore) {

    role = Role::Student;
    std::cout << "The Student's parameterized constructor is called" << std::endl;
}

Student::Student(const Student& other) : Person(other.surname, other.name, other.patronymic),
                                         groupName(other.groupName),
                                         speciality(other.speciality),
                                         course(other.course),
                                         averageScore(other.averageScore) {

    role = Role::Student;
    std::cout << "The Student's copy constructor is called" << std::endl;
}

Student::~Student() {

    std::cout << "The Student's destructor is called" << std::endl;
}

Student& Student::operator=(const Student& other) {

    if (this == &other) return *this;

    surname = other.surname;
    name = other.name;
    patronymic = other.patronymic;
    groupName = other.groupName;
    speciality = other.speciality;
    course = other.course;
    averageScore = other.averageScore;
    role = other.role;

    return *this;
}

std::string Student::getGroupName() const {

    return groupName;
}

std::string Student::getSpeciality() const {

    return speciality;
}

int Student::getCourse() const {

    return course;
}

float Student::getAverageScore() const {

    return averageScore;
}

void Student::setGroupName(const std::string& groupName) {

    this->groupName = groupName;
}

void Student::setSpeciality(const std::string& speciality) {

    this->speciality = speciality;
}

void Student::setCourse(int course) {

    this->course = course;
}

void Student::setAverageScore(float averageScore) {

    this->averageScore = averageScore;
}

std::string Student::toString() const {

    return std::string(surname + " " + name + " " + patronymic +
                        " | Group " + groupName +
                        " | Speciality " + speciality +
                        " | Course " + std::to_string(course) +
                        " | Average Score " + std::to_string(averageScore));
}