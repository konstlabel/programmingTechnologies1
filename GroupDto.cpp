#include "GroupDto.h"

using namespace Groups;
using namespace Vectors;


Vector<std::string> GroupDto::headers() {

    Vector<std::string> h;
    
	h.add(new std::string("id"));
    h.add(new std::string("name"));
    h.add(new std::string("speciality id"));
    h.add(new std::string("course"));

    return h;
}

Vector<std::string> GroupDto::toPrintable() const {

	Vector<std::string> row;
	
	row.add(new std::string(std::to_string(id)));
	row.add(new std::string(name));
	row.add(new std::string(std::to_string(specialityId)));
	row.add(new std::string(std::to_string(course)));

	return row;
}
