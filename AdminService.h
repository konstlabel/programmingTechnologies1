#pragma once

#include "AdminRepository.h"
#include "PositionRepository.h"
#include "ResponsibilityRepository.h"

#include "Service.h"
#include "Vector.h"
#include "AdminDto.h"

namespace Admins {
	class AdminService : public Services::Service {
	private:
		const AdminRepository* adminRepository;
		const Positions::PositionRepository* positionRepository;
		const Responsibilities::ResponsibilityRepository* responsibilityRepository;

		AdminDto* toDto(const Admin* admin) const;
	public:
		AdminService(AdminRepository* adminRepository, Positions::PositionRepository* positionRepository, Responsibilities::ResponsibilityRepository* responsibilityRepository);

		AdminDto* findById(int id) const;	

		Vectors::Vector<AdminDto> findAll() const;

		Vectors::Vector<AdminDto> findByFirstName(const std::string& firstName) const;

		Vectors::Vector<AdminDto> findByMiddleName(const std::string& middleName) const;
		
		Vectors::Vector<AdminDto> findByLastName(const std::string& lastName) const;

		Vectors::Vector<AdminDto> findByPositionId(int positionId) const;

		Vectors::Vector<AdminDto> findByResponsibilityId(int responsibilityId) const;

		bool createAdmin(const AdminDto* adminDto) const;

		bool deleteAdmin(int id) const;

		bool updateAdmin(const AdminDto* adminDto) const;
	};
}