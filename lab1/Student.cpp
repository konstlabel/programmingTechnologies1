#include <iostream>
#include<string>
#include "Student.h"
#include "Group.h"
#include "Role.h"

using namespace Students;

void Student::attachToGroup(Group* group) {

    this->group = group;
}

void Student::detachFromGroup() {

    group = nullptr;
}

Student::Student()
    : Person(), group(nullptr), speciality("unknown"), course(1), averageScore(0) {

    role = Role::Student;
    std::cout << "The Student's default constructor is called" << std::endl;
}

Student::Student(const std::string& surname,
    const std::string& name,
    const std::string& patronymic,
    Group* group,
    const std::string& speciality,
    int course,
    float averageScore)
    : Person(surname, name, patronymic) {

    setGroup(group);
    setSpeciality(speciality);
    setCourse(course);
    setAverageScore(averageScore);
    role = Role::Student;
    std::cout << "The Student's parameterized constructor is called" << std::endl;
}

Student::Student(const Student& other) : Person(other.surname, other.name, other.patronymic),
                                         group(other.group),
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
    group = other.group;
    speciality = other.speciality;
    course = other.course;
    averageScore = other.averageScore;
    role = other.role;

    return *this;
}

const Group* Student::getGroup() const {

    return group;
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

void Student::setGroup(Group* group) {

    if (group == nullptr)
        throw std::invalid_argument("Error! Null pointer element is not allowed");

    if (group->getStudents().exists(*this) == false) {
        clearGroup();
        group->addStudent(this);
    }

    this->group = group;
}

void Student::setSpeciality(const std::string& speciality) {

    std::string trimmed = speciality;
    trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
    trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

    if (trimmed.empty())
        this->speciality = "unknown";
    else
        this->speciality = trimmed;
}

void Student::setCourse(int course) {

    if (course < 1 || course > 5)
        throw std::invalid_argument("Error! course must be between 1 and 5");
    this->course = course;
}

void Student::setAverageScore(float averageScore) {

    if ((averageScore < 2 || averageScore > 5) && averageScore != 0)
        throw std::invalid_argument("Error! average score must be between 2 and 5 or equl to 0 (NaN data)");

    this->averageScore = averageScore;
}

void Student::clearGroup() {

    if (group != nullptr) {
        Group* oldGroup = group;
        group = nullptr;
        oldGroup->deleteStudent(this);
    }
}

std::string Student::toString() const {
    std::string groupName = (group != nullptr) ? group->getName() : "no group";
    return surname + " " + name + " " + patronymic +
                        " | Group " + groupName +
                        " | Speciality " + speciality +
                        " | Course " + std::to_string(course) +
                        " | Average Score " + std::to_string(averageScore);
}