#include "Group.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
using namespace Groups;
using namespace Specialities;


Group::Group() : id(0), name("unknown"), speciality(nullptr), course(1) {

	cout << "Group default constructor called." << endl;
}

Group::Group(int id, const std::string& name, Speciality* speciality, int course) : id(id), name(name), speciality(speciality), course(course) {
	
	cout << "Group all argumetns constructor called." << endl;
}

Group::Group(const Group& other) : id(other.id), name(other.name), speciality(other.speciality), course(other.course) {

	cout << "Group copy constructor called." << endl;
}

Group::~Group() {

	delete speciality;

	cout << "Group destructor called." << endl;
}

Group& Group::operator =(const Group& other) {

	if (this == &other) {
		return *this;
	}

	this->id = other.id;
	this->name = other.name;
	this->speciality = other.speciality;
	this->course = other.course;
	return *this;
}

bool Group::operator ==(const Group& other) const {

	if (this == &other) {
		return true;
	}

	return this->id == other.id &&
		this->name == other.name &&
		this->speciality == other.speciality &&
		this->course == other.course;
}

int Group::getId() const {

	return id;
}

std::string Group::getName() const {

	return name;
}

Speciality* Group::getSpeciality() const {

	return speciality;
}

int Group::getCourse() const {

	return course;
}

void Group::setId(int id) {

	this->id = id;
}

void Group::setName(const std::string& name) {

	this->name = name;
}

void Group::setSpeciality(Speciality* speciality) {

	this->speciality = speciality;
}

void Group::setCourse(int course) {

	this->course = course;
}

std::string Group::toString() const {

	stringstream oss;
	oss << "Group { "
		<< "id: " << id
		<< ", name: " << name
		<< ", speciality: " << speciality->getName()
		<< ", course: " << course
		<< " }";
	return oss.str();
}

Group::Builder& Group::Builder::id(int _id) {

	this->_id = _id;
	return *this;
}

Group::Builder& Group::Builder::name(const std::string& _name) {

	this->_name = _name;
	return *this;
}

Group::Builder& Group::Builder::speciality(Speciality* _speciality) {

	this->_speciality = _speciality;
	return *this;
}

Group::Builder& Group::Builder::course(int _course) {

	this->_course = _course;
	return *this;
}

Group Group::Builder::build() {
	
	return Group(_id, _name, _speciality, _course);
}
