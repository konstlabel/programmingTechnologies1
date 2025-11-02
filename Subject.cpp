#include "Subject.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace Subjects;

Subject::Subject() : id(0), name("unknown") {

	cout << "Subject default constructor called." << endl;
}

Subject::Subject(int id, const std::string& name) : id(id), name(name) {

	cout << "Subject all argumetns constructor called." << endl;
}

Subject::Subject(const Subject& other) : id(other.id), name(other.name) {

	cout << "Subject copy constructor called." << endl;
}

Subject::~Subject() {

	cout << "Subject destructor called." << endl;
}

Subject& Subject::operator =(const Subject& other) {

	if (this == &other) {
		return *this;
	}

	this->id = other.id;
	this->name = other.name;
	return *this;
}

bool Subject::operator ==(const Subject& other) const {

	if (this == &other) {
		return true;
	}

	return this->id == other.id &&
		this->name == other.name;
}

int Subject::getId() const {

	return id;
}

std::string Subject::getName() const {

	return name;
}

void Subject::setId(int id) {

	this->id = id;
}

void Subject::setName(const std::string& name) {

	this->name = name;
}

std::string Subject::toString() const {

	std::ostringstream oss;
	oss << "Subject {"
		<< "id: " << id
		<< ", name: " << name
		<< "}";
	return oss.str();
}

Subject::Builder& Subject::Builder::id(int _id) {

	this->_id = _id;
	return *this;
}

Subject::Builder& Subject::Builder::name(const std::string& _name) {

	this->_name = _name;
	return *this;
}

Subject Subject::Builder::build() {

	return Subject(this->_id, this->_name);
}