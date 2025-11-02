#pragma once

#include <string>
#include "PersonDto.h"

namespace Professors {
	struct ProfessorDto : public Persons::PersonDto {
		int department = 0;

		static Vectors::Vector<std::string> headers();

		Vectors::Vector<std::string> toPrintable() const override;
	};
}