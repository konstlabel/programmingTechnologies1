#pragma once

#include "Vector.h"
#include <string>

using namespace Vectors;

namespace SpecialityRepositories {
	class SpecialityRepository {
	private:
		Vector<std::string> specialities;

		std::string trim(const std::string& str) const;
	public:
		SpecialityRepository();
		SpecialityRepository(int capacity, bool ownsObjects);
		SpecialityRepository(const SpecialityRepository& other);
		~SpecialityRepository();
		
		SpecialityRepository& operator =(const SpecialityRepository& other);
		bool operator ==(const SpecialityRepository& other) const;
		
		int getSize() const;
		int getCapacity() const;
		bool getOwnsObjects() const;
		
		void add(const std::string& speciality);
		void remove(const std::string& speciality);
		
		int findIndex(const std::string& speciality) const;
		std::string& findByIndex(int index);
		int findIndexByPointer(const std::string* speciality) const;

		bool exists(const std::string& speciality) const;
		bool isEmpty() const;

		void print() const;
	};
}