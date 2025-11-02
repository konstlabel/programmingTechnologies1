#include "Admin.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace Admins;
using namespace Persons;
using namespace Positions;
using namespace Responsibilities;

Admin::Admin() : Person(), position(nullptr), responsibility(nullptr) {

	cout << "Admin default constructor called." << endl;
}

Admin::Admin(int id, std::string& firstName, std::string& middleName, std::string& lastName, std::string& phone, Position* position, Responsibility* responsibility)
	: Person(id, firstName, middleName, lastName, phone), position(position), responsibility(responsibility) {

	cout << "Admin all arguments constructor called." << endl;
}

Admin::Admin(const Admin& other) : Person(other), position(other.position), responsibility(other.responsibility) {

	cout << "Admin copy constructor called." << endl;
}

Admin::~Admin() {

	delete position;
	delete responsibility;

	cout << "Admin destructor called." << endl;
}

Admin& Admin::operator =(const Admin& other) {

	if (this == &other) {
		return *this;
	}

	Person::operator=(other);
	this->position = other.position;
	this->responsibility = other.responsibility;
	return *this;
}

bool Admin::operator ==(const Admin& other) const {

	if (this == &other) {
		return true;
	}

	return Person::operator==(other) &&
		this->position == other.position &&
		this->responsibility == other.responsibility;
}

Position* Admin::getPosition() const {

	return position;
}

Responsibility* Admin::getResponsibility() const {

	return responsibility;
}

void Admin::setPosition(Position* position) {

	this->position = position;
}

void Admin::setResponsibility(Responsibility* responsibility) {

	this->responsibility = responsibility;
}

std::string Admin::toString() const {

	stringstream oss;
	oss << "Admin {"
		<< "id: " << id
		<< ", First Name: " << firstName
		<< ", Middle Name: " << middleName
		<< ", Last Name: " << lastName
		<< ", Phone: " << phone
		<< ", Position: " << position->getName()
		<< ", Responsibility: " << responsibility->getName()
		<< " }";
	return oss.str();
}

Admin::Builder& Admin::Builder::id(int _id) {

	this->_id = _id;
	return *this;
}

Admin::Builder& Admin::Builder::firstName(const std::string& _firstName) {

	this->_firstName = _firstName;
	return *this;
}

Admin::Builder& Admin::Builder::middleName(const std::string& _middleName) {

	this->_middleName = _middleName;
	return *this;
}

Admin::Builder& Admin::Builder::lastName(const std::string& _lastName) {

	this->_lastName = _lastName;
	return *this;
}

Admin::Builder& Admin::Builder::phone(const std::string& _phone) {

	this->_phone = _phone;
	return *this;
}

Admin::Builder& Admin::Builder::position(Position* _position) {

	this->_position = _position;
	return *this;
}

Admin::Builder& Admin::Builder::responsibility(Responsibility* _responsibility) {

	this->_responsibility = _responsibility;
	return *this;
}

Admin Admin::Builder::build() {

	return Admin(_id, _firstName, _middleName, _lastName, _phone, _position, _responsibility);
}