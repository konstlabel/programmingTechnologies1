#include "GroupService.h"
#include <iostream>

using namespace Groups;
using namespace Specialities;
using namespace Vectors;
using namespace std;

GroupDto* GroupService::toDto(const Group* group) const {

	GroupDto* dto = new GroupDto();

	dto->id = group->getId();
	dto->name = group->getName();
	dto->specialityId = group->getSpeciality()->getId();
	dto->course = group->getCourse();

	return dto;
}

GroupService::GroupService(GroupRepository* groupRepository, SpecialityRepository* specialityRepository) {

	if (groupRepository == nullptr) {
		throw std::invalid_argument("GroupRepository pointer is null");
	}
	if (specialityRepository == nullptr) {
		throw std::invalid_argument("SpecialityRepository pointer is null");
	}

	this->groupRepository = groupRepository;
	this->specialityRepository = specialityRepository;

	cout << "GroupService default constructor called" << endl;
}

GroupDto* GroupService::findById(int id) const {

	auto group = groupRepository->findById(id);
	if (group == nullptr)
		return nullptr;

	GroupDto* dto = toDto(group);
	delete group;
	return dto;
}

Vector<GroupDto> GroupService::findAll() const {

	Vector<Group> groups = groupRepository->findAll();

	Vector<GroupDto> groupDtos;

	if (groups.isEmpty())
		return groupDtos;

	for (Group* group : groups) {
		groupDtos.add(toDto(group));
	}

	return groupDtos;
}

Vector<GroupDto> GroupService::findByName(const std::string& name) const {

	Vector<Group> groups = groupRepository->findByName(name);

	Vector<GroupDto> groupDtos;

	if (groups.isEmpty())
		return groupDtos;

	for (Group* group : groups) {
		groupDtos.add(toDto(group));
	}

	return groupDtos;
}

Vector<GroupDto> GroupService::findBySpecialityId(int specialityId) const {

	Vector<GroupDto> groupDtos;

	Speciality* speciality = specialityRepository->findById(specialityId);

	if (speciality == nullptr)
		groupDtos;

	Vector<Group> groups = groupRepository->findBySpeciality(speciality);

	if (groups.isEmpty()) {
		return groupDtos;
	}

	for (Group* group : groups) {
		groupDtos.add(toDto(group));
	}

	delete speciality;
	return groupDtos;
}

Vector<GroupDto> GroupService::findByCourse(int course) const {

	Vector<Group> groups = groupRepository->findByCourse(course);

	Vector<GroupDto> groupDtos;

	if (groups.isEmpty())
		return groupDtos;

	for (Group* group : groups) {
		groupDtos.add(toDto(group));
	}

	return groupDtos;
}

bool GroupService::createGroup(const GroupDto* groupDto) const {

	if (groupDto == nullptr)
		throw std::invalid_argument("GroupDto pointer is null");

	std::string name = trim(groupDto->name);
	if (name.empty())
		throw std::invalid_argument("Empty groupDto's name is not allowed");
	
	Speciality* speciality = nullptr;
	speciality = specialityRepository->findById(groupDto->specialityId);
	if (speciality == nullptr)
		throw std::invalid_argument("Error found speciality by id");

	if (groupDto->course < 1 || groupDto->course > 5)
		throw std::invalid_argument("GroupDto's course must be between 1 and 5");

	Group* group = new Group(Group::Builder()
		.id(0)
		.name(name)
		.speciality(speciality)
		.course(groupDto->course)
		.build());

	groupRepository->save(group);
	delete group;
	return true;
}

bool GroupService::deleteGroup(int id) const {

	if (groupRepository->findById(id) == nullptr)
		return false;

	groupRepository->deleteById(id);
	return true;
}

bool GroupService::updateGroup(const GroupDto* groupDto) const {

	if (groupDto == nullptr)
		throw std::invalid_argument("GroupDto pointer is null");

	Group* group = groupRepository->findById(groupDto->id);

	if (group == nullptr)
		return false;

	std::string name = "";
	
	if (!groupDto->name.empty()) {
		name = trim(groupDto->name);
		if (name.empty())
			throw std::invalid_argument("Empty groupDto's name is not allowed");

		group->setName(name);
	}

	Speciality* speciality = nullptr;
	if (groupDto->specialityId != 0) {
		speciality = specialityRepository->findById(groupDto->specialityId);
		if (speciality == nullptr)
			throw std::invalid_argument("Error found speciality by id");

		group->setSpeciality(speciality);
	}

	if (groupDto->course != 0) {
		if (groupDto->course < 1 || groupDto->course > 5)
			throw std::invalid_argument("GroupDto's course must be between 1 and 5");
		
		group->setCourse(groupDto->course);
	}

	groupRepository->save(group);
	delete group;
	return true;
}