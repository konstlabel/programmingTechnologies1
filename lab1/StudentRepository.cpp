#include "StudentRepository.h"
#include <iostream>

using namespace StudentRepositories;

StudentRepository::StudentRepository() : students(8, true) {

	std::cout << "The StudentRepository's default constructor is called " << std::endl;
}

StudentRepository::StudentRepository(int capacity, bool ownsObjects) : students(capacity, ownsObjects) {

	std::cout << "The StudentRepository's parameterized constructor is called " << std::endl;
}

StudentRepository::StudentRepository(const StudentRepository& other) : students(other.students) {

	std::cout << "The StudentRepository's copy constructor is called " << std::endl;
}

StudentRepository::~StudentRepository() {

	std::cout << "The StudentRepository's destructor is called " << std::endl;
}

StudentRepository& StudentRepository::operator =(const StudentRepository& other) {

	if (this == &other) return *this;
	students = other.students;
	return *this;
}

bool StudentRepository::operator ==(const StudentRepository& other) const {

	return students == other.students;
}

int StudentRepository::getSize() const {

	return students.getSize();
}

int StudentRepository::getCapacity() const {

	return students.getCapacity();
}

bool StudentRepository::getOwnsObjects() const {

	return students.getOwnsObjects();
}

void StudentRepository::add(const Student* student) {

	try {
		students.add(student);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

void StudentRepository::add(const Student& student) {

	try {
		students.add(student);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

void StudentRepository::add(std::unique_ptr<Student> student) {

	try {
		students.add(std::move(student));
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

void StudentRepository::deleteByIndex(int index) {

	try {
		students.deleteByIndex(index);
	}
	catch (const std::out_of_range& e) {
		throw e;
	}
}

void StudentRepository::deleteByStudent(Student* student) {

	try {
		students.deleteByObject(student);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

Student* StudentRepository::findByIndex(int index) {
	try {
		return students.getByIndex(index);
	}
	catch (const std::out_of_range& e) {
		return nullptr;
	}
}

int StudentRepository::findIndexByPointer(Student* student) const {

	try {
		return students.getIndexByPointer(student);
	}
	catch (const std::invalid_argument& e) {
		return -1;
	}
}

int StudentRepository::findIndexByStudent(const Student& student) const {

	try {
		return students.getIndexByObject(student);
	}
	catch (const std::invalid_argument& e) {
		return -1;
	}
}

bool StudentRepository::exists(const Student& student) const {

	return students.exists(student);
}

bool StudentRepository::isEmpty() const {

	return students.getSize() == 0;
}

void StudentRepository::print() const {

	if (isEmpty()) {
		std::cout << "There are no students" << std::endl;
		return;
	}
	std::cout << "Students:" << std::endl;
	students.print();
}


