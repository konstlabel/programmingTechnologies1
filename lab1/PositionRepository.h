#pragma once

#include <string>
#include "Vector.h"

using namespace Vectors;

namespace PositionRepositories {

	class PositionRepository {
		Vector<std::string> positions;

		std::string trim(const std::string& str) const;
	public:
		PositionRepository();
		PositionRepository(int capacity, bool ownsObjects);
		PositionRepository(const PositionRepository& other);
		~PositionRepository();
	
		PositionRepository& operator =(const PositionRepository& other);
		bool operator ==(const PositionRepository& other) const;
		
		int getSize() const;
		int getCapacity() const;
		bool getOwnsObjects() const;

		void add(const std::string& position);
		void remove(const std::string& position);

		int findIndex(const std::string& position) const;
		std::string& findByIndex(int index);
		int findIndexByPointer(const std::string* position) const;

		bool exists(const std::string& position) const;
		bool isEmpty() const;

		void print() const;
	};
}
