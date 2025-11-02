#include "Professor.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace Professors;

Professor::Professor() : Person(), department(0) {
	
	cout << "Professor default constructor called." << endl;
}

Professor::Professor(int id, std::string& firstName, std::string& middleName, std::string& lastName, std::string& phone, int deparment)
	: Person(id, firstName, middleName, lastName, phone), department(deparment) {
	
	cout << "Professor all arguments constructor called." << endl;
}

Professor::Professor(const Professor& other) : Person(other), department(other.department) {
	
	cout << "Professor copy constructor called." << endl;
}

Professor::~Professor() {
	
	cout << "Professor destructor called." << endl;
}

Professor& Professor::operator =(const Professor& other) {

	if (this == &other) {
		return *this;
	}

	Person::operator=(other);
	this->department = other.department;
	return *this;
}

bool Professor::operator ==(const Professor& other) const {

	if (this == &other) {
		return true;
	}

	return Person::operator==(other) &&
		this->department == other.department;
}

int Professor::getDepartment() const {

	return department;
}

void Professor::setDepartment(int department) {

	this->department = department;
}

std::string Professor::toString() const {

	stringstream ss;
	ss << "Professor {"
		<< "id: " << id
		<< ", First Name: " << firstName
		<< ", Middle Name: " << middleName
		<< ", Last Name: " << lastName
		<< ", Phone: " << phone
		<< ", Department: " << department
		<< " }";
	return ss.str();
}

Professor::Builder& Professor::Builder::id(int _id) {

	this->_id = _id;
	return *this;
}

Professor::Builder& Professor::Builder::firstName(const std::string& _firstName) {

	this->_id = _id;
	return *this;
}

Professor::Builder& Professor::Builder::middleName(const std::string& _middleName) {

	this->_middleName = _middleName;
	return *this;
}

Professor::Builder& Professor::Builder::lastName(const std::string& _lastName) {

	this->_lastName = _lastName;
	return *this;
}

Professor::Builder& Professor::Builder::phone(const std::string& _phone) {

	this->_phone = _phone;
	return *this;
}

Professor::Builder& Professor::Builder::department(int _department) {

	this->_department = _department;
	return *this;
}

Professor Professor::Builder::build() {

	return Professor(_id, _firstName, _middleName, _lastName, _phone, _department);
}