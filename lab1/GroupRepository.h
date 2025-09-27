#pragma once

#include "Group.h"
#include "Vector.h"

using namespace Vectors;

namespace GroupRepositories {
	using namespace Groups;
	
	class GroupRepository {
		Vector<Group> groups;
	public:
		GroupRepository();
		GroupRepository(int capacity, bool ownsObjects);
		GroupRepository(const GroupRepository& other);
		~GroupRepository();

		GroupRepository& operator =(const GroupRepository& other);
		bool operator ==(const GroupRepository& other) const;
		
		int getSize() const;
		int getCapacity() const;
		bool getOwnsObjects() const;
		
		void add(const Group* group);
		
		void deleteByIndex(int index);
		void deleteByGroup(Group* group);
		
		Group* findByIndex(int index);
		int findIndexByPointer(Group* group) const;
		int findIndexByGroup(const Group& group) const;
		
		bool exists(const Group& group) const;
		bool isEmpty() const;
		
		void print() const;
	};
}