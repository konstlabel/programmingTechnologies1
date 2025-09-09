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

Vector<Group>& Professor::getGroups() {

	return groups;
}

Vector<std::string>& Professor::getSubjects() {

	return subjects;
}

void Professor::setGroups(const Vector<Group>& groups) {

	this->groups = groups;
}

void Professor::setSubjects(const Vector<std::string>& subjects) {

	this->subjects = subjects;
}

void Professor::addGroup(const Group& group) {

	this->groups.add(&group);
}

void Professor::addSubject(const std::string& subject) {

	this->subjects.add(&subject);
}

void Professor::deleteGroup(int index) {

	if (index < 0 || index >= groups.getSize()) return;

	groups.deleteByIndex(index);
}

void Professor::deleteSubject(int index) {

	if (index < 0 || index >= subjects.getSize()) return;

	subjects.deleteByIndex(index);
}

void Professor::printGroups() const {

	std::cout << "Groups:" << std::endl;
	groups.print();
}

void Professor::printSubjects() const {

	std::cout << "Subjects:" << std::endl;
	subjects.print();
}

std::string Professor::toString() const {
	return std::string(surname + " " + name + " " + patronymic);
}