#include "AdminService.h"
#include <regex>
#include <iostream>

using namespace Admins;
using namespace Positions;
using namespace Responsibilities;
using namespace Vectors;
using namespace std;

AdminDto* AdminService::toDto(const Admin* admin) const {

	AdminDto* dto = new AdminDto();

	dto->id = admin->getId();
	dto->firstName = admin->getFirstName();
	dto->middleName = admin->getMiddleName();
	dto->lastName = admin->getLastName();
	dto->phone = admin->getPhone();
	dto->positionId = (admin->getPosition() == nullptr) ? -1 : admin->getPosition()->getId();
	dto->responsibilityId = (admin->getResponsibility() == nullptr) ? -1 : admin->getResponsibility()->getId();

	return dto;
}

AdminService::AdminService(AdminRepository* adminRepository, PositionRepository* positionRepository, ResponsibilityRepository* responsibilityRepository) {

	if (adminRepository == nullptr) {
		throw std::invalid_argument("AdminRepository pointer is null");
	}
	if (positionRepository == nullptr) {
		throw std::invalid_argument("PositionRepository pointer is null");
	}
	if (responsibilityRepository == nullptr) {
		throw std::invalid_argument("ResponsibilityRepository pointer is null");
	}

	this->adminRepository = adminRepository;
	this->positionRepository = positionRepository;
	this->responsibilityRepository = responsibilityRepository;
	cout << "AdminService default constructor called" << endl;
}

AdminDto* AdminService::findById(int id) const {

	auto admin = adminRepository->findById(id);
	if (admin == nullptr)
		return nullptr;


	AdminDto* dto = toDto(admin);
	delete admin;
	return dto;
}

Vector<AdminDto> AdminService::findAll() const {

	Vector<Admin> admins = adminRepository->findAll();

	Vector<AdminDto> adminDtos;

	if (admins.isEmpty())
		return adminDtos;

	for (Admin* admin : admins) {
		adminDtos.add(toDto(admin));
	}

	return adminDtos;
}

Vector<AdminDto> AdminService::findByFirstName(const std::string& firstName) const {

	Vector<Admin> admins = adminRepository->findByFirstName(firstName);

	Vector<AdminDto> adminDtos;

	if (admins.isEmpty()) {
		return adminDtos;
	}

	for (Admin* admin : admins) {
		adminDtos.add(toDto(admin));
	}

	return adminDtos;
}

Vector<AdminDto> AdminService::findByMiddleName(const std::string& middleName) const {

	Vector<Admin> admins = adminRepository->findByMiddleName(middleName);

	Vector<AdminDto> adminDtos;

	if (admins.isEmpty()) {
		return adminDtos;
	}

	for (Admin* admin : admins) {
		adminDtos.add(toDto(admin));
	}

	return adminDtos;
}

Vector<AdminDto> AdminService::findByLastName(const std::string& lastName) const {

	Vector<Admin> admins = adminRepository->findByLastName(lastName);

	Vector<AdminDto> adminDtos;

	if (admins.isEmpty()) {
		return adminDtos;
	}

	for (Admin* admin : admins) {
		adminDtos.add(toDto(admin));
	}

	return adminDtos;
}

Vector<AdminDto> AdminService::findByPositionId(int positionId) const {

	Vector<AdminDto> adminDtos;

	Position* position = positionRepository->findById(positionId);

	if (position == nullptr)
		adminDtos;

	Vector<Admin> admins = adminRepository->findByPosition(position);

	if (admins.isEmpty()) {
		return adminDtos;
	}

	for (Admin* admin : admins) {
		adminDtos.add(toDto(admin));
	}

	delete position;
	return adminDtos;
}

Vector<AdminDto> AdminService::findByResponsibilityId(int responsibilityId) const {

	Vector<AdminDto> adminDtos;

	Responsibility* responsibility = responsibilityRepository->findById(responsibilityId);

	if (responsibility == nullptr)
		adminDtos;

	Vector<Admin> admins = adminRepository->findByResponsibility(responsibility);

	if (admins.isEmpty()) {
		return adminDtos;
	}

	for (Admin* admin : admins) {
		adminDtos.add(toDto(admin));
	}

	delete responsibility;
	return adminDtos;
}

bool AdminService::createAdmin(const AdminDto* adminDto) const {

	if (adminDto == nullptr)
		throw std::invalid_argument("AdminDto pointer is null");

	std::string firstName = trim(adminDto->firstName);
	if (firstName.empty())
		throw std::invalid_argument("Empty adminDto's first_name is not allowed");

	std::string middleName = trim(adminDto->middleName);
	if (middleName.empty())
		throw std::invalid_argument("Empty adminDto's middle_name is not allowed");

	std::string lastName = trim(adminDto->lastName);
	if (lastName.empty())
		throw std::invalid_argument("Empty adminDto's last_name is not allowed");

	std::string phone = trim(adminDto->phone);
	if (phone.empty())
		throw std::invalid_argument("Empty adminDto's phone is not allowed");
	const std::regex phoneTemplate(R"(^\+7\d{10}$)");
	if (!std::regex_match(phone, phoneTemplate))
		throw std::invalid_argument("Invalid adminDto's phone format");

	Position* position = positionRepository->findById(adminDto->positionId);
	if (position == nullptr)
		throw std::invalid_argument("Error found position by id");

	Responsibility* responsibility = responsibilityRepository->findById(adminDto->responsibilityId);
	if (responsibility == nullptr)
		throw std::invalid_argument("Error found responsibility by id");


	Admin* admin = new Admin(Admin::Builder()
		.id(0)
		.firstName(firstName)
		.middleName(middleName)
		.lastName(lastName)
		.phone(phone)
		.position(position)
		.responsibility(responsibility)
		.build());

	adminRepository->save(admin);
	delete admin;
	return true;
}

bool AdminService::deleteAdmin(int id) const {

	if (adminRepository->findById(id) == nullptr)
		return false;

	adminRepository->deleteById(id);
	return true;
}

bool AdminService::updateAdmin(const AdminDto* adminDto) const {

	if (adminDto == nullptr)
		throw std::invalid_argument("AdminDto pointer is null");

	Admin* admin = adminRepository->findById(adminDto->id);

	if (admin == nullptr)
		return false;

	if (!adminDto->firstName.empty()) {
		std::string firstName = trim(adminDto->firstName);
		if (firstName.empty())
			throw std::invalid_argument("Empty adminDto's first_name is not allowed");

		admin->setFirstName(firstName);
	}
	
	if (!adminDto->middleName.empty()) {
		std::string middleName = trim(adminDto->middleName);
		if (middleName.empty())
			throw std::invalid_argument("Empty adminDto's middle_name is not allowed");

		admin->setMiddleName(middleName);
	}
	
	if (!adminDto->lastName.empty()) {
		std::string lastName = trim(adminDto->lastName);
		if (lastName.empty())
			throw std::invalid_argument("Empty adminDto's last_name is not allowed");

		admin->setLastName(lastName);
	}
	
	if (!adminDto->lastName.empty()) {
		std::string phone = trim(adminDto->phone);
		if (phone.empty())
			throw std::invalid_argument("Empty adminDto's phone is not allowed");
		const std::regex phoneTemplate(R"(^\+7\d{10}$)");
		if (!std::regex_match(phone, phoneTemplate))
			throw std::invalid_argument("Invalid adminDto's phone format");

		admin->setPhone(phone);
	}

	if (adminDto->positionId != 0) {
		Position* position = positionRepository->findById(adminDto->positionId);
		if (position == nullptr)
			throw std::invalid_argument("Error found position by id");

		admin->setPosition(position);
	}

	
	if (adminDto->responsibilityId != 0) {
		Responsibility* responsibility = responsibilityRepository->findById(adminDto->responsibilityId);

		if (responsibility == nullptr)
			throw std::invalid_argument("Error found responsibility by id");

		admin->setResponsibility(responsibility);
	}

	adminRepository->save(admin);
	delete admin;
	return true;
}