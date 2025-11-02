#pragma once

#include <string>
#include "PersonDto.h"
#include "Vector.h"

namespace Admins {
	struct AdminDto : public Persons::PersonDto {
		int positionId = 0;
		int responsibilityId = 0;

		static Vectors::Vector<std::string> headers();

		Vectors::Vector<std::string> toPrintable() const override;
	};	
}