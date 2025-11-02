#pragma once

#include "ResponsibilityRepository.h"

#include "Service.h"
#include "Vector.h"
#include "ResponsibilityDto.h"

namespace Responsibilities {
	class ResponsibilityService : public Services::Service {
	private:
		const ResponsibilityRepository* responsibilityRepository;

		ResponsibilityDto* toDto(const Responsibility* responsibility) const;
	public:

		ResponsibilityService(ResponsibilityRepository* responsibilityRepository);

		ResponsibilityDto* findById(int id) const;

		Vectors::Vector<ResponsibilityDto> findAll() const;

		Vectors::Vector<ResponsibilityDto> findByName(const std::string& name) const;

		bool createResponsibility(const ResponsibilityDto* responsibilityDto) const;

		bool deleteResponsibility(int id) const;

		bool updateResponsibility(const ResponsibilityDto* responsibilityDto) const;
	};
}