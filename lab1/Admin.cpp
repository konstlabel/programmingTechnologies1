#include <iostream>
#include <sstream>
#include <string>
#include <regex>

#include "Admin.h"
#include "Role.h"

using namespace Admins;

Admin::Admin() : Person(), position("unknown"), phone("unknown"), responsibility("unknown") {

	role = Role::Admin;
	std::cout << "The Admin's default constructor is called" << std::endl;
}

Admin::Admin(int id,
	const std::string& surname,
	const std::string& name,
	const std::string& patronymic,
	const std::string& position,
	const std::string& phone,
	const std::string& responsibility)
	: Person(id, surname, name, patronymic, Role::Admin) {
	
	setPosition(position);
	setPhone(phone);
	setResponsibility(responsibility);
	std::cout << "The Admin's parameterized constructor is called" << std::endl;
}

Admin::Admin(const Admin& other) : Person(other.id, other.surname, other.name, other.patronymic, Role::Admin),
									position(other.position),
									phone(other.phone),
									responsibility(other.responsibility) {

	std::cout << "The Admin's copy constructor is called" << std::endl;
}

Admin::~Admin() {

	std::cout << "The Admin's destructor is called" << std::endl;
}

Admin& Admin::operator =(const Admin& other) {

	if (this == &other) return *this;

	Person::operator=(other);
	position = other.position;
	phone = other.phone;
	responsibility = other.responsibility;

	return *this;
}

bool Admin::operator ==(const Admin& other) const {
	return Person::operator==(other) &&
		position == other.position &&
		phone == other.phone &&
		responsibility == other.responsibility;
}

const std::string& Admin::getPosition() const {

	return position;
}

const std::string& Admin::getPhone() const {

	return phone;
}

const std::string& Admin::getResponsibility() const {

	return responsibility;
}

void Admin::setPosition(const std::string& position) {

	std::string trimmed = trim(position);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string is not allowed");
		
	this->position = trimmed;
}

void Admin::setPhone(const std::string & phone) {

	std::string trimmed = trim(phone);

	const std::regex phoneTemplate(R"(^\+7\d{10}$)");
	if (std::regex_match(trimmed, phoneTemplate))
		this->phone = trimmed;
	else
		throw std::invalid_argument("Error! Unknown phone number format");
}

void Admin::setResponsibility(const std::string& responsibility) {

	std::string trimmed = trim(responsibility);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string is not allowed");
		
	this->responsibility = trimmed;
}


void Admin::clearPosition() {
	
	position = "unknown";
}

void Admin::clearPhone() {

	phone = "unknown";
}

void Admin::clearResponsibility() {

	responsibility = "unknown";
}

std::string Admin::toString() const {

	std::ostringstream oss;
	oss << surname << " " << name << " " << patronymic
		<< " | Position: " << position
		<< " | Phone: " << phone
		<< " | Responsibility: " << responsibility;
	return oss.str();
}