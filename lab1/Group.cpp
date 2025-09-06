#include <iostream>
#include <string>

#include "Group.h"

using namespace Groups;

Group::Group() : name("unknown"), students(16, false) {

	std::cout << "The Group's default constructor is called " << std::endl;
}

Group::Group(const std::string& name) : name(name), students(16, false) {

	std::cout << "The Group's parameterized constructor is called " << std::endl;
}

Group::Group(const Group& other) : name(other.name), students(other.students) {

	std::cout << "The Group's copy constructor is called " << std::endl;
}

Group::~Group() {
	std::cout << "The Group's destructor is called " << std::endl;
}

Group& Group::operator =(const Group& other) {
	if (this == &other) return *this;

	name = other.name;

	students = other.students;

	return *this;
}

std::string Group::getName() const {
	return name;
}

Vector<Student>& Group::getStudents() {
	return students;
}

void Group::setName(const std::string& name) {
	this->name = name;
}

void Group::setStudents(const Vector<Student>& students) {
	this->students = students;
}

Student* Group::findByIndex(int index) {
	return students.getByIndex(index);
}

void Group::print() {
	std::cout << "Group " << name << ":" << std::endl;
	students.print();
}