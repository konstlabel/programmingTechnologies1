#pragma once

#include <string>
#include "Vector.h"

namespace Persons {
	struct PersonDto {
		int id = 0;
		std::string firstName;
		std::string middleName;
		std::string lastName;
		std::string phone;

		virtual Vectors::Vector<std::string> toPrintable() const;
	};
}