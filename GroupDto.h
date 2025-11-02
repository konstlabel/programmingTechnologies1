#pragma once

#include <string>
#include "Vector.h"

namespace Groups {
	struct GroupDto {
		int id = 0;
		std::string name;
		int specialityId = 0;
		int course = 0;

		static Vectors::Vector<std::string> headers();

		Vectors::Vector<std::string> toPrintable() const;
	};
}