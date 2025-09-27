#include <iostream>
#include <string>
#include "Person.h"

using namespace Persons;

std::string Person::trim(const std::string& str) {
    std::string trimmed = str;
    trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
    trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);
    return trimmed;
}

Person::Person()
    : id(-1), surname("unknown"), name("unknown"), patronymic("unknown"), role(Role::Unknown) {

    std::cout << "The Person's default constructor is called" << std::endl;
}

Person::Person(int id,
    const std::string& surname,
    const std::string& name,
    const std::string& patronymic, Role role) : id(id) {

    setSurname(surname);
    setName(name);
    setPatronymic(patronymic);
    setRole(role);
    std::cout << "The Person's parameterized constructor is called" << std::endl;
}

Person::Person(const Person& other)
    : id(other.id), surname(other.surname), name(other.name), patronymic(other.patronymic), role(other.role) {

    std::cout << "The Person's copy constructor is called" << std::endl;
}

Person::~Person() {

    std::cout << "The Person's destructor is called" << std::endl;
}

Person& Person::operator=(const Person& other) {

    if (this == &other) return *this;

    id = other.id;
    surname = other.surname;
    name = other.name;
    patronymic = other.patronymic;
	role = other.role;

    return *this;
}

bool Person::operator==(const Person& other) const {
    return id == other.id &&
           surname == other.surname &&
           name == other.name &&
           patronymic == other.patronymic &&
           role == other.role;
}

int Person::getId() const {

    return id;
}

const std::string& Person::getSurname() const {

    return surname;
}

const std::string& Person::getName() const {

    return name;
}

const std::string& Person::getPatronymic() const {

    return patronymic;
}

const Role& Person::getRole() const {

    return role;
}

void Person::setSurname(const std::string& surname) {

	std::string trimmed = trim(surname);

    if (trimmed.empty())
        throw std::invalid_argument("Error! Empty string is not allowed");
    
    this->surname = trimmed;
}

void Person::setName(const std::string& name) {
    
	std::string trimmed = trim(name);

    if (trimmed.empty())
        throw std::invalid_argument("Error! Empty string is not allowed");
        
    this->name = trimmed;
}
void Person::setPatronymic(const std::string& patronymic) {

	std::string trimmed = trim(patronymic);

    if (trimmed.empty())
        throw std::invalid_argument("Error! Empty string is not allowed");
        
    this->patronymic = trimmed;
}

void Person::setRole(Role role) {

    this->role = role;
}


void Person::clearSurname() {
    surname = "unknown";
}

void Person::clearName() {

    name = "unknown";
}

void Person::clearPatronymic() {
    patronymic = "unknown";
}
