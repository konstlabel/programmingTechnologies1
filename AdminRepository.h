#pragma once

#include <string>
#include "Admin.h"
#include "Vector.h"
#include "Repository.h"

namespace Admins {
	class AdminRepository : public Repositories::Repository {
	public:
		AdminRepository(pqxx::connection* conn);

		Admin* findById(int id) const;

		Vectors::Vector<Admin> findAll() const;

		Vectors::Vector<Admin> findByFirstName(const std::string& firstName) const;

		Vectors::Vector<Admin> findByMiddleName(const std::string& middleName) const;

		Vectors::Vector<Admin> findByLastName(const std::string& lastName) const;

		Vectors::Vector<Admin> findByPosition(Positions::Position* position) const;

		Vectors::Vector<Admin> findByResponsibility(Responsibilities::Responsibility* responsibility) const;

		void save(Admin* admin) const;

		void deleteByObject(const Admin* admin) const;
		
		void deleteById(int id) const;
	};
}