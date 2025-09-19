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
		Vector<int> groups;
		Vector<std::string> subjects;

	public:
		Professor();
		Professor(int id,
			const std::string& surname,
			const std::string& name,
			const std::string& patronymic,
			const Vector<int>& groupsIds,
			const Vector<std::string>& subjects);
		Professor(const Professor& other);

		~Professor();

		Professor& operator =(const Professor& other);

		const Vector<int>& getGroupsIds() const ;
		const Vector<std::string>& getSubjects() const;

		void setGroups(const Vector<int>& groupsIds);
		void setSubjects(const Vector<std::string>& subjects);

		void addGroup(int group);
		void addSubject(const std::string& subject);

		void deleteGroupByIndex(int index);
		void deleteGroupById(int groupId);

		void deleteSubjectByIndex(int index);
		void deleteSubjectByName(const std::string& subject);

		int findGroupByIndex(int index);
		int findGroupIdIndex(int groupId);
		std::string findSubjectByIndex(int index);
		int findSubjectIndex(const std::string& subject);

		bool groupExists(int groupId) const;
		bool subjectExists(const std::string& subject) const;

		bool isGroupsEmpty() const;
		bool isSubjectsEmpty() const;

		int getGroupsSize() const;
		int getSubjectsSize() const;

		void printGroupsIds() const;
		void printSubjects() const;

		std::string toString() const override;
	};
}