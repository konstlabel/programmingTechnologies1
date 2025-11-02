#pragma once

#include <string>
#include "Vector.h"

namespace Specialities {
	struct SpecialityDto {
		int id = 0;
		std::string name;

		static Vectors::Vector<std::string> headers();

		Vectors::Vector<std::string> toPrintable() const;
	};
}