#include "Student.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace Groups;
using namespace Students;

Student::Student() : Person(), group(nullptr) {

	cout << "Student default constructor called." << endl;
}

Student::Student(int id, std::string& firstName, std::string& middleName, std::string& lastName, std::string& phone, Group* group)
	: Person(id, firstName, middleName, lastName, phone), group(group) {

	cout << "Student all arguments constructor called." << endl;
}

Student::Student(const Student& other) : Person(other), group(other.group) {

	cout << "Student copy constructor called." << endl;
}

Student::~Student() {

	delete group;
	cout << "Student destructor called." << endl;
}

Student& Student::operator =(const Student& other) {

	if (this == &other) {
		return *this;
	}

	Person::operator=(other);
	this->group = other.group;
	return *this;
}

bool Student::operator ==(const Student& other) const {

	if (this == &other) {
		return true;
	}

	return Person::operator==(other) &&
		this->group == other.group;
}

Group* Student::getGroup() const {

	return group;
}

void Student::setGroup(Group* group) {

	this->group = group;
}

std::string Student::toString() const {

	stringstream ss;
	ss << "Student {"
		<< "id: " << id
		<< ", First Name: " << firstName
		<< ", Middle Name: " << middleName
		<< ", Last Name: " << lastName
		<< ", Phone: " << phone
		<< ", Group: " << group->getName()
		<< " }";
	return ss.str();
}

Student::Builder& Student::Builder::id(int _id) {

	this->_id = _id;
	return *this;
}

Student::Builder& Student::Builder::firstName(const std::string& _firstName) {

	this->_firstName = _firstName;
	return *this;
}

Student::Builder& Student::Builder::middleName(const std::string& _middleName) {

	this->_middleName = _middleName;
	return *this;
}

Student::Builder& Student::Builder::lastName(const std::string& _lastName) {

	this->_lastName = _lastName;
	return *this;
}

Student::Builder& Student::Builder::phone(const std::string& _phone) {

	this->_phone = _phone;
	return *this;
}

Student::Builder& Student::Builder::group(Group* _group) {

	this->_group = _group;
	return *this;
}

Student Student::Builder::build() {

	return Student(_id, _firstName, _middleName, _lastName, _phone, _group);
}