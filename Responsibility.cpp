#include "Responsibility.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace Responsibilities;

Responsibility::Responsibility() : id(0), name("unknown") {

	cout << "Responsibility default constructor called." << endl;
}

Responsibility::Responsibility(int id, const std::string& name) : id(id), name(name) {

	cout << "Responsibility all argumetns constructor called." << endl;
}

Responsibility::Responsibility(const Responsibility& other) : id(other.id), name(other.name) {

	cout << "Responsibility copy constructor called." << endl;
}

Responsibility::~Responsibility() {

	cout << "Responsibility destructor called." << endl;
}

Responsibility& Responsibility::operator =(const Responsibility& other) {

	if (this == &other) {
		return *this;
	}

	this->id = other.id;
	this->name = other.name;
	return *this;
}

bool Responsibility::operator ==(const Responsibility& other) const {

	if (this == &other) {
		return true;
	}

	return this->id == other.id &&
		this->name == other.name;
}

int Responsibility::getId() const {

	return id;
}

std::string Responsibility::getName() const {

	return name;
}

void Responsibility::setId(int id) {

	this->id = id;
}

void Responsibility::setName(const std::string& name) {

	this->name = name;
}

std::string Responsibility::toString() const {

	std::ostringstream oss;
	oss << "Responsibility {"
		<< "id: " << id
		<< ", name: " << name
		<< "}";
	return oss.str();
}

Responsibility::Builder& Responsibility::Builder::id(int _id) {

	this->_id = _id;
	return *this;
}

Responsibility::Builder& Responsibility::Builder::name(const std::string& _name) {

	this->_name = _name;
	return *this;
}

Responsibility Responsibility::Builder::build() {

	return Responsibility(this->_id, this->_name);
}