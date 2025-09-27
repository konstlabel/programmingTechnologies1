#include "ProfessorRepository.h"
#include <iostream>

using namespace ProfessorRepositories;

ProfessorRepository::ProfessorRepository() : professors(8, true) {

	std::cout << "The ProfessorRepository's default constructor is called " << std::endl;
}

ProfessorRepository::ProfessorRepository(int capacity, bool ownsObjects) : professors(capacity, ownsObjects) {

	std::cout << "The ProfessorRepository's parameterized constructor is called " << std::endl;
}

ProfessorRepository::ProfessorRepository(const ProfessorRepository& other) : professors(other.professors) {

	std::cout << "The ProfessorRepository's copy constructor is called " << std::endl;
}

ProfessorRepository::~ProfessorRepository() {

	std::cout << "The ProfessorRepository's destructor is called " << std::endl;
}

ProfessorRepository& ProfessorRepository::operator =(const ProfessorRepository& other) {

	if (this != &other) return *this;
	professors = other.professors;
	return *this;
}

bool ProfessorRepository::operator ==(const ProfessorRepository& other) const {

	return professors == other.professors;
}

int ProfessorRepository::getSize() const {

	return professors.getSize();
}

int ProfessorRepository::getCapacity() const {

	return professors.getCapacity();
}

bool ProfessorRepository::getOwnsObjects() const {

	return professors.getOwnsObjects();
}

void ProfessorRepository::add(const Professor* professor) {

	if (professor == nullptr)
		throw std::invalid_argument("Error! Null pointer professor is not allowed");

	if (professors.exists(*professor))
		throw std::invalid_argument("Error! This professor already exists in the university");

	professors.add(professor);
}

void ProfessorRepository::deleteByIndex(int index) {

	try {
		professors.deleteByIndex(index);
	}
	catch (const std::out_of_range& e) {
		throw e;
	}
}

void ProfessorRepository::deleteByProfessor(Professor* professor) {

	if (professor == nullptr)
		throw std::invalid_argument("Error! Null pointer professor is not allowed");

	if (!professors.exists(*professor))
		throw std::invalid_argument("Error! This professor doesn't exist in the university");

	professors.deleteByObject(professor);
}

Professor* ProfessorRepository::findByIndex(int index) {

	try {
		return professors.getByIndex(index);
	}
	catch (const std::out_of_range&) {
		return nullptr;
	}
}

int ProfessorRepository::findIndexByPointer(Professor* professor) const {

	try {
		return professors.getIndexByPointer(professor);
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

int ProfessorRepository::findIndexByProfessor(const Professor& professor) const {

	try {
		return professors.getIndexByObject(professor);
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

bool ProfessorRepository::exists(const Professor& professor) const {

	return professors.exists(professor);
}

bool ProfessorRepository::isEmpty() const {

	return professors.getSize() == 0;
}

void ProfessorRepository::print() const {

	if (isEmpty()) {
		std::cout << "There are no professors" << std::endl;
		return;
	}

	std::cout << "Professors:" << std::endl;
	professors.print();
}