#pragma once

#include "SpecialityRepository.h"

#include "Service.h"
#include "Vector.h"
#include "SpecialityDto.h"

namespace Specialities {
	class SpecialityService : public Services::Service {
	private:
		const SpecialityRepository* specialityRepository;

		SpecialityDto* toDto(const Speciality* speciality) const;
	public:

		SpecialityService(SpecialityRepository* specialityRepository);

		SpecialityDto* findById(int id) const;

		Vectors::Vector<SpecialityDto> findAll() const;

		Vectors::Vector<SpecialityDto> findByName(const std::string& name) const;

		bool createSpeciality(const SpecialityDto* specialityDto) const;

		bool deleteSpeciality(int id) const;

		bool updateSpeciality(const SpecialityDto* specialityDto) const;
	};
}