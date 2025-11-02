#pragma once

#include <string>
#include "PersonDto.h"

namespace Students {
	struct StudentDto : public Persons::PersonDto {
		int groupId = 0;

		static Vectors::Vector<std::string> headers();

		Vectors::Vector<std::string> toPrintable() const override;
	};
}