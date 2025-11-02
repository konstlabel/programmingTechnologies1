#include "ScoreDto.h"

using namespace Scores;
using namespace Vectors;

Vector<std::string> ScoreDto::headers() {

    Vector<std::string> h;

    h.add(new std::string("id"));
    h.add(new std::string("student id"));
    h.add(new std::string("subject id"));
    h.add(new std::string("professor id"));
    h.add(new std::string("score"));

    return h;
}

Vector<std::string> ScoreDto::toPrintable() const {

	Vector<std::string> row;

	row.add(new std::string(std::to_string(id)));
	row.add(new std::string(std::to_string(studentId)));
	row.add(new std::string(std::to_string(subjectId)));
	row.add(new std::string(std::to_string(professorId)));
	row.add(new std::string(std::to_string(score)));

	return row;
}