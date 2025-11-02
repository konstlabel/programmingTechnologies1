#pragma once

#include "ProfessorRepository.h"

#include "Service.h"
#include "Vector.h"
#include "ProfessorDto.h"

namespace Professors {
	class ProfessorService : public Services::Service {
	private:
		const ProfessorRepository* professorRepository;

		ProfessorDto* toDto(const Professor* Professor) const;
	public:
		ProfessorService(ProfessorRepository* professorRepository);

		ProfessorDto* findById(int id) const;

		Vectors::Vector<ProfessorDto> findAll() const;

		Vectors::Vector<ProfessorDto> findByFirstName(const std::string& firstName) const;

		Vectors::Vector<ProfessorDto> findByMiddleName(const std::string& middleName) const;

		Vectors::Vector<ProfessorDto> findByLastName(const std::string& lastName) const;

		Vectors::Vector<ProfessorDto> findByDepartment(int gdepartment) const;

		bool createProfessor(const ProfessorDto* professorDto) const;

		bool deleteProfessor(int id) const;

		bool updateProfessor(const ProfessorDto* professorDto) const;
	};
}