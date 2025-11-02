#pragma once

#include <string>
#include "Subject.h"
#include "Vector.h"
#include "Repository.h"

namespace Subjects {
	class SubjectRepository : public Repositories::Repository {
	public:
		SubjectRepository(pqxx::connection* conn);

		Subject* findById(int id) const;
	
		Vectors::Vector<Subject> findAll() const;
		
		Vectors::Vector<Subject> findByName(const std::string& name) const;
		
		void save(Subject* subject) const;
		
		void deleteByObject(const Subject* subject) const;
		
		void deleteById(int id) const;
	};
}