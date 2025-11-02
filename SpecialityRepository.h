#pragma once

#include <string>
#include "Speciality.h"
#include "Vector.h"
#include "Repository.h"

namespace Specialities {
	class SpecialityRepository : public Repositories::Repository {
	public:
		SpecialityRepository(pqxx::connection* conn);

		Speciality* findById(int id) const;

		Vectors::Vector<Speciality> findAll() const;
		
		Vectors::Vector<Speciality> findByName(const std::string& name) const;
		
		void save(Speciality* speciality) const;
		
		void deleteByObject(const Speciality* speciality) const;
		
		void deleteById(int id) const;
	};
}