#include "PositionService.h"

using namespace Vectors;
using namespace Positions;
using namespace std;

PositionDto* PositionService::toDto(const Position* position) const {

	PositionDto* dto = new PositionDto();

	dto->id = position->getId();
	dto->name = position->getName();

	return dto;
}

PositionService::PositionService(PositionRepository* positionRepository) {

	if (positionRepository == nullptr) {
		throw std::invalid_argument("AdminRepository pointer is null");
	}

	this->positionRepository = positionRepository;

	cout << "PositionService default constructor called" << endl;
}

PositionDto* PositionService::findById(int id) const {

	auto position = positionRepository->findById(id);
	if (position == nullptr)
		return nullptr;

	PositionDto* positionDto = toDto(position);
	delete position;
	return positionDto;
}

Vector<PositionDto> PositionService::findAll() const {

	Vector<Position> positions = positionRepository->findAll();

	Vector<PositionDto> positionDtos;

	if (positions.isEmpty())
		return positionDtos;

	for (Position* position : positions) {
		positionDtos.add(toDto(position));
	}

	return positionDtos;
}

Vector<PositionDto> PositionService::findByName(const std::string& name) const {

	Vector<Position> positions = positionRepository->findByName(name);

	Vector<PositionDto> positionDtos;

	if (positions.isEmpty())
		return positionDtos;

	for (Position* position : positions) {
		positionDtos.add(toDto(position));
	}

	return positionDtos;
}

bool PositionService::createPosition(const PositionDto* positionDto) const {

	if (positionDto == nullptr)
		throw std::invalid_argument("PositionDto pointer is null");

	std::string name = trim(positionDto->name);
	if (name.empty())
		throw std::invalid_argument("Empty positionDto's name is not allowed");

	Position* position = new Position(Position::Builder()
		.id(0)
		.name(name)
		.build());

	positionRepository->save(position);
	delete position;
	return true;
}

bool PositionService::deletePosition(int id) const {

	if (positionRepository->findById(id) == nullptr)
		return false;

	positionRepository->deleteById(id);
	return true;

}

bool PositionService::updatePosition(const PositionDto* positionDto) const {

	if (positionDto == nullptr)
		throw std::invalid_argument("PositionDto pointer is null");

	if (positionDto->id < 1)
		throw std::invalid_argument("PositionDto's id less than 1");

	std::string name = trim(positionDto->name);
	if (name.empty())
		throw std::invalid_argument("Empty positionDto's name is not allowed");

	Position* position = new Position(Position::Builder()
		.id(positionDto->id)
		.name(name)
		.build());

	positionRepository->save(position);
	delete position;
	return true;
}
