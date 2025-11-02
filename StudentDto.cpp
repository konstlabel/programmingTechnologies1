#include "StudentDto.h"

using namespace Students;
using namespace Vectors;

Vector<std::string> StudentDto::headers() {

    Vector<std::string> h;

    h.add(new std::string("id"));
    h.add(new std::string("First Name"));
    h.add(new std::string("Middle Name"));
    h.add(new std::string("Last Name"));
    h.add(new std::string("Phone"));
    h.add(new std::string("group id"));

    return h;
}

Vector<std::string> StudentDto::toPrintable() const {

	Vector<std::string> row = PersonDto::toPrintable();

	row.add(new std::string(std::to_string(groupId)));

	return row;
}