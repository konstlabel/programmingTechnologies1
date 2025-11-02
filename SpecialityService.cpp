#include "SpecialityService.h"

using namespace Specialities;
using namespace Vectors;
using namespace std;

SpecialityDto* SpecialityService::toDto(const Speciality* speciality) const {

	SpecialityDto* dto = new SpecialityDto();

	dto->id = speciality->getId();
	dto->name = speciality->getName();

	return dto;
}

SpecialityService::SpecialityService(SpecialityRepository* specialityRepository) {

	if (specialityRepository == nullptr) {
		throw std::invalid_argument("AdminRepository pointer is null");
	}

	this->specialityRepository = specialityRepository;

	cout << "SpecialityService default constructor called" << endl;
}

SpecialityDto* SpecialityService::findById(int id) const {

	auto speciality = specialityRepository->findById(id);
	if (speciality == nullptr)
		return nullptr;

	SpecialityDto* specialityDto = toDto(speciality);
	delete speciality;
	return specialityDto;
}

Vector<SpecialityDto> SpecialityService::findAll() const {

	Vector<Speciality> specialities = specialityRepository->findAll();

	Vector<SpecialityDto> specialityDtos;

	if (specialities.isEmpty())
		return specialityDtos;

	for (Speciality* speciality : specialities) {
		specialityDtos.add(toDto(speciality));
	}

	return specialityDtos;
}

Vector<SpecialityDto> SpecialityService::findByName(const std::string& name) const {

	Vector<Speciality> specialities = specialityRepository->findByName(name);

	Vector<SpecialityDto> specialityDtos;

	if (specialities.isEmpty())
		return specialityDtos;

	for (Speciality* speciality : specialities) {
		specialityDtos.add(toDto(speciality));
	}

	return specialityDtos;
}

bool SpecialityService::createSpeciality(const SpecialityDto* specialityDto) const {

	if (specialityDto == nullptr)
		throw std::invalid_argument("SpecialityDto pointer is null");

	std::string name = trim(specialityDto->name);
	if (name.empty())
		throw std::invalid_argument("Empty specialityDto's name is not allowed");

	Speciality* speciality = new Speciality(Speciality::Builder()
		.id(0)
		.name(name)
		.build());

	specialityRepository->save(speciality);
	return true;
}

bool SpecialityService::deleteSpeciality(int id) const {

	if (specialityRepository->findById(id) == nullptr)
		return false;

	specialityRepository->deleteById(id);
	return true;

}

bool SpecialityService::updateSpeciality(const SpecialityDto* specialityDto) const {

	if (specialityDto == nullptr)
		throw std::invalid_argument("SpecialityDto pointer is null");

	if (specialityDto->id < 1)
		throw std::invalid_argument("SpecialityDto's id less than 1");

	std::string name = trim(specialityDto->name);
	if (name.empty())
		throw std::invalid_argument("Empty specialityDto's name is not allowed");

	Speciality* speciality = new Speciality(Speciality::Builder()
		.id(specialityDto->id)
		.name(name)
		.build());

	specialityRepository->save(speciality);
	return true;
}
