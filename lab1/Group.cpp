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

Group::Group(const Group& other) : name(other.name) {

	students = other.students;
	for (int i = 0; i < students.getSize(); i++) {
		students.getByIndex(i)->clearGroup();
		students.getByIndex(i)->attachToGroup(this);
	}

	std::cout << "The Group's copy constructor is called " << std::endl;
}

Group::~Group() {

	for (int i = 0; i < students.getSize(); i++) {
		students.getByIndex(i)->clearGroup();
	}
	std::cout << "The Group's destructor is called " << std::endl;
}

Group& Group::operator =(const Group& other) {

	if (this == &other) return *this;

	name = other.name;
	students = other.students;
	for (int i = 0; i < students.getSize(); i++) {
		students.getByIndex(i)->clearGroup();
		students.getByIndex(i)->attachToGroup(this);
	}
	return *this;
}

bool Group::operator ==(const Group& other) const {
	
	return (this->name == other.name) &&
		(this->students == other.students);
}

const std::string& Group::getName() const {

	return name;
}

const Vectors::Vector<Students::Student>& Group::getStudents() const {

	return students;
}

void Group::setName(const std::string& name) {

	std::string trimmed = name;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string is not allowed");
	else
		this->name = trimmed;
}

void Group::setStudents(const Vectors::Vector<Students::Student>& students) {

	this->students = students;
}

void Group::clearName() {

	name = "unknown";
}

void Group::addStudent(Student* student) {

	try {
		if (students.exists(*student) == false) {

			if (student->getGroup() != nullptr) {
				student->clearGroup();
			}
			students.add(student);
			student->setGroup(this);
		}
		else {
			std::cout << "The student is already in this group!" << std::endl;
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Group::deleteStudentByIndex(int index) {

	try {
		Student* student = students.getByIndex(index);
		student->detachFromGroup();
		students.deleteByIndex(index);
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Group::deleteStudent(Student* student) {

	try {
		students.deleteByObject(student);
		student->detachFromGroup();
	}
	catch (const std::invalid_argument&) {
		throw std::invalid_argument("Error! No the student in group");
	}
}

Student* Group::findByIndex(int index) {

	try {
		return students.getByIndex(index);
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
		return nullptr;
	}
}

int Group::findStudentIndex(Student* student) const {

	if (student == nullptr) 
		return -1;
	return students.getIndex(student);
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

std::string Group::toString() const {

	return name;
}