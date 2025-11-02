#include "AdminDto.h"

using namespace Admins;
using namespace Vectors;

Vector<std::string> AdminDto::headers() {

    Vector<std::string> h;
    
    h.add(new std::string("id"));
    h.add(new std::string("First Name"));
    h.add(new std::string("Middle Name"));
    h.add(new std::string("Last Name"));
    h.add(new std::string("Phone"));
    h.add(new std::string("Position id"));
    h.add(new std::string("Responsibility id"));
    
    return h;
}

Vector<std::string> AdminDto::toPrintable() const {

	Vector<std::string> row = PersonDto::toPrintable();
	
	row.add(new std::string(std::to_string(positionId)));
	row.add(new std::string(std::to_string(responsibilityId)));
	
	return row;
}