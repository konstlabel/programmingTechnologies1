#pragma once

#include <string>

#include "Group.h"
#include "Admin.h"
#include "Vector.h"
#include "Student.h"
#include "Professor.h"

namespace Universities {
	using namespace Admins;
	using namespace Students;
	using namespace Professors;
	using namespace Groups;
	using namespace Vectors;

	class University {
		Vector<Admin> admins;
		Vector<Student> students;
		Vector<Professor> professors;
		Vector<Group> groups;
		Vector<std::string> specialities;
		Vector<std::string> subjects;
		Vector<std::string> positions;
		Vector<std::string> responsibilities;

	public:
		University();
		University(Vector<Admin>& admins,
			Vector<Student>& students,
			Vector<Professor> professors,
			Vector<Group> groups,
			Vector<std::string> specialities,
			Vector<std::string> subjects,
			Vector<std::string> positions,
			Vector<std::string> responsibilities);
		University(const University& other);

		~University();

		University& operator =(const University& other);

		Vector<Admin>& getAdmins();
		Vector<Student>& getStudents();
		Vector<Professor>& getProfessors();
		Vector<Group>& getGroups();
		Vector<std::string>& getSpecialities();
		Vector<std::string>& getSubjects();
		Vector<std::string>& getPositions();
		Vector<std::string>& getResponsibilities();

		void setAdmins(const Vector<Admin>& admins);
		void setStudents(const Vector<Student>& students);
		void setProfessors(const Vector<Professor>& professors);
		void setGroups(const Vector<Group>& groups);
		void setSpecialities(const Vector<std::string>& specialities);
		void setSubjects(const Vector<std::string>& subjects);
		void setPositions(const Vector<std::string>& positions);
		void setResponsibilities(const Vector<std::string>& responsibilities);

		void print();
		void printAdmins();
		void printStudents();
		void printProfessors();
		void printGroups();
		void printSpecialities();
		void printSubjects();
		void printPositions();
		void printResponsibilities();

		void addAdmin(const Admin& admin);
		void addStudent(const Student& student);
		void addProfessor(const Professor& professor);
		void addGroup(const Group& group);
		void addSpeciality(const std::string& speciality);
		void addSubject(const std::string& subject);
		void addPosition(const std::string& position);
		void addResponsibility(const std::string& responsibility);

		void deleteAdminsByIndex(int index);
		void deleteStudentsByIndex(int index);
		void deleteProfessorsByIndex(int index);
		void deleteGroupsByIndex(int index);
		void deleteSpecialitiesByIndex(int index);
		void deleteSubjectsByIndex(int index);
		void deletePositionsByIndex(int index);
		void deleteResponsibilitiesByIndex(int index);
	};
}