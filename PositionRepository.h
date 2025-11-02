#pragma once

#include <string>
#include "Position.h"
#include "Vector.h"
#include "Repository.h"

namespace Positions {
	class PositionRepository : public Repositories::Repository {
	public:
		PositionRepository(pqxx::connection* conn);

		Position* findById(int id) const;
		
		Vectors::Vector<Position> findAll() const;
		
		Vectors::Vector<Position> findByName(const std::string& name) const;
		
		void save(Position* position) const;
		
		void deleteByObject(const Position* position) const;
		
		void deleteById(int id) const;
	};
}