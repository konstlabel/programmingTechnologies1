#include "Person.h"

#include <iostream>
#include <string>

using namespace Persons;

Person::Person() : id(0), firstName(""), middleName(""), lastName(""), phone("") {

	std::cout << "Person default constructor called." << std::endl;
}

Person::Person(int id, const std::string& firstName, const std::string& middleName, const std::string& lastName, const std::string& phone)
	: id(id), firstName(firstName), middleName(middleName), lastName(lastName), phone(phone) {

	std::cout << "Person all arguments constructor called." << std::endl;
}

Person::Person(const Person& other) 
	: id(other.id), firstName(other.firstName), middleName(other.middleName), lastName(other.lastName), phone(other.phone) {
	
	std::cout << "Person copy constructor called." << std::endl;
}

Person::~Person() {

	std::cout << "Person destructor called." << std::endl;
}

Person& Person::operator =(const Person& other) {

	if (this == &other) 
		return *this;

	this->id = other.id;
	this->firstName = other.firstName;
	this->middleName = other.middleName;
	this->lastName = other.lastName;
	this->phone = other.phone;
	return *this;
}

bool Person::operator ==(const Person& other) const {

	return this->id == other.id &&
		this->firstName == other.firstName &&
		this->middleName == other.middleName &&
		this->lastName == other.lastName &&
		this->phone == other.phone;
}

int Person::getId() const {

	return id;
}
std::string Person::getFirstName() const {

	return firstName;
}
std::string Person::getMiddleName() const {

	return middleName;
}

std::string Person::getLastName() const {

	return lastName;
}

std::string Person::getPhone() const {
	
	return phone;
}

void Person::setId(int id) {

	this->id = id;
}

void Person::setFirstName(const std::string& firstName) {

	this->firstName = firstName;
}

void Person::setMiddleName(const std::string& middleName) {

	this->middleName = middleName;
}

void Person::setLastName(const std::string& lastName) {

	this->lastName = lastName;
}

void Person::setPhone(const std::string& phone) {

	this->phone = phone;
}