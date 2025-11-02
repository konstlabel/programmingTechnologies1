#include "Position.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace Positions;

Position::Position() : id(0), name("unknown") {
	
	std::cout << "Position default constructor called." << std::endl;
}

Position::Position(int id, const std::string& name) : id(id), name(name) {

	std::cout << "Position all argumetns constructor called." << std::endl;
}

Position::Position(const Position& other) : id(other.id), name(other.name) {

	std::cout << "Position copy constructor called." << std::endl;
}

Position::~Position() {

	std::cout << "Position destructor called." << std::endl;
}

Position& Position::operator =(const Position& other) {

	if (this == &other)
		return *this;

	this->id = other.id;
	this->name = other.name;
	return *this;
}

bool Position::operator ==(const Position& other) const {

	if (this == &other)
		return true;

	return this->id == other.id &&
		this->name == other.name;
}

int Position::getId() const {

	return id;
}

std::string Position::getName() const {

	return name;
}

void Position::setId(int id) {

	this->id = id;
}

void Position::setName(const std::string& name) {

	this->name = name;
}

std::string Position::toString() const {

	std::ostringstream oss;
	oss << "Position {"
		<< "id: " << id
		<< ", name: " << name
		<< "}";
	return oss.str();
}

Position::Builder& Position::Builder::id(int _id) {

	this->_id = _id;
	return *this;
}

Position::Builder& Position::Builder::name(const std::string& _name) {

	this->_name = _name;
	return *this;
}

Position Position::Builder::build() {

	return Position(this->_id, this->_name);
}