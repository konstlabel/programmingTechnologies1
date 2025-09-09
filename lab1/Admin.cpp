#include <iostream>
#include <string>

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
	const std::string& responsibility) : Person(surname, name, patronymic),
										position(position),
										phone(phone),
										responsibility(responsibility) {

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

	std::cout << "The Admin's destructor constructor is called" << std::endl;
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

std::string Admin::getPosition() const {

	return position;
}

std::string Admin::getPhone() const {

	return phone;
}

std::string Admin::getResponsibity() const {

	return responsibility;
}

void Admin::setPosition(const std::string& position) {

	this->position = position;
}

void Admin::setPhone(const std::string & phone) {

	this->phone = phone;
}

void Admin::setResponsibility(const std::string& responsibility) {

	this->responsibility = responsibility;
}

std::string Admin::toString() const {

	return std::string(surname + " " + name + " " + patronymic +
		" | Position: " + position +
		" | Phone: " + phone +
		" | Responsibility: " + responsibility);
}