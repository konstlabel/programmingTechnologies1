#include <iostream>
#include <string>
#include "Person.h"

using namespace Persons;

Person::Person()
    : surname("unknown"), name("unknown"), patronymic("unknown") {
    std::cout << "The Person's default constructor is called" << std::endl;
}

Person::Person(const std::string& surname,
    const std::string& name,
    const std::string& patronymic)
    : surname(surname.empty() ? "unknown" : surname),
    name(name.empty() ? "unknown" : name),
    patronymic(patronymic.empty() ? "unknown" : patronymic) {
    std::cout << "The Person's parameterized constructor is called" << std::endl;
}

Person::Person(const Person& other)
    : surname(other.surname), name(other.name), patronymic(other.patronymic) {
    std::cout << "The Person's copy constructor is called" << std::endl;

}

Person::~Person() {
    std::cout << "The Person's destructor is called" << std::endl;
}

Person& Person::operator=(const Person& other) {
    if (this == &other) return *this;

    this->surname = other.surname;
    this->name = other.name;
    this->patronymic = other.patronymic;

    return *this;
}

std::string Person::getSurname() const {
    return surname;
}

std::string Person::getName() const {
    return name;
}

std::string Person::getPatronymic() const {
    return patronymic;
}

Role Person::getRole() const {
    return role;
}

void Person::setSurname(const std::string& surname) {
    this->surname = surname;
}

void Person::setName(const std::string& name) {
    this->name = name;
}
void Person::setPatronymic(const std::string& patronymic) {
    this->patronymic = patronymic;
}

void Person::setRole(Role role) {
    this->role = role;
}