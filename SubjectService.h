#pragma once

#include "SubjectRepository.h"

#include "Service.h"
#include "Vector.h"
#include "SubjectDto.h"

namespace Subjects {
	class SubjectService : public Services::Service {
	private:
		const SubjectRepository* subjectRepository;

		SubjectDto* toDto(const Subject* subject) const;
	public:

		SubjectService(SubjectRepository* subjectRepository);

		SubjectDto* findById(int id) const;

		Vectors::Vector<SubjectDto> findAll() const;

		Vectors::Vector<SubjectDto> findByName(const std::string& name) const;

		bool createSubject(const SubjectDto* subjectDto) const;

		bool deleteSubject(int id) const;

		bool updateSubject(const SubjectDto* subjectDto) const;
	};
}