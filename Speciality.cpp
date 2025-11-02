#include "Speciality.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace Specialities;

Speciality::Speciality() : id(0), name("unknown") {

	cout << "Speciality default constructor called." << endl;
}

Speciality::Speciality(int id, const std::string& name) : id(id), name(name) {

	cout << "Speciality all argumetns constructor called." << endl;
}

Speciality::Speciality(const Speciality& other) : id(other.id), name(other.name) {

	cout << "Speciality copy constructor called." << endl;
}

Speciality::~Speciality() {

	cout << "Speciality destructor called." << endl;
}

Speciality& Speciality::operator =(const Speciality& other) {

	if (this == &other) {
		return *this;
	}

	this->id = other.id;
	this->name = other.name;
	return *this;
}

bool Speciality::operator ==(const Speciality& other) const {

	if (this == &other) {
		return true;
	}

	return this->id == other.id &&
		this->name == other.name;
}

int Speciality::getId() const {

	return id;
}

std::string Speciality::getName() const {

	return name;
}

void Speciality::setId(int id) {

	this->id = id;
}

void Speciality::setName(const std::string& name) {

	this->name = name;
}

std::string Speciality::toString() const {

	std::ostringstream oss;
	oss << "Speciality {"
		<< "id: " << id
		<< ", name: " << name
		<< "}";
	return oss.str();
}

Speciality::Builder& Speciality::Builder::id(int _id) {

	this->_id = _id;
	return *this;
}

Speciality::Builder& Speciality::Builder::name(const std::string& _name) {

	this->_name = _name;
	return *this;
}

Speciality Speciality::Builder::build() {

	return Speciality(this->_id, this->_name);
}