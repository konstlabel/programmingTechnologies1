#include "GroupRepository.h"
#include <iostream>

using namespace GroupRepositories;

GroupRepository::GroupRepository() : groups(8, true) {

	std::cout << "The GroupRepository's default constructor is called " << std::endl;
}

GroupRepository::GroupRepository(int capacity, bool ownsObjects) : groups(capacity, ownsObjects) {

	std::cout << "The GroupRepository's parameterized constructor is called " << std::endl;
}

GroupRepository::GroupRepository(const GroupRepository& other) : groups(other.groups) {

	std::cout << "The GroupRepository's copy constructor is called " << std::endl;
}

GroupRepository::~GroupRepository() {

	std::cout << "The GroupRepository's destructor is called " << std::endl;
}

GroupRepository& GroupRepository::operator =(const GroupRepository& other) {

	if (this == &other) return *this;
	groups = other.groups;
	return *this;
}

bool GroupRepository::operator ==(const GroupRepository& other) const {

	return groups == other.groups;
}

int GroupRepository::getSize() const {

	return groups.getSize();
}

int GroupRepository::getCapacity() const {

	return groups.getCapacity();
}

bool GroupRepository::getOwnsObjects() const {

	return groups.getOwnsObjects();
}

void GroupRepository::add(const Group* group) {

	try {
		groups.add(group);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

void GroupRepository::add(const Group& group) {

	try {
		groups.add(group);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

void GroupRepository::add(std::unique_ptr<Group> group) {

	try {
		groups.add(std::move(group));
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

void GroupRepository::deleteByIndex(int index) {

	try {
		groups.deleteByIndex(index);
	}
	catch (const std::out_of_range& e) {
		throw e;
	}
}

void GroupRepository::deleteByGroup(Group* group) {

	try {
		groups.deleteByObject(group);
	}
	catch (const std::invalid_argument& e) {
		throw e;
	}
}

Group* GroupRepository::findByIndex(int index) {

	try {
		return groups.getByIndex(index);
	}
	catch (const std::out_of_range& e) {
		return nullptr;
	}
}

int GroupRepository::findIndexByPointer(Group* group) const {

	try {
		return groups.getIndexByPointer(group);
	}
	catch (const std::invalid_argument& e) {
		return -1;
	}
}

int GroupRepository::findIndexByGroup(const Group& group) const {

	try {
		return groups.getIndexByObject(group);
	}
	catch (const std::invalid_argument& e) {
		return -1;
	}
}

bool GroupRepository::exists(const Group& group) const {

	return groups.exists(group);
}

bool GroupRepository::isEmpty() const {

	return groups.getSize() == 0;
}

void GroupRepository::print() const {

	if (isEmpty()) {
		std::cout << "There are no groups" << std::endl;
		return;
	}

	std::cout << "Groups:" << std::endl;
	groups.print();
}
