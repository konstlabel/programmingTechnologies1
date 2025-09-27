#include "SpecialityRepository.h"
#include <iostream>
#include <string>

using namespace SpecialityRepositories;

std::string SpecialityRepository::trim(const std::string& str) const {
	
	std::string trimmed = str;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

	return trimmed;
}

SpecialityRepository::SpecialityRepository() : specialities(8, true) {

	std::cout << "The SpecialityRepository's default constructor is called " << std::endl;
}

SpecialityRepository::SpecialityRepository(int capacity, bool ownsObjects) : specialities(capacity, ownsObjects) {

	std::cout << "The SpecialityRepository's parameterized constructor is called " << std::endl;
}

SpecialityRepository::SpecialityRepository(const SpecialityRepository& other) : specialities(other.specialities) {

	std::cout << "The SpecialityRepository's copy constructor is called " << std::endl;
}

SpecialityRepository::~SpecialityRepository() {

	std::cout << "The SpecialityRepository's destructor is called " << std::endl;
}

SpecialityRepository& SpecialityRepository::operator =(const SpecialityRepository& other) {

	if (this == &other) return *this;
	specialities = other.specialities;
	return *this;
}

bool SpecialityRepository::operator ==(const SpecialityRepository& other) const {

	return specialities == other.specialities;
}

int SpecialityRepository::getSize() const {

	return specialities.getSize();
}

int SpecialityRepository::getCapacity() const {

	return specialities.getCapacity();
}

bool SpecialityRepository::getOwnsObjects() const {

	return specialities.getOwnsObjects();
}

void SpecialityRepository::add(const std::string& speciality) {

	std::string trimmed = trim(speciality);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string speciality is not allowed");

	if (specialities.exists(trimmed))
		throw std::invalid_argument("Error! This speciality already exists in the university");

	specialities.add(new std::string(trimmed));
}

void SpecialityRepository::remove(const std::string& speciality) {

	std::string trimmed = trim(speciality);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string speciality is not allowed");

	if (!specialities.exists(trimmed))
		throw std::invalid_argument("Error! This speciality doesn't exist in the university");

	specialities.deleteByObject(new std::string(trimmed));
}

int SpecialityRepository::findIndex(const std::string& speciality) const {

	try {
		return specialities.getIndexByObject(speciality);
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

std::string& SpecialityRepository::findByIndex(int index) {

	try {
		return *specialities.getByIndex(index);
	}
	catch (const std::out_of_range& e) {
		throw e;
	}
}

int SpecialityRepository::findIndexByPointer(const std::string* speciality) const {

	try {
		return specialities.getIndexByPointer(const_cast<std::string*>(speciality));
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

bool SpecialityRepository::exists(const std::string& speciality) const {

	try {
		return specialities.exists(speciality);
	}
	catch (const std::invalid_argument&) {
		return false;
	}
}

bool SpecialityRepository::isEmpty() const {

	return specialities.getSize() == 0;
}

void SpecialityRepository::print() const {

	if (isEmpty()) {
		std::cout << "There are no specialities" << std::endl;
		return;
	}

	std::cout << "Specialities:" << std::endl;
	specialities.print();
}