#pragma once

#include <string>
#include "Vector.h"

using namespace Vectors;

namespace ResponsibilityRepositories {

	class ResponsibilityRepository {
		Vector<std::string> responsibilities;

		std::string trim(const std::string& str) const;
	public:
		ResponsibilityRepository();
		ResponsibilityRepository(int capacity, bool ownsObjects);
		ResponsibilityRepository(const ResponsibilityRepository& other);
		~ResponsibilityRepository();
	
		ResponsibilityRepository& operator =(const ResponsibilityRepository& other);
		bool operator ==(const ResponsibilityRepository& other) const;
		
		int getSize() const;
		int getCapacity() const;
		bool getOwnsObjects() const;
		
		void add(const std::string& responsibility);
		void remove(const std::string& responsibility);
		
		int findIndex(const std::string& responsibility) const;
		std::string& findByIndex(int index);
		int findIndexByPointer(const std::string* responsibility) const;
		
		bool exists(const std::string& responsibility) const;
		bool isEmpty() const;
		
		void print() const;
	};
}