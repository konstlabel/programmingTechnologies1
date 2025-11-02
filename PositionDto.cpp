#include "PositionDto.h"

using namespace Positions;
using namespace Vectors;

Vector<std::string> PositionDto::headers() {

    Vector<std::string> h;

    h.add(new std::string("id"));
    h.add(new std::string("name"));

    return h;
}

Vector<std::string> PositionDto::toPrintable() const {

	Vector<std::string> row;

	row.add(new std::string(std::to_string(id)));
	row.add(new std::string(name));

	return row;
}