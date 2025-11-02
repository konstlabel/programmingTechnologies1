#pragma once

#include <pqxx/pqxx>

#include "University.h"

using namespace Admins;
using namespace Groups;
using namespace Positions;
using namespace Professors;
using namespace Responsibilities;
using namespace Scores;
using namespace Specialities;
using namespace Students;
using namespace Subjects;
using namespace Vectors;
using namespace Universities;

University::University(pqxx::connection* conn) {

	_adminRepository = new AdminRepository(conn);
	_groupRepository = new GroupRepository(conn);
	_positionRepository = new PositionRepository(conn);
	_professorRepository = new ProfessorRepository(conn);
	_responsibilityRepository = new ResponsibilityRepository(conn);
	_scoreRepository = new ScoreRepository(conn);
	_specialityRepository = new SpecialityRepository(conn);
	_studentRepository = new StudentRepository(conn);
	_subjectRepository = new SubjectRepository(conn);

	_adminService = new AdminService(const_cast<AdminRepository*>(_adminRepository), const_cast<PositionRepository*>(_positionRepository), const_cast<ResponsibilityRepository*>(_responsibilityRepository));
	_groupService = new GroupService(const_cast<GroupRepository*>(_groupRepository), const_cast<SpecialityRepository*>(_specialityRepository));
	_positionService = new PositionService(const_cast<PositionRepository*>(_positionRepository));
	_professorService = new ProfessorService(const_cast<ProfessorRepository*>(_professorRepository));
	_responsibilityService = new ResponsibilityService(const_cast<ResponsibilityRepository*>(_responsibilityRepository));
	_scoreService = new ScoreService(const_cast<ScoreRepository*>(_scoreRepository), const_cast<StudentRepository*>(_studentRepository), const_cast<SubjectRepository*>(_subjectRepository), const_cast<ProfessorRepository*>(_professorRepository));
	_specialityService = new SpecialityService(const_cast<SpecialityRepository*>(_specialityRepository));
	_studentService = new StudentService(const_cast<StudentRepository*>(_studentRepository), const_cast<GroupRepository*>(_groupRepository));
	_subjectService = new SubjectService(const_cast<SubjectRepository*>(_subjectRepository));
}

University::~University() {

	delete _adminRepository;
	delete _groupRepository;
	delete _positionRepository;
	delete _professorRepository;
	delete _responsibilityRepository;
	delete _scoreRepository;
	delete _specialityRepository;
	delete _studentRepository;
	delete _subjectRepository;

	delete _adminService;
	delete _groupService;
	delete _positionService;
	delete _professorService;
	delete _responsibilityService;
	delete _scoreService;
	delete _specialityService;
	delete _studentService;
	delete _subjectService;
}

const Admins::AdminService* University::adminService() const {

	return _adminService;
}

const Groups::GroupService* University::groupService() const {

	return _groupService;
}

const Positions::PositionService* University::positionService() const {

	return _positionService;
}

const Professors::ProfessorService* University::professorService() const {

	return _professorService;
}

const Responsibilities::ResponsibilityService* University::responsibilityService() const {

	return _responsibilityService;
}

const Scores::ScoreService* University::scoreService() const {

	return _scoreService;
}

const Specialities::SpecialityService* University::specialityService() const {

	return _specialityService;
}

const Students::StudentService* University::studentService() const {

	return _studentService;
}

const Subjects::SubjectService* University::subjectService() const {

	return _subjectService;
}

const Vectors::Vector<Admins::Admin>& University::admins() const {

	return _admins;
}

const Vectors::Vector<Groups::Group>& University::groups() const {

	return _groups;
}

const Vectors::Vector<Positions::Position>& University::positions() const {

	return _positions;
}

const Vectors::Vector<Professors::Professor>& University::professors() const {

	return _professors;
}

const Vectors::Vector<Responsibilities::Responsibility>& University::responsibilities() const {

	return _responsibilities;
}

const Vectors::Vector<Scores::Score>& University::scores() const {

	return _scores;
}

const Vectors::Vector<Specialities::Speciality>& University::specialities() const {

	return _specialities;
}

const Vectors::Vector<Students::Student>& University::students() const {

	return _students;
}

const Vectors::Vector<Subjects::Subject>& University::subjects() const {

	return _subjects;
}

const Vectors::Vector<Admins::AdminDto>& University::adminDtos() const {

	return _adminDtos;
}

const Vectors::Vector<Groups::GroupDto>& University::groupDtos() const {

	return _groupDtos;
}

const Vectors::Vector<Positions::PositionDto>& University::positionDtos() const {

	return _positionDtos;
}

const Vectors::Vector<Professors::ProfessorDto>& University::professorDtos() const {

	return _professorDtos;
}

const Vectors::Vector<Responsibilities::ResponsibilityDto>& University::responsibilityDtos() const {

	return _responsibilityDtos;
}

const Vectors::Vector<Scores::ScoreDto>& University::scoreDtos() const {

	return _scoreDtos;
}

const Vectors::Vector<Specialities::SpecialityDto>& University::specialityDtos() const {

	return _specialityDtos;
}

const Vectors::Vector<Students::StudentDto>& University::studentDtos() const {

	return _studentDtos;
}

const Vectors::Vector<Subjects::SubjectDto>& University::subjectDtos() const {

	return _subjectDtos;
}

void University::admins(const Vectors::Vector<Admins::Admin>& admins) {

	_admins = admins;
}

void University::groups(const Vectors::Vector<Groups::Group>& groups) {

	_groups = groups;
}

void University::positions(const Vectors::Vector<Positions::Position>& positions) {

	_positions = positions;
}

void University::professors(const Vectors::Vector<Professors::Professor>& professors) {

	_professors = professors;
}

void University::responsibilities(const Vectors::Vector<Responsibilities::Responsibility>& responsibilities) {

	_responsibilities = responsibilities;
}

void University::scores(const Vectors::Vector<Scores::Score>& scores) {

	_scores = scores;
}

void University::specialities(const Vectors::Vector<Specialities::Speciality>& specialities) {

	_specialities = specialities;
}

void University::students(const Vectors::Vector<Students::Student>& students) {

	_students = students;
}

void University::subjects(const Vectors::Vector<Subjects::Subject>& subjects) {

	_subjects = subjects;
}

void University::adminDtos(const Vectors::Vector<Admins::AdminDto>& adminDtos) {

	_adminDtos = adminDtos;
}

void University::groupDtos(const Vectors::Vector<Groups::GroupDto>& groupDtos) {

	_groupDtos = groupDtos;
}

void University::positionDtos(const Vectors::Vector<Positions::PositionDto>& positionDtos) {

	_positionDtos = positionDtos;
}

void University::professorDtos(const Vectors::Vector<Professors::ProfessorDto>& professorDtos) {

	_professorDtos = professorDtos;
}

void University::responsibilityDtos(const Vectors::Vector<Responsibilities::ResponsibilityDto>& responsibilityDtos) {

	_responsibilityDtos = responsibilityDtos;
}

void University::scoreDtos(const Vectors::Vector<Scores::ScoreDto>& scoreDtos) {

	_scoreDtos = scoreDtos;
}

void University::specialityDtos(const Vectors::Vector<Specialities::SpecialityDto>& specialityDtos) {

	_specialityDtos = specialityDtos;
}

void University::studentDtos(const Vectors::Vector<Students::StudentDto>& studentDtos) {

	_studentDtos = studentDtos;
}

void University::subjectDtos(const Vectors::Vector<Subjects::SubjectDto>& subjectDtos) {

	_subjectDtos = subjectDtos;
}