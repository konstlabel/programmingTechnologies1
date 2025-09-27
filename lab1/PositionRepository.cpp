#include "PositionRepository.h"
#include <iostream>
#include <string>

using namespace PositionRepositories;

std::string PositionRepository::trim(const std::string& str) const {
	
	std::string trimmed = str;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

	return trimmed;
}

PositionRepository::PositionRepository() : positions(8, true) {

	std::cout << "The PositionRepository's default constructor is called " << std::endl;
}

PositionRepository::PositionRepository(int capacity, bool ownsObjects) : positions(capacity, ownsObjects) {

	std::cout << "The PositionRepository's parameterized constructor is called " << std::endl;
}

PositionRepository::PositionRepository(const PositionRepository& other) : positions(other.positions) {

	std::cout << "The PositionRepository's copy constructor is called " << std::endl;
}

PositionRepository::~PositionRepository() {

	std::cout << "The PositionRepository's destructor is called " << std::endl;
}

PositionRepository& PositionRepository::operator =(const PositionRepository& other) {

	if (this == &other) return *this;
	positions = other.positions;
	return *this;
}

bool PositionRepository::operator ==(const PositionRepository& other) const {

	return positions == other.positions;
}

int PositionRepository::getSize() const {

	return positions.getSize();
}

int PositionRepository::getCapacity() const {

	return positions.getCapacity();
}

bool PositionRepository::getOwnsObjects() const {

	return positions.getOwnsObjects();
}

void PositionRepository::add(const std::string& position) {

	std::string trimmed = trim(position);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string position is not allowed");

	if (positions.exists(trimmed))
		throw std::invalid_argument("Error! This position already exists in the university");

	positions.add(new std::string(trimmed));
}

void PositionRepository::remove(const std::string& position) {

	std::string trimmed = trim(position);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string position is not allowed");

	if (!positions.exists(trimmed))
		throw std::invalid_argument("Error! This position doesn't exist in the university");

	positions.deleteByObject(new std::string(trimmed));
}

int PositionRepository::findIndex(const std::string& position) const {

	try {
		return positions.getIndexByObject(position);
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

std::string& PositionRepository::findByIndex(int index) {

	try {
		return *positions.getByIndex(index);
	}
	catch (const std::out_of_range& e) {
		throw e;
	}
}

int PositionRepository::findIndexByPointer(const std::string* position) const {

	try {
		return positions.getIndexByPointer(const_cast<std::string*>(position));
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

bool PositionRepository::exists(const std::string& position) const {

	try {
		return positions.exists(position);
	}
	catch (const std::invalid_argument&) {
		return false;
	}
}

bool PositionRepository::isEmpty() const {

	return positions.isEmpty();
}

void PositionRepository::print() const {

	if (isEmpty()) {
		std::cout << "PositionRepository is empty" << std::endl;
		return;
	}

	std::cout << "Positions: " << std::endl;
	positions.print();
}

