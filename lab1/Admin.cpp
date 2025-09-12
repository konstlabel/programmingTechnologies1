#include <iostream>
#include <string>
#include <regex>

#include "Admin.h"
#include "Role.h"

using namespace Admins;

Admin::Admin() : Person(), position("unknown"), phone("unknown"), responsibility("unknown") {

	role = Role::Admin;
	std::cout << "The Admin's default constructor is called" << std::endl;
}

Admin::Admin(const std::string& surname,
	const std::string& name,
	const std::string& patronymic,
	const std::string& position,
	const std::string& phone,
	const std::string& responsibility)
	: Person(surname, name, patronymic) {
	
	setPosition(position);
	setPhone(phone);
	setResponsibility(responsibility);
	role = Role::Admin;
	std::cout << "The Admin's parameterized constructor is called" << std::endl;
}

Admin::Admin(const Admin& other) : Person(other.surname, other.name, other.patronymic),
									position(other.position),
									phone(other.phone),
									responsibility(other.responsibility) {

	role = Role::Admin;
	std::cout << "The Admin's copy constructor is called" << std::endl;
}

Admin::~Admin() {

	std::cout << "The Admin's destructor is called" << std::endl;
}

Admin& Admin::operator =(const Admin& other) {

	if (this == &other) return *this;

	surname = other.surname;
	name = other.name;
	patronymic = other.patronymic;
	position = other.position;
	phone = other.phone;
	responsibility = other.responsibility;
	role = other.role;

	return *this;
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

	std::string trimmed = position;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string is not allowed");
	else
		this->position = trimmed;
}

void Admin::setPhone(const std::string & phone) {

	const std::regex phoneTemplate(R"(\+7\d{10,10})");
	if (std::regex_match(phone, phoneTemplate))
		this->phone = phone;
	else
		throw std::invalid_argument("Error! Unknown phone number format");
}

void Admin::setResponsibility(const std::string& responsibility) {

	std::string trimmed = responsibility;
	trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
	trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

	if (trimmed.empty())
		throw std::invalid_argument("Error! Empty string is not allowed");
	else
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

	return surname + " " + name + " " + patronymic +
		" | Position: " + position +
		" | Phone: " + phone +
		" | Responsibility: " + responsibility;
}