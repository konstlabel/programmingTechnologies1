#pragma once

#include <string>
#include "Group.h"
#include "Vector.h"
#include "Repository.h"

namespace Groups {
	class GroupRepository : public Repositories::Repository {
	public:
		GroupRepository(pqxx::connection* conn);

		Group* findById(int id) const;

		Vectors::Vector<Group> findAll() const;

		Vectors::Vector<Group> findByName(const std::string& name) const;

		Vectors::Vector<Group> findBySpeciality(Specialities::Speciality* speciality) const;

		Vectors::Vector<Group> findByCourse(int course) const;

		void save(Group* group) const;

		void deleteByObject(const Group* group) const;

		void deleteById(int id) const;
	};
}