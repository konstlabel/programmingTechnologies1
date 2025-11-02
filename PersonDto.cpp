#include "PersonDto.h"

using namespace Persons;
using namespace Vectors;

Vector<std::string> PersonDto::toPrintable() const {

	Vector<std::string> row;
	
	row.add(new std::string(std::to_string(id)));
	row.add(new std::string(firstName));
	row.add(new std::string(middleName));
	row.add(new std::string(lastName));
	row.add(new std::string(phone));
	
	return row;
}