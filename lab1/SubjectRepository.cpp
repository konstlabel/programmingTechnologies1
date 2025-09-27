#include "SubjectRepository.h"
#include <iostream>

using namespace SubjectRepositories;

std::string SubjectRepository::trim(const std::string& str) const {

	std::string trimmed = str;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

	return trimmed;
}

SubjectRepository::SubjectRepository() : subjects(8, true) {

	std::cout << "The SubjectRepository's default constructor is called " << std::endl;
}

SubjectRepository::SubjectRepository(int capacity, bool ownsObjects) : subjects(capacity, ownsObjects) {

	std::cout << "The SubjectRepository's parameterized constructor is called " << std::endl;
}

SubjectRepository::SubjectRepository(const SubjectRepository& other) : subjects(other.subjects) {

	std::cout << "The SubjectRepository's copy constructor is called " << std::endl;
}

SubjectRepository::~SubjectRepository() {

	std::cout << "The SubjectRepository's destructor is called " << std::endl;
}

SubjectRepository& SubjectRepository::operator =(const SubjectRepository& other) {

	if (this == &other) return *this;
	subjects = other.subjects;
	return *this;
}

bool SubjectRepository::operator ==(const SubjectRepository& other) const {

	return subjects == other.subjects;
}

int SubjectRepository::getSize() const {

	return subjects.getSize();
}

int SubjectRepository::getCapacity() const {

	return subjects.getCapacity();
}

bool SubjectRepository::getOwnsObjects() const {

	return subjects.getOwnsObjects();
}

void SubjectRepository::add(const std::string& subject) {

	std::string trimmed = trim(subject);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string subject is not allowed");

	if (subjects.exists(trimmed))
		throw std::invalid_argument("Error! This subject already exists in the university");

	subjects.add(new std::string(trimmed));
}

void SubjectRepository::remove(const std::string& subject) {

	std::string trimmed = trim(subject);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string subject is not allowed");

	if (!subjects.exists(trimmed))
		throw std::invalid_argument("Error! This subject doesn't exist in the university");

	subjects.deleteByObject(new std::string(trimmed));
}

int SubjectRepository::findIndex(const std::string& subject) const {

	try {
		return subjects.getIndexByObject(subject);
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

std::string& SubjectRepository::findByIndex(int index) {
	try {
		return *subjects.getByIndex(index);
	}
	catch (const std::out_of_range& e) {
		throw e;
	}
}

int SubjectRepository::findIndexByPointer(const std::string* subject) const {
	try {
		return subjects.getIndexByPointer(const_cast<std::string*>(subject));
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

bool SubjectRepository::exists(const std::string& subject) const {
	try {
		return subjects.exists(subject);
	}
	catch (const std::invalid_argument&) {
		return false;
	}
}

bool SubjectRepository::isEmpty() const {
	return subjects.isEmpty();
}

void SubjectRepository::print() const {

	if (isEmpty()) {
		std::cout << "No subjects available." << std::endl;
		return;
	}

	std::cout << "subjects:" << std::endl;
	subjects.print();
}



