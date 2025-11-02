#include "ResponsibilityService.h"

using namespace Responsibilities;
using namespace Vectors;
using namespace std;

ResponsibilityDto* ResponsibilityService::toDto(const Responsibility* responsibility) const {

	ResponsibilityDto* dto = new ResponsibilityDto();

	dto->id = responsibility->getId();
	dto->name = responsibility->getName();

	return dto;
}

ResponsibilityService::ResponsibilityService(ResponsibilityRepository* responsibilityRepository) {

	if (responsibilityRepository == nullptr) {
		throw std::invalid_argument("AdminRepository pointer is null");
	}

	this->responsibilityRepository = responsibilityRepository;

	cout << "ResponsibilityService default constructor called" << endl;
}

ResponsibilityDto* ResponsibilityService::findById(int id) const {

	auto responsibility = responsibilityRepository->findById(id);
	if (responsibility == nullptr)
		return nullptr;

	ResponsibilityDto* responsibilityDto = toDto(responsibility);
	delete responsibility;
	return responsibilityDto;
}

Vector<ResponsibilityDto> ResponsibilityService::findAll() const {

	Vector<Responsibility> responsibilities = responsibilityRepository->findAll();

	Vector<ResponsibilityDto> responsibilityDtos;

	if (responsibilities.isEmpty())
		return responsibilityDtos;

	for (Responsibility* responsibility : responsibilities) {
		responsibilityDtos.add(toDto(responsibility));
	}

	return responsibilityDtos;
}

Vector<ResponsibilityDto> ResponsibilityService::findByName(const std::string& name) const {

	Vector<Responsibility> responsibilities = responsibilityRepository->findByName(name);

	Vector<ResponsibilityDto> responsibilityDtos;

	if (responsibilities.isEmpty())
		return responsibilityDtos;

	for (Responsibility* responsibility : responsibilities) {
		responsibilityDtos.add(toDto(responsibility));
	}

	return responsibilityDtos;
}

bool ResponsibilityService::createResponsibility(const ResponsibilityDto* responsibilityDto) const {

	if (responsibilityDto == nullptr)
		throw std::invalid_argument("ResponsibilityDto pointer is null");

	std::string name = trim(responsibilityDto->name);
	if (name.empty())
		throw std::invalid_argument("Empty responsibilityDto's name is not allowed");
 
	Responsibility* responsibility = new Responsibility(Responsibility::Builder()
		.id(0)
		.name(name)
		.build());

	responsibilityRepository->save(responsibility);
	return true;
}

bool ResponsibilityService::deleteResponsibility(int id) const {

	if (responsibilityRepository->findById(id) == nullptr)
		return false;

	responsibilityRepository->deleteById(id);
	return true;

}

bool ResponsibilityService::updateResponsibility(const ResponsibilityDto* responsibilityDto) const {

	if (responsibilityDto == nullptr)
		throw std::invalid_argument("ResponsibilityDto pointer is null");

	if (responsibilityDto->id < 1)
		throw std::invalid_argument("ResponsibilityDto's id less than 1");

	std::string name = trim(responsibilityDto->name);
	if (name.empty())
		throw std::invalid_argument("Empty responsibilityDto's name is not allowed");

	Responsibility* responsibility = new Responsibility(Responsibility::Builder()
		.id(responsibilityDto->id)
		.name(name)
		.build());

	responsibilityRepository->save(responsibility);
	return true;
}
