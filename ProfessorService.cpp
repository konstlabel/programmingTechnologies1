#include "ProfessorService.h"
#include <regex>
#include <iostream>

using namespace Professors;
using namespace Vectors;
using namespace std;

ProfessorDto* ProfessorService::toDto(const Professor* professor) const {

	ProfessorDto* dto = new ProfessorDto();

	dto->id = professor->getId();
	dto->firstName = professor->getFirstName();
	dto->middleName = professor->getMiddleName();
	dto->lastName = professor->getLastName();
	dto->phone = professor->getPhone();
	dto->department = professor->getDepartment();

	return dto;
}

ProfessorService::ProfessorService(ProfessorRepository* professorRepository) {

	if (professorRepository == nullptr) {
		throw std::invalid_argument("ProfessorRepository pointer is null");
	}

	this->professorRepository = professorRepository;
	cout << "ProfessorService default constructor called" << endl;
}

ProfessorDto* ProfessorService::findById(int id) const {

	auto professor = professorRepository->findById(id);
	if (professor == nullptr)
		return nullptr;

	ProfessorDto* dto = toDto(professor);
	delete professor;
	return dto;
}

Vector<ProfessorDto> ProfessorService::findAll() const {

	Vector<Professor> professors = professorRepository->findAll();

	Vector<ProfessorDto> professorDtos;

	if (professors.isEmpty())
		return professorDtos;

	for (Professor* professor : professors) {
		professorDtos.add(toDto(professor));
	}

	return professorDtos;
}

Vector<ProfessorDto> ProfessorService::findByFirstName(const std::string& firstName) const {

	Vector<Professor> professors = professorRepository->findByFirstName(firstName);

	Vector<ProfessorDto> professorDtos;

	if (professors.isEmpty()) {
		return professorDtos;
	}

	for (Professor* professor : professors) {
		professorDtos.add(toDto(professor));
	}

	return professorDtos;
}

Vector<ProfessorDto> ProfessorService::findByMiddleName(const std::string& middleName) const {

	Vector<Professor> professors = professorRepository->findByMiddleName(middleName);

	Vector<ProfessorDto> professorDtos;

	if (professors.isEmpty()) {
		return professorDtos;
	}

	for (Professor* professor : professors) {
		professorDtos.add(toDto(professor));
	}

	return professorDtos;
}

Vector<ProfessorDto> ProfessorService::findByLastName(const std::string& lastName) const {

	Vector<Professor> professors = professorRepository->findByLastName(lastName);

	Vector<ProfessorDto> professorDtos;

	if (professors.isEmpty()) {
		return professorDtos;
	}

	for (Professor* professor : professors) {
		professorDtos.add(toDto(professor));
	}

	return professorDtos;
}

Vector<ProfessorDto> ProfessorService::findByDepartment(int department) const {

	Vector<ProfessorDto> professorDtos;

	Vector<Professor> professors = professorRepository->findByDepartment(department);

	if (professors.isEmpty()) {
		return professorDtos;
	}

	for (Professor* professor : professors) {
		professorDtos.add(toDto(professor));
	}

	return professorDtos;
}

bool ProfessorService::createProfessor(const ProfessorDto* professorDto) const {

	if (professorDto == nullptr)
		throw std::invalid_argument("ProfessorDto pointer is null");

	std::string firstName = trim(professorDto->firstName);
	if (firstName.empty())
		throw std::invalid_argument("Empty professorDto's first_name is not allowed");

	std::string middleName = trim(professorDto->middleName);
	if (middleName.empty())
		throw std::invalid_argument("Empty professorDto's middle_name is not allowed");

	std::string lastName = trim(professorDto->lastName);
	if (lastName.empty())
		throw std::invalid_argument("Empty professorDto's last_name is not allowed");

	std::string phone = trim(professorDto->phone);
	if (phone.empty())
		throw std::invalid_argument("Empty professorDto's phone is not allowed");
	const std::regex phoneTemplate(R"(^\+7\d{10}$)");
	if (!std::regex_match(phone, phoneTemplate))
		throw std::invalid_argument("Invalid professorDto's phone format");

	if (professorDto->department != 0)
		throw std::invalid_argument("Invalid professorDto's department id");


	Professor* professor = new Professor(Professor::Builder()
		.id(0)
		.firstName(firstName)
		.middleName(middleName)
		.lastName(lastName)
		.phone(phone)
		.department(professorDto->department)
		.build());

	professorRepository->save(professor);
	delete professor;
	return true;
}

bool ProfessorService::deleteProfessor(int id) const {

	if (professorRepository->findById(id) == nullptr)
		return false;

	professorRepository->deleteById(id);
	return true;
}

bool ProfessorService::updateProfessor(const ProfessorDto* professorDto) const {

	if (professorDto == nullptr)
		throw std::invalid_argument("ProfessorDto pointer is null");

	Professor* professor = professorRepository->findById(professorDto->id);

	if (professor == nullptr)
		return false;

	if (!professorDto->firstName.empty()) {
		std::string firstName = trim(professorDto->firstName);
		if (firstName.empty())
			throw std::invalid_argument("Empty professorDto's first_name is not allowed");

		professor->setFirstName(firstName);
	}

	if (!professorDto->middleName.empty()) {
		std::string middleName = trim(professorDto->middleName);
		if (middleName.empty())
			throw std::invalid_argument("Empty professorDto's middle_name is not allowed");

		professor->setMiddleName(middleName);
	}

	if (!professorDto->lastName.empty()) {
		std::string lastName = trim(professorDto->lastName);
		if (lastName.empty())
			throw std::invalid_argument("Empty professorDto's last_name is not allowed");

		professor->setLastName(lastName);
	}

	if (!professorDto->lastName.empty()) {
		std::string phone = trim(professorDto->phone);
		if (phone.empty())
			throw std::invalid_argument("Empty professorDto's phone is not allowed");
		const std::regex phoneTemplate(R"(^\+7\d{10}$)");
		if (!std::regex_match(phone, phoneTemplate))
			throw std::invalid_argument("Invalid professorDto's phone format");

		professor->setPhone(phone);
	}

	if (professorDto->department >= 0)
		professor->setDepartment(professorDto->department);

	professorRepository->save(professor);
	delete professor;
	return true;
}