#pragma once

#include "StudentRepository.h"
#include "GroupRepository.h"

#include "Service.h"
#include "Vector.h"
#include "StudentDto.h"

namespace Students {
	class StudentService : public Services::Service {
	private:
		const StudentRepository* studentRepository;
		const Groups::GroupRepository * groupRepository;

		StudentDto* toDto(const Student* Student) const;
	public:
		StudentService(StudentRepository* studentRepository, Groups::GroupRepository* groupRepository);

		StudentDto* findById(int id) const;

		Vectors::Vector<StudentDto> findAll() const;

		Vectors::Vector<StudentDto> findByFirstName(const std::string& firstName) const;

		Vectors::Vector<StudentDto> findByMiddleName(const std::string& middleName) const;

		Vectors::Vector<StudentDto> findByLastName(const std::string& lastName) const;

		Vectors::Vector<StudentDto> findByGroupId(int groupId) const;

		bool createStudent(const StudentDto* studentDto) const;

		bool deleteStudent(int id) const;

		bool updateStudent(const StudentDto* studentDto) const;
	};
}