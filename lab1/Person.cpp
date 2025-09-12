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
    const std::string& patronymic) {

    setSurname(surname);
    setName(name);
    setPatronymic(patronymic);
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

    std::string trimmed = surname;
    trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
    trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

    if (trimmed.empty())
        this->surname = "unknown";
    else
        this->surname = trimmed;
}

void Person::setName(const std::string& name) {
    
    std::string trimmed = name;
    trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
    trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

    if (trimmed.empty())
        this->name = "unknown";
    else
        this->name = trimmed;
}
void Person::setPatronymic(const std::string& patronymic) {

    std::string trimmed = patronymic;
    trimmed.erase(0, trimmed.find_first_not_of(" \t\n\r"));
    trimmed.erase(trimmed.find_last_not_of(" \t\n\r") + 1);

    if (trimmed.empty())
        this->patronymic = "unknown";
    else
        this->patronymic = trimmed;
}

void Person::setRole(Role role) {

    this->role = role;
}