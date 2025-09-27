#include "ResponsibilityRepository.h"
#include <iostream>
#include <string>

using namespace ResponsibilityRepositories;

std::string ResponsibilityRepository::trim(const std::string& str) const {

	std::string trimmed = str;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

	return trimmed;
}

ResponsibilityRepository::ResponsibilityRepository() : responsibilities(8, true) {

	std::cout << "The ResponsibilityRepository's default constructor is called " << std::endl;
}

ResponsibilityRepository::ResponsibilityRepository(int capacity, bool ownsObjects) : responsibilities(capacity, ownsObjects) {

	std::cout << "The ResponsibilityRepository's parameterized constructor is called " << std::endl;
}

ResponsibilityRepository::ResponsibilityRepository(const ResponsibilityRepository& other) : responsibilities(other.responsibilities) {

	std::cout << "The ResponsibilityRepository's copy constructor is called " << std::endl;
}

ResponsibilityRepository::~ResponsibilityRepository() {

	std::cout << "The ResponsibilityRepository's destructor is called " << std::endl;
}

ResponsibilityRepository& ResponsibilityRepository::operator =(const ResponsibilityRepository& other) {

	if (this == &other) return *this;
	responsibilities = other.responsibilities;
	return *this;
}

bool ResponsibilityRepository::operator ==(const ResponsibilityRepository& other) const {

	return responsibilities == other.responsibilities;
}

int ResponsibilityRepository::getSize() const {

	return responsibilities.getSize();
}

int ResponsibilityRepository::getCapacity() const {

	return responsibilities.getCapacity();
}

bool ResponsibilityRepository::getOwnsObjects() const {

	return responsibilities.getOwnsObjects();
}

void ResponsibilityRepository::add(const std::string& responsibility) {

	std::string trimmed = trim(responsibility);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string responsibility is not allowed");

	if (responsibilities.exists(trimmed))
		throw std::invalid_argument("Error! This responsibility already exists in the university");

	responsibilities.add(new std::string(trimmed));
}

void ResponsibilityRepository::remove(const std::string& responsibility) {

	std::string trimmed = trim(responsibility);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string responsibility is not allowed");

	if (!responsibilities.exists(trimmed))
		throw std::invalid_argument("Error! This responsibility doesn't exist in the university");

	responsibilities.deleteByObject(new std::string(trimmed));
}

int ResponsibilityRepository::findIndex(const std::string& responsibility) const {

	try {
		return responsibilities.getIndexByObject(responsibility);
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

std::string& ResponsibilityRepository::findByIndex(int index) {

	try {
		return *responsibilities.getByIndex(index);
	}
	catch (const std::out_of_range& e) {
		throw e;
	}
}

int ResponsibilityRepository::findIndexByPointer(const std::string* responsibility) const {

	try {
		return responsibilities.getIndexByPointer(const_cast<std::string*>(responsibility));
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

bool ResponsibilityRepository::exists(const std::string& responsibility) const {

	try {
		return responsibilities.exists(responsibility);
	}
	catch (const std::invalid_argument&) {
		return false;
	}
}

bool ResponsibilityRepository::isEmpty() const {

	return responsibilities.isEmpty();
}

void ResponsibilityRepository::print() const {

	if (isEmpty()) {
		std::cout << "The ResponsibilityRepository is empty." << std::endl;
		return;
	}

	std::cout << "Responsibilities:" << std::endl;
	responsibilities.print();
}