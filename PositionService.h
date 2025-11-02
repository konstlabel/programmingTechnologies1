#pragma once

#include "PositionRepository.h"

#include "Service.h"
#include "Vector.h"
#include "PositionDto.h"

namespace Positions {
	class PositionService : public Services::Service {
	private:
		const PositionRepository* positionRepository;

		PositionDto* toDto(const Position* position) const;
	public:

		PositionService(PositionRepository* positionRepository);

		PositionDto* findById(int id) const;

		Vectors::Vector<PositionDto> findAll() const;

		Vectors::Vector<PositionDto> findByName(const std::string& name) const;

		bool createPosition(const PositionDto* positionDto) const;

		bool deletePosition(int id) const;

		bool updatePosition(const PositionDto* positionDto) const;
	};
}