#pragma once

#include <string>
#include "Vector.h"

namespace Subjects {
	struct SubjectDto {
		int id = 0;
		std::string name;

		static Vectors::Vector<std::string> headers();

		Vectors::Vector<std::string> toPrintable() const;
	};
}