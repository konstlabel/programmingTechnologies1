#include <iostream>
#include <string>

#include "Group.h"

using namespace Groups;

Group::Group() : name("unknown"), students(16, false) {

	std::cout << "The Group's default constructor is called " << std::endl;
}

Group::Group(const std::string& name) :students(16, false) {

	setName(name);
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

	std::string trimmed = name;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

	if (trimmed.empty())
		this->name = "unknown";
	else
		this->name = trimmed;
}

void Group::setStudents(const Vector<Student>& students) {

	this->students = students;
}

Student* Group::findByIndex(int index) {

	try {
		return students.getByIndex(index);
	}
	catch (const std::out_of_range&) {
		return nullptr;
	}
}

void Group::print() {

	std::cout << "Group " << name << ":";
	if (students.getSize() == 0)
		std::cout << " No students" << std::endl;
	else {

		std::cout << std::endl;
		students.print();
	}
}