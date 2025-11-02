#include "SubjectDto.h"

using namespace Subjects;
using namespace Vectors;

Vector<std::string> SubjectDto::headers() {

	Vector<std::string> h;

	h.add(new std::string("id"));
	h.add(new std::string("name"));

	return h;
}

Vector<std::string> SubjectDto::toPrintable() const {

	Vector<std::string> row;

	row.add(new std::string(std::to_string(id)));
	row.add(new std::string(name));

	return row;
}