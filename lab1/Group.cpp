#include <iostream>
#include <string>

#include "Group.h"

using namespace Groups;

Group::Group() : name("unknown"), students(16, false) {

	std::cout << "The Group's default constructor is called" << std::endl;
}

Group::Group(const std::string& name) :students(16, false) {

	setName(name);
	std::cout << "The Group's parameterized constructor is called" << std::endl;
}

Group::Group(const Group& other) : name(other.name), students(other.students) {

	std::cout << "The Group's copy constructor is called" << std::endl;
}

Group::~Group() {

	std::cout << "The Group's destructor is called" << std::endl;
}

Group& Group::operator =(const Group& other) {

	if (this == &other) return *this;

	name = other.name;
	students = other.students;
	return *this;
}

bool Group::operator ==(const Group& other) const {

	return (name == other.name && students == other.students);
}

const std::string& Group::getName() const {

	return name;
}

const Vector<int>& Group::getStudents() const {

	return students;
}

void Group::setName(const std::string& name) {

	std::string trimmed = name;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);
	
	if (trimmed.empty())
		throw std::invalid_argument("Group name cannot be empty");
	this->name = trimmed;
}

void Group::setStudents(const Vector<int>& students) {

	this->students = students;
}

void Group::clearName() {

	name = "unknown";
}

void Group::addStudentId(int studentId) {

	if (studentId <= 0)
		throw std::invalid_argument("Student ID must be a positive integer");

	if (students.exists(studentId))
		throw std::invalid_argument("Student ID already exists in the group");

	students.add(studentId);
}

void Group::addStudent(const Student& student) {

	addStudentId(student.getId());
}

void Group::addStudent(std::unique_ptr<Student> student) {

	if (!student)
		throw std::invalid_argument("Null student pointer cannot be added");

	addStudentId(student->getId());
}

void Group::deleteStudentByIndex(int index) {

	students.deleteByIndex(index);
}

void Group::deleteStudentById(int studentId) {

	int index = findStudentIndex(studentId);
	if (index == -1)
		throw std::invalid_argument("Student ID not found in the group");

	students.deleteByIndex(index);
}

void Group::deleteStudent(const Student& student) {
	deleteStudentById(student.getId());
}

void Group::deleteStudent(std::unique_ptr<Student> student) {

	if (!student)
		throw std::invalid_argument("Null student pointer cannot be deleted");

	deleteStudentById(student->getId());
}

int Group::findByIndex(int index) const {

	if (index < 0 || index >= students.getSize())
		throw std::out_of_range("Index out of range");

	try {
		return students.getByIndex(index);
	}
	catch (const std::logic_error&) {
		throw std::logic_error("getByIndex is only implemented for int type");
	}
}

int Group::findStudentIndex(int studentId) const {

	return students.getIndexByObject(studentId);
}

int Group::findStudentIndex(const Student& student) const {

	return findStudentIndex(student.getId());
}

int Group::findStudentIndex(const std::unique_ptr<Student> student) const {
	
	if (!student)
		throw std::invalid_argument("Null student pointer cannot be searched");
	
	return findStudentIndex(student->getId());
}

bool Group::studentExists(int studentId) const {

	return students.exists(studentId);
}

bool Group::studentExists(const Student& student) const {

	return studentExists(student.getId());
}

bool Group::studentExists(const std::unique_ptr<Student> student) const {

	if (!student)
		throw std::invalid_argument("Null student pointer cannot be searched");

	return studentExists(student->getId());
}

void Group::print() const {

	std::cout << "Group Name: " << name << std::endl;

	std::cout << "Students IDs in the group:" << std::endl;
	students.print();
}