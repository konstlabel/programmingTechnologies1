#pragma once

#include <string>
#include "Person.h"
#include "Group.h"
#include "Vector.h"

namespace Professors {
	using namespace Persons;
	using namespace Groups;
	using namespace Vectors;

	class Professor : public Person{
		Vector<Group> groups;
		Vector<std::string> subjects;

	public:
		Professor();
		Professor(const std::string& surname,
			const std::string& name,
			const std::string& patronymic,
			const Vector<Group>& groups,
			const Vector<std::string>& subjects);
		Professor(const Professor& other);

		~Professor();

		Professor& operator =(const Professor& other);

		const Vector<Group>& getGroups() const ;
		const Vector<std::string>& getSubjects() const;

		void setGroups(const Vector<Group>& groups);
		void setSubjects(const Vector<std::string>& subjects);

		void addGroup(const Group* group);
		void addSubject(const std::string* subject);

		void deleteGroupByIndex(int index);
		void deleteSubjectByIndex(int index);

		void printGroups() const;
		void printSubjects() const;

		Group* findGroupByIndex(int index);
		int findGroupIndex(Group* group);

		std::string findSubjectByIndex(int index);
		int findSubjectIndex(std::string& subject);

		std::string toString() const override;
	};
}