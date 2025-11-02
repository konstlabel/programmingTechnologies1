#pragma once

#include "GroupRepository.h"
#include "SpecialityRepository.h"

#include "Service.h"
#include "Vector.h"
#include "GroupDto.h"

namespace Groups {
	class GroupService : public Services::Service {
	private:
		const GroupRepository* groupRepository;
		const Specialities::SpecialityRepository* specialityRepository;

		GroupDto* toDto(const Group* group) const;
	public:
		GroupService(GroupRepository* groupRepository, Specialities::SpecialityRepository* specialityRepository);

		GroupDto* findById(int id) const;

		Vectors::Vector<GroupDto> findAll() const;

		Vectors::Vector<GroupDto> findByName(const std::string& name) const;

		Vectors::Vector<GroupDto> findBySpecialityId(int specialityId) const;

		Vectors::Vector<GroupDto> findByCourse(int course) const;

		bool createGroup(const GroupDto* groupDto) const;

		bool deleteGroup(int id) const;

		bool updateGroup(const GroupDto* groupDto) const;
	};
}