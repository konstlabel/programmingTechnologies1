#include <iostream>
#include <string>

#include "Professor.h"
#include "Role.h"

using namespace Professors;

Professor::Professor() : Person(), groups(8, false), subjects(4, false) {

	role = Role::Professor;
	std::cout << "The Professor's default constructor is called " << std::endl;
}

Professor::Professor(const std::string& surname,
	const std::string& name,
	const std::string& patronymic,
	const Vector<Group>& groups,
	const Vector<std::string>& subjects) 
	: Person(surname, name, patronymic), groups(groups), subjects(subjects) {

	role = Role::Professor;
	std::cout << "The Professor's parameterized constructor is called " << std::endl;
}

Professor::Professor(const Professor& other) 
					: Person(other.surname, other.name, other.patronymic),
					  groups(other.groups), subjects(other.subjects) {

	role = Role::Professor;
	std::cout << "The Professor's copy constructor is called " << std::endl;
}

Professor::~Professor() {

	std::cout << "The Professor's destructor is called " << std::endl;
}

Professor& Professor::operator =(const Professor& other) {

	if (this == &other) return *this;

	surname = other.surname;
	name = other.name;
	patronymic = other.patronymic;
	groups = other.groups;
	subjects = other.subjects;
	role = other.role;

	return *this;
}

const Vector<Group>& Professor::getGroups() const {

	return groups;
}

const Vector<std::string>& Professor::getSubjects() const {

	return subjects;
}

void Professor::setGroups(const Vector<Group>& groups) {

	this->groups = groups;
}

void Professor::setSubjects(const Vector<std::string>& subjects) {

	this->subjects = subjects;
}

void Professor::addGroup(const Group* group) {

	try {
		this->groups.add(group);
	}
	catch (std::invalid_argument& e) {
		throw e;
	}
}

void Professor::addSubject(const std::string* subject) {

	try {
		this->subjects.add(subject);
	}
	catch (std::invalid_argument& e) {
		throw e;
	}
}

void Professor::deleteGroupByIndex(int index) {

	try {
		groups.deleteByIndex(index);
	}
	catch (std::out_of_range& e) {
		 throw e;
	}
}

void Professor::deleteSubjectByIndex(int index) {

	try {
		subjects.deleteByIndex(index);
	}
	catch (std::out_of_range& e) {
		throw e;
	}
}

void Professor::printGroups() const {

	std::cout << "Groups:";
	if (groups.getSize() == 0)
		std::cout << " No groups" << std::endl;
	else {
		std::cout << std::endl;
		groups.print();
	}
}

void Professor::printSubjects() const {

	std::cout << "Subjects:";
		if (subjects.getSize() == 0)
			std::cout << " No subjects" << std::endl;
		else {
			std::cout << std::endl;
			subjects.print();
		}
}

Group* Professor::findGroupByIndex(int index) {

	try {
		return groups.getByIndex(index);
	}
	catch (const std::out_of_range&) {
		return nullptr;
	}
}

int Professor::findGroupIndex(Group* group) {

	return groups.getIndex(group);
}

std::string Professor::findSubjectByIndex(int index) {

	try {
		return *(subjects.getByIndex(index));
	}
	catch (const std::out_of_range&) {
		return "";
	}
}

int Professor::findSubjectIndex(std::string& subject) {

	return subjects.getIndex(&subject);
}

std::string Professor::toString() const {
	return surname + " " + name + " " + patronymic;
}