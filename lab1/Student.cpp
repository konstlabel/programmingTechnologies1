#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Role.h"

using namespace Students;

Student::Student() : Person(), groupId(-1), speciality("unknown"), course(1), averageScore(0.0f) {
    
    role = Role::Student;
    std::cout << "The Student's default constructor is called" << std::endl;
}

Student::Student(int id,
                 const std::string& surname,
                 const std::string& name,
                 const std::string& patronymic,
                 int groupId,
                 const std::string& speciality,
                 int course,
                 float averageScore)
    : Person(id, surname, name, patronymic, Role::Student),
      groupId(groupId),
      speciality(speciality),
      course(course),
      averageScore(averageScore) {
 
    std::cout << "The Student's parameterized constructor is called" << std::endl;
}

Student::Student(const Student& other)
    : Person(other),
      groupId(other.groupId),
      speciality(other.speciality),
      course(other.course),
      averageScore(other.averageScore) {
    
    std::cout << "The Student's copy constructor is called" << std::endl;
}

Student::~Student() {
    
    std::cout << "The Student's destructor is called" << std::endl;
}

Student& Student::operator =(const Student& other) {
    
    if (this == &other) return *this;
    
    Person::operator=(other);
    groupId = other.groupId;
    speciality = other.speciality;
    course = other.course;
    averageScore = other.averageScore;

    return *this;
}

int Student::getGroupId() const {
    
    return groupId;
}

const std::string& Student::getSpeciality() const {
    
    return speciality;
}

int Student::getCourse() const {
    
    return course;
}

float Student::getAverageScore() const {
    
    return averageScore;
}

void Student::setGroupId(int groupId) {
    
    if (groupId < 0)
        throw std::invalid_argument("Error! Group ID cannot be negative");
        
    this->groupId = groupId;
}

void Student::setSpeciality(const std::string& speciality) {
    
    std::string trimmed = trim(speciality);
    
    if (trimmed.empty())
        throw std::invalid_argument("Error! Empty string is not allowed");
        
    this->speciality = trimmed;
}

void Student::setCourse(int course) {
    
    if (course < 1 || course > 5)
        throw std::out_of_range("Error! Course must be between 1 and 5");
        
    this->course = course;
}

void Student::setAverageScore(float averageScore) {
    
    if (averageScore < 0.0f || averageScore > 5.0f)
        throw std::out_of_range("Error! Average score must be between 0 and 5");
        
    this->averageScore = averageScore;
}

void Student::clearGroup() {

    groupId = 0;
}

std::string Student::toString() const {

	std::ostringstream oss;
    std::string groupName = (groupId != -1) ? std::to_string(groupId) : "no group";
    oss << surname << " " << name << " " << patronymic <<
                        " | Group Id " << groupName <<
                        " | Speciality " << speciality <<
                        " | Course " << course <<
                        " | Average Score " << std::fixed << std::setprecision(2) << averageScore;
	return oss.str();
}