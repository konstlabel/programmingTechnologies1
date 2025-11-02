#pragma once

#include <string>
#include "Professor.h"
#include "Vector.h"
#include "Repository.h"

namespace Professors {
	class ProfessorRepository : public Repositories::Repository {
	public:
		ProfessorRepository(pqxx::connection* conn);

		Professor* findById(int id) const;
	
		Vectors::Vector<Professor> findAll() const;
		
		Vectors::Vector<Professor> findByFirstName(const std::string& firstName) const;
		
		Vectors::Vector<Professor> findByMiddleName(const std::string& middleName) const;
		
		Vectors::Vector<Professor> findByLastName(const std::string& lastName) const;
		
		Vectors::Vector<Professor> findByPhone(const std::string& phone) const;

		Vectors::Vector<Professor> findByDepartment(int department) const;
		
		void save(Professor* professor) const;
		
		void deleteByObject(const Professor* professor) const;
		
		void deleteById(int id) const;
	};
}