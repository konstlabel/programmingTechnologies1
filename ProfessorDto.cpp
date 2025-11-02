#include "ProfessorDto.h"

using namespace Professors;
using namespace Vectors;

Vector<std::string> ProfessorDto::headers() {

    Vector<std::string> h;

    h.add(new std::string("id"));
    h.add(new std::string("First Name"));
    h.add(new std::string("Middle Name"));
    h.add(new std::string("Last Name"));
    h.add(new std::string("Phone"));
    h.add(new std::string("department"));

    return h;
}

Vector<std::string> ProfessorDto::toPrintable() const {

	Vector<std::string> row = PersonDto::toPrintable();

	row.add(new std::string(std::to_string(department)));

	return row;
}