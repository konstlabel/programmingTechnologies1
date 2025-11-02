#pragma once

#include <string>
#include "Vector.h"

namespace Scores {
	struct ScoreDto {
		int id;
		int studentId;
		int subjectId;
		int professorId;
		int score;

		static Vectors::Vector<std::string> headers();

		Vectors::Vector<std::string> toPrintable() const;
	};
}