#pragma once

#include <pqxx/pqxx>

#include "AdminService.h"
#include "GroupService.h"
#include "PositionService.h"
#include "ProfessorService.h"
#include "ResponsibilityService.h"
#include "ScoreService.h"
#include "SpecialityService.h"
#include "StudentService.h"
#include "SubjectService.h"

namespace Universities {
	using namespace Admins;
	using namespace Groups;
	using namespace Positions;
	using namespace Professors;
	using namespace Responsibilities;
	using namespace Scores;
	using namespace Specialities;
	using namespace Students;
	using namespace Subjects;

	class University {
		const Admins::AdminService* _adminService;
		const Groups::GroupService* _groupService;
		const Positions::PositionService* _positionService;
		const Professors::ProfessorService* _professorService;
		const Responsibilities::ResponsibilityService* _responsibilityService;
		const Scores::ScoreService* _scoreService;
		const Specialities::SpecialityService* _specialityService;
		const Students::StudentService* _studentService;
		const Subjects::SubjectService* _subjectService;

		const Admins::AdminRepository* _adminRepository;
		const Groups::GroupRepository* _groupRepository;
		const Positions::PositionRepository* _positionRepository;
		const Professors::ProfessorRepository* _professorRepository;
		const Responsibilities::ResponsibilityRepository* _responsibilityRepository;
		const Scores::ScoreRepository* _scoreRepository;
		const Specialities::SpecialityRepository* _specialityRepository;
		const Students::StudentRepository* _studentRepository;
		const Subjects::SubjectRepository* _subjectRepository;

		Vectors::Vector<Admins::Admin> _admins;
		Vectors::Vector<Groups::Group> _groups;
		Vectors::Vector<Positions::Position> _positions;
		Vectors::Vector<Professors::Professor> _professors;
		Vectors::Vector<Responsibilities::Responsibility> _responsibilities;
		Vectors::Vector<Scores::Score> _scores;
		Vectors::Vector<Specialities::Speciality> _specialities;
		Vectors::Vector<Students::Student> _students;
		Vectors::Vector<Subjects::Subject> _subjects;

		Vectors::Vector<Admins::AdminDto> _adminDtos;
		Vectors::Vector<Groups::GroupDto> _groupDtos;
		Vectors::Vector<Positions::PositionDto> _positionDtos;
		Vectors::Vector<Professors::ProfessorDto> _professorDtos;
		Vectors::Vector<Responsibilities::ResponsibilityDto> _responsibilityDtos;
		Vectors::Vector<Scores::ScoreDto> _scoreDtos;
		Vectors::Vector<Specialities::SpecialityDto> _specialityDtos;
		Vectors::Vector<Students::StudentDto> _studentDtos;
		Vectors::Vector<Subjects::SubjectDto> _subjectDtos;
	public:

		University(pqxx::connection* conn);

		~University();

		const Admins::AdminService* adminService() const;
		const Groups::GroupService* groupService() const;
		const Positions::PositionService* positionService() const;
		const Professors::ProfessorService* professorService() const;
		const Responsibilities::ResponsibilityService* responsibilityService() const;
		const Scores::ScoreService* scoreService() const;
		const Specialities::SpecialityService* specialityService() const;
		const Students::StudentService* studentService() const;
		const Subjects::SubjectService* subjectService() const;

		const Vectors::Vector<Admins::Admin>& admins() const;
		const Vectors::Vector<Groups::Group>& groups() const;
		const Vectors::Vector<Positions::Position>& positions() const;
		const Vectors::Vector<Professors::Professor>& professors() const;
		const Vectors::Vector<Responsibilities::Responsibility>& responsibilities() const;
		const Vectors::Vector<Scores::Score>& scores() const;
		const Vectors::Vector<Specialities::Speciality>& specialities() const;
		const Vectors::Vector<Students::Student>& students() const;
		const Vectors::Vector<Subjects::Subject>& subjects() const;

		const Vectors::Vector<Admins::AdminDto>& adminDtos() const;
		const Vectors::Vector<Groups::GroupDto>& groupDtos() const;
		const Vectors::Vector<Positions::PositionDto>& positionDtos() const;
		const Vectors::Vector<Professors::ProfessorDto>& professorDtos() const;
		const Vectors::Vector<Responsibilities::ResponsibilityDto>& responsibilityDtos() const;
		const Vectors::Vector<Scores::ScoreDto>& scoreDtos() const;
		const Vectors::Vector<Specialities::SpecialityDto>& specialityDtos() const;
		const Vectors::Vector<Students::StudentDto>& studentDtos() const;
		const Vectors::Vector<Subjects::SubjectDto>& subjectDtos() const;

		void admins(const Vectors::Vector<Admins::Admin>& admins);
		void groups(const Vectors::Vector<Groups::Group>& groups);
		void positions(const Vectors::Vector<Positions::Position>& positions);
		void professors(const Vectors::Vector<Professors::Professor>& professors);
		void responsibilities(const Vectors::Vector<Responsibilities::Responsibility>& responsibilities);
		void scores(const Vectors::Vector<Scores::Score>& scores);
		void specialities(const Vectors::Vector<Specialities::Speciality>& specialities);
		void students(const Vectors::Vector<Students::Student>& students);
		void subjects(const Vectors::Vector<Subjects::Subject>& subjects);

		void adminDtos(const Vectors::Vector<Admins::AdminDto>& adminDtos);
		void groupDtos(const Vectors::Vector<Groups::GroupDto>& groupDtos);
		void positionDtos(const Vectors::Vector<Positions::PositionDto>& positionDtos);
		void professorDtos(const Vectors::Vector<Professors::ProfessorDto>& professorDtos);
		void responsibilityDtos(const Vectors::Vector<Responsibilities::ResponsibilityDto>& responsibilityDtos);
		void scoreDtos(const Vectors::Vector<Scores::ScoreDto>& scoreDtos);
		void specialityDtos(const Vectors::Vector<Specialities::SpecialityDto>& specialityDtos);
		void studentDtos(const Vectors::Vector<Students::StudentDto>& studentDtos);
		void subjectDtos(const Vectors::Vector<Subjects::SubjectDto>& subjectDtos);
	};
}