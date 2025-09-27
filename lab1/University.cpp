#include <iostream>
#include <string>

#include "University.h"

using namespace Universities;

University::University() 
	: adminRepository(),
	groupRepository(),
	professorRepository(),
	studentRepository(),
	specialityRepository(),
	subjectRepository(),
	positionRepository(),
	responsibilityRepository() {

	std::cout << "The University's default constructor is called." << std::endl;
}

University::University(AdminRepository adminrepository,
	GroupRepository groupRepository,
	ProfessorRepository professorRepository,
	StudentRepository studentRepository,
	SpecialityRepository specialityRepository,
	SubjectRepository subjectRepository,
	PositionRepository positionRepository,
	ResponsibilityRepository responsibilityRepository)

	: adminRepository(adminrepository),
	groupRepository(groupRepository),
	professorRepository(professorRepository),
	studentRepository(studentRepository),
	specialityRepository(specialityRepository),
	subjectRepository(subjectRepository),
	positionRepository(positionRepository),
	responsibilityRepository(responsibilityRepository) {


	std::cout << "The University's parameterized constructor is called." << std::endl;
}

University::University(const University& other)
	: adminRepository(other.adminRepository),
	groupRepository(other.groupRepository),
	professorRepository(other.professorRepository),
	studentRepository(other.studentRepository),
	specialityRepository(other.specialityRepository),
	subjectRepository(other.subjectRepository),
	positionRepository(other.positionRepository),
	responsibilityRepository(other.responsibilityRepository) {

	std::cout << "The University's copy constructor is called." << std::endl;
}

University::~University() {

	std::cout << "The University's destructor is called." << std::endl;
}

University& University::operator =(const University& other) {

	if (this == &other) return *this;

 	adminRepository = other.adminRepository;
	groupRepository = other.groupRepository;
	professorRepository = other.professorRepository;
	studentRepository = other.studentRepository;
	specialityRepository = other.specialityRepository;
	subjectRepository = other.subjectRepository;
	positionRepository = other.positionRepository;
	responsibilityRepository = other.responsibilityRepository;
	
	return *this;
}

bool University::operator ==(const University& other) const {
	return adminRepository == other.adminRepository &&
		groupRepository == other.groupRepository &&
		professorRepository == other.professorRepository &&
		studentRepository == other.studentRepository &&
		specialityRepository == other.specialityRepository &&
		subjectRepository == other.subjectRepository &&
		positionRepository == other.positionRepository &&
		responsibilityRepository == other.responsibilityRepository;
}

AdminRepository& University::getAdminRepository() {

	return adminRepository;
}

GroupRepository& University::getGroupRepository() {

	return groupRepository;
}

ProfessorRepository& University::getProfessorRepository() {

	return professorRepository;
}

StudentRepository& University::getStudentRepository() {

	return studentRepository;
}

SpecialityRepository& University::getSpecialityRepository() {

	return specialityRepository;
}

SubjectRepository& University::getSubjectRepository() {

	return subjectRepository;
}

PositionRepository& University::getPositionRepository() {

	return positionRepository;
}

ResponsibilityRepository& University::getResponsibilityRepository() {

	return responsibilityRepository;
}

void University::setAdminRepository(const AdminRepository& adminRepository) {

	this->adminRepository = adminRepository;
}

void University::setGroupRepository(const GroupRepository& groupRepository) {

	this->groupRepository = groupRepository;
}

void University::setProfessorRepository(const ProfessorRepository& professorRepository) {

	this->professorRepository = professorRepository;
}

void University::setStudentRepository(const StudentRepository& studentRepository) {

	this->studentRepository = studentRepository;
}

void University::setSpecialityRepository(const SpecialityRepository& specialityRepository) {

	this->specialityRepository = specialityRepository;
}

void University::setSubjectRepository(const SubjectRepository& subjectRepository) {

	this->subjectRepository = subjectRepository;
}

void University::setPositionRepository(const PositionRepository& positionRepository) {

	this->positionRepository = positionRepository;
}

void University::setResponsibilityRepository(const ResponsibilityRepository& responsibilityRepository) {

	this->responsibilityRepository = responsibilityRepository;
}

void University::print() {
	std::cout << "University:" << std::endl;
	adminRepository.print();
	groupRepository.print();
	professorRepository.print();
	studentRepository.print();
	specialityRepository.print();
	subjectRepository.print();
	positionRepository.print();
	responsibilityRepository.print();
}

void University::saveToFile(const std::string& dirPath) {


}

void University::loadFromFile(const std::string& dirPath) {


}