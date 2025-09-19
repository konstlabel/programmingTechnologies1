#include <iostream>
#include <string>

#include "Professor.h"
#include "Role.h"

using namespace Professors;

Professor::Professor() : Person(), groups(8, false), subjects(8, false) {
	
	this->role = Role::Professor;
	std::cout << "The Professor's default constructor has been called." << std::endl;
}

Professor::Professor(int id,
	const std::string& surname,
	const std::string& name,
	const std::string& patronymic,
	const Vector<int>& groupsIds,
	const Vector<std::string>& subjects) 
	: Person(id, surname, name, patronymic, Role::Professor), groups(groupsIds), subjects(subjects) {
	
	std::cout << "The Professor's parameterized constructor has been called." << std::endl;
}

Professor::Professor(const Professor& other) 
	: Person(other), groups(other.groups), subjects(other.subjects) {
	
	std::cout << "The Professor's copy constructor has been called." << std::endl;
}

Professor::~Professor() {

	std::cout << "The Professor's destructor has been called." << std::endl;
}

Professor& Professor::operator =(const Professor& other) {

	if (this == &other) return *this;
	
	Person::operator=(other);
	groups = other.groups;
	subjects = other.subjects;
	role = Role::Professor;

	return *this;
}

const Vector<int>& Professor::getGroupsIds() const {

	return groups;
}

const Vector<std::string>& Professor::getSubjects() const {

	return subjects;
}

void Professor::setGroups(const Vector<int>& groupsIds) {

	this->groups = groupsIds;
}

void Professor::setSubjects(const Vector<std::string>& subjects) {

	this->subjects = subjects;
}

void Professor::addGroup(int group) {

	try {
		groups.add(group);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error adding group: " << e.what() << std::endl;
	}
}

void Professor::addSubject(const std::string& subject) {

	try {
		subjects.add(subject);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error adding subject: " << e.what() << std::endl;
	}
}

void Professor::deleteGroupByIndex(int index) {

	try {
		groups.deleteByIndex(index);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error deleting group by index: " << e.what() << std::endl;
	}
}

void Professor::deleteGroupById(int groupId) {

	try {
		groups.deleteByObject(groupId);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error deleting group by ID: " << e.what() << std::endl;
	}
}

void Professor::deleteSubjectByIndex(int index) {

	try {
		subjects.deleteByIndex(index);
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Error deleting subject by index: " << e.what() << std::endl;
	}
}

void Professor::deleteSubjectByName(const std::string& subject) {

	try {
		subjects.deleteByObject(subject);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error deleting subject by name: " << e.what() << std::endl;
	}
}

int Professor::findGroupByIndex(int index) {

	try {
		int* group = groups.getByIndex(index);
		return *group;
	}
	catch (const std::out_of_range&) {
		return -1;
	}
}

int Professor::findGroupIdIndex(int groupId) {

	try {
		return groups.getIndexByObject(groupId);
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

std::string Professor::findSubjectByIndex(int index) {

	try {
		std::string* subject = subjects.getByIndex(index);
		return *subject;
	}
	catch (const std::out_of_range&) {
		return "";
	}
}

int Professor::findSubjectIndex(const std::string& subject) {

	try {
		return subjects.getIndexByObject(subject);
	}
	catch (const std::invalid_argument&) {
		return -1;
	}
}

bool Professor::groupExists(int groupId) const {

	return groups.exists(groupId);
}

bool Professor::subjectExists(const std::string& subject) const {

	return subjects.exists(subject);
}

bool Professor::isGroupsEmpty() const {

	return groups.isEmpty();
}

bool Professor::isSubjectsEmpty() const {

	return subjects.isEmpty();
}

int Professor::getGroupsSize() const {

	return groups.getSize();
}

int Professor::getSubjectsSize() const {

	return subjects.getSize();
}

void Professor::printGroupsIds() const {

	std::cout << "Groups IDs for Professor " << this->toString() << " :" << std::endl;
	groups.print();
}

void Professor::printSubjects() const {

	std::cout << "Subjects for Professor " << this->toString() << " :" << std::endl;
	subjects.print();
}

std::string Professor::toString() const {
	return surname + " " + name + " " + patronymic;
}