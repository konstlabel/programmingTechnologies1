#pragma once

#include <string>

#include "GroupRepository.h"
#include "AdminRepository.h"
#include "StudentRepository.h"
#include "ProfessorRepository.h"
#include "SpecialityRepository.h"
#include "SubjectRepository.h"
#include "PositionRepository.h"
#include "ResponsibilityRepository.h"

namespace Universities {
	using namespace AdminRepositories;
	using namespace GroupRepositories;
	using namespace StudentRepositories;
	using namespace ProfessorRepositories;
	using namespace SpecialityRepositories;
	using namespace SubjectRepositories;
	using namespace PositionRepositories;
	using namespace ResponsibilityRepositories;

	class University {
		AdminRepository adminRepository;
		GroupRepository groupRepository;
		ProfessorRepository professorRepository;
		StudentRepository studentRepository;
		SpecialityRepository specialityRepository;
		SubjectRepository subjectRepository;
		PositionRepository positionRepository;
		ResponsibilityRepository responsibilityRepository;

		static std::string trim(const std::string& str);
	public:
		University();
		University(AdminRepository adminrepository,
			GroupRepository groupRepository,
			ProfessorRepository professorRepository,
			StudentRepository studentRepository,
			SpecialityRepository specialityRepository,
			SubjectRepository subjectRepository,
			PositionRepository positionRepository,
			ResponsibilityRepository responsibilityRepository);
		University(const University& other);
		~University();

		University& operator =(const University& other);
		bool operator ==(const University& other) const;

		AdminRepository& getAdminRepository();
		GroupRepository& getGroupRepository();
		ProfessorRepository& getProfessorRepository();
		StudentRepository& getStudentRepository();
		SpecialityRepository& getSpecialityRepository();
		SubjectRepository& getSubjectRepository();
		PositionRepository& getPositionRepository();
		ResponsibilityRepository& getResponsibilityRepository();

		void setAdminRepository(const AdminRepository& adminRepository);
		void setGroupRepository(const GroupRepository& groupRepository);
		void setProfessorRepository(const ProfessorRepository& professorRepository);
		void setStudentRepository(const StudentRepository& studentRepository);
		void setSpecialityRepository(const SpecialityRepository& specialityRepository);
		void setSubjectRepository(const SubjectRepository& subjectRepository);
		void setPositionRepository(const PositionRepository& positionRepository);
		void setResponsibilityRepository(const ResponsibilityRepository& responsibilityRepository);

		void print();

		void saveToFile(const std::string& dirPath);
		void loadFromFile(const std::string& dirPath);
	};
}