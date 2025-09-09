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

		Vector<Group>& getGroups();
		Vector<std::string>& getSubjects();

		void setGroups(const Vector<Group>& groups);
		void setSubjects(const Vector<std::string>& subjects);

		void addGroup(const Group& group);
		void addSubject(const std::string& subject);

		void deleteGroup(int index);
		void deleteSubject(int index);

		void printGroups() const;
		void printSubjects() const;

		std::string toString() const override;
	};
}