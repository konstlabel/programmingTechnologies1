#pragma once

#include <string>
#include "Responsibility.h"
#include "Vector.h"
#include "Repository.h"

namespace Responsibilities {
	class ResponsibilityRepository : public Repositories::Repository {
	public:
		ResponsibilityRepository(pqxx::connection* conn);

		Responsibility* findById(int id) const;

		Vectors::Vector<Responsibility> findAll() const;

		Vectors::Vector<Responsibility> findByName(const std::string& name) const;

		void save(Responsibility* responsibility) const;

		void deleteByObject(const Responsibility* responsibility) const;
		
		void deleteById(int id) const;
	};
}