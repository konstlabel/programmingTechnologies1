#pragma once

#include <string>
#include "Student.h"
#include "Vector.h"
#include "Repository.h"

namespace Students {
	class StudentRepository : public Repositories::Repository {
	public:
		StudentRepository(pqxx::connection* conn);

		Student* findById(int id) const;
	
		Vectors::Vector<Student> findAll() const;
		
		Vectors::Vector<Student> findByFirstName(const std::string& firstName) const;
		
		Vectors::Vector<Student> findByMiddleName(const std::string& middleName) const;
		
		Vectors::Vector<Student> findByLastName(const std::string& lastName) const;
		
		Vectors::Vector<Student> findByGroup(Groups::Group* group) const;

		Vectors::Vector<Student> findByPhone(const std::string& phone) const;
		
		void save(Student* student) const;
		
		void deleteByObject(const Student* student) const;
		
		void deleteById(int id) const;
	};
}