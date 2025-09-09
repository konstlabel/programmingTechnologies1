#include <iostream>
#include <string>

#include "University.h"

using namespace Universities;

University::University()
	: admins(16, true),
	students(16, true),
	professors(16, true),
	groups(16, true),
	specialities(16, true),
	subjects(16, true),
	positions(16, true),
	responsibilities(16, true) {

	std::cout << "The University's default constructor is called" << std::endl;
};

University::University(Vector<Admin>& admins,
	Vector<Student>& students,
	Vector<Professor> professors,
	Vector<Group> groups,
	Vector<std::string> specialities,
	Vector<std::string> subjects,
	Vector<std::string> positions,
	Vector<std::string> responsibilities) 
	: admins(admins),
	students(students),
	professors(professors),
	groups(groups),
	specialities(specialities),
	subjects(subjects),
	positions(positions),
	responsibilities(responsibilities) {

	std::cout << "The University's parameterized constructor is called" << std::endl;
}

University::University(const University& other) 
	: admins(other.admins),
	students(other.students),
	professors(other.professors),
	groups(other.groups),
	specialities(other.specialities),
	subjects(other.subjects),
	positions(other.positions),
	responsibilities(other.responsibilities) {

	std::cout << "The University's copy constructor is called" << std::endl;
}

University::~University() {

	std::cout << "The University's destructor is called" << std::endl;
}

University& University::operator =(const University& other) {

	if (this == &other) return *this;

	admins = other.admins;
	students = other.students;
	professors = other.professors;
	groups = other.groups;
	specialities = other.specialities;
	subjects = other.subjects;
	positions = other.positions;
	responsibilities = other.responsibilities;

	return *this;
}

Vector<Admin>& University::getAdmins() {

	return admins;
}

Vector<Student>& University::getStudents() {

	return students;
}

Vector<Professor>& University::getProfessors() {

	return professors;
}

Vector<Group>& University::getGroups() {

	return groups;
}

Vector<std::string>& University::getSpecialities() {

	return specialities;
}

Vector<std::string>& University::getSubjects() {

	return subjects;
}

Vector<std::string>& University::getPositions() {

	return positions;
}

Vector<std::string>& University::getResponsibilities() {

	return responsibilities;
}

void University::setAdmins(const Vector<Admin>& admins) {

	this->admins = admins;
}

void University::setStudents(const Vector<Student>& students) {

	this->students = students;
}

void University::setProfessors(const Vector<Professor>& professors) {

	this->professors = professors;
}

void University::setGroups(const Vector<Group>& groups) {

	this->groups = groups;
}

void University::setSpecialities(const Vector<std::string>& specialities) {

	this->specialities = specialities;
}

void University::setSubjects(const Vector<std::string>& subjects) {

	this->subjects = subjects;
}

void University::setPositions(const Vector<std::string>& positions) {

	this->positions = positions;
}

void University::setResponsibilities(const Vector<std::string>& responsibilities) {

	this->responsibilities = responsibilities;
}

void University::print() {

	this->printAdmins();
	this->printStudents();
	this->printProfessors();
	this->printGroups();
	this->printSpecialities();
	this->printSubjects();
	this->printPositions();
	this->printResponsibilities();
}

void University::printAdmins() {
	
	std::cout << "Admins:" << std::endl;
	admins.print();
}

void University::printStudents() {


	std::cout << "Students:" << std::endl;
	students.print();
}

void University::printProfessors() {


	std::cout << "Professors:" << std::endl;
	professors.print();
}

void University::printGroups() {

	std::cout << "Groups:" << std::endl;
	groups.print();
}

void University::printSpecialities() {

	std::cout << "Specialities:" << std::endl;
	specialities.print();
}

void University::printSubjects() {

	std::cout << "Subjects:" << std::endl;
	subjects.print();
}

void University::printPositions() {

	std::cout << "Positions:" << std::endl;
	positions.print();
}

void University::printResponsibilities() {

	std::cout << "Responsibilities:" << std::endl;
	responsibilities.print();
}

void University::addAdmin(const Admin& admin) {

	admins.add(&admin);
}

void University::addStudent(const Student& student) {

	students.add(&student);
}

void University::addProfessor(const Professor& professor) {

	professors.add(&professor);
}

void University::addGroup(const Group& group) {

	groups.add(&group);
}

void University::addSpeciality(const std::string& speciality) {

	specialities.add(&speciality);
}

void University::addSubject(const std::string& subject) {

	subjects.add(&subject);
}

void University::addPosition(const std::string& position) {

	positions.add(&position);
}

void University::addResponsibility(const std::string& responsibility) {

	responsibilities.add(&responsibility);
}

void University::deleteAdminsByIndex(int index) {

	admins.deleteByIndex(index);
}

void University::deleteStudentsByIndex(int index) {

	students.deleteByIndex(index);
}

void University::deleteProfessorsByIndex(int index) {

	professors.deleteByIndex(index);
}

void University::deleteGroupsByIndex(int index) {

	groups.deleteByIndex(index);
}

void University::deleteSpecialitiesByIndex(int index) {

	specialities.deleteByIndex(index);
}

void University::deleteSubjectsByIndex(int index) {

	subjects.deleteByIndex(index);
}

void University::deletePositionsByIndex(int index) {

	positions.deleteByIndex(index);
}

void University::deleteResponsibilitiesByIndex(int index) {

	responsibilities.deleteByIndex(index);
}