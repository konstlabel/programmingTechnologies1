#include "AdminRepository.h"
#include <iostream>

using namespace AdminRepositories;

AdminRepository::AdminRepository() : admins(8, true) {

	std::cout << "The AdminRepository's default constructor is called" << std::endl;
}

AdminRepository::AdminRepository(int capacity, bool ownsObjects) : admins(capacity, ownsObjects) {

	std::cout << "The AdminRepository's parameterized constructor is called" << std::endl;
}

AdminRepository::AdminRepository(const AdminRepository& other) : admins(other.admins) {

	std::cout << "The AdminRepository's copy constructor is called" << std::endl;
}

AdminRepository::~AdminRepository() {

	std::cout << "The AdminRepository's destructor is called" << std::endl;
}

AdminRepository& AdminRepository::operator =(const AdminRepository& other) {

	if (this == &other) return *this;
	admins = other.admins;
	return *this;
}

bool AdminRepository::operator ==(const AdminRepository& other) const {

	return admins == other.admins;
}

int AdminRepository::getSize() const {

	return admins.getSize();
}

int AdminRepository::getCapacity() const {

	return admins.getCapacity();
}

bool AdminRepository::getOwnsObjects() const {

	return admins.getOwnsObjects();
}

void AdminRepository::add(const Admin* admin) {
	
	try {
		admins.add(admin);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

void AdminRepository::add(const Admin& admin) {

	try {
		admins.add(admin);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

void AdminRepository::add(std::unique_ptr<Admin> admin) {

	try {
		admins.add(std::move(admin));
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

void AdminRepository::deleteByIndex(int index) {

	try {
		admins.deleteByIndex(index);
	}
	catch (const std::out_of_range& e) {
		throw e;
	}
}

void AdminRepository::deleteByAdmin(Admin* admin) {

	try {
		admins.deleteByObject(admin);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

Admin* AdminRepository::findByIndex(int index) {

	try {
		return admins.getByIndex(index);
	}
	catch (const std::out_of_range& e) {
		return nullptr;
	}
}

int AdminRepository::findIndexByPointer(Admin* admin) const {

	try {
		return admins.getIndexByPointer(admin);
	}
	catch (const std::invalid_argument& e) {
		return -1;
	}
}

int AdminRepository::findIndexByAdmin(const Admin& admin) const {

	try {
		return admins.getIndexByObject(admin);
	}
	catch (const std::invalid_argument& e) {
		return -1;
	}
}


bool AdminRepository::exists(const Admin& admin) const {

	return admins.exists(admin);
}

bool AdminRepository::isEmpty() const {

	return admins.isEmpty();
}

void AdminRepository::print() const {

	if (isEmpty()) {
		std::cout << "There are no admins" << std::endl;
		return;
	}

	std::cout << "Admins:" << std::endl;
	admins.print();
}
