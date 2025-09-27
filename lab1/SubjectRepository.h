#pragma once

#include <string>
#include "Vector.h"

using namespace Vectors;

namespace SubjectRepositories {

	class SubjectRepository {
	private:
		Vector<std::string> subjects;

		std::string trim(const std::string& str) const;
	public:
		SubjectRepository();
		SubjectRepository(int capacity, bool ownsObjects);
		SubjectRepository(const SubjectRepository& other);
		~SubjectRepository();
		
		SubjectRepository& operator =(const SubjectRepository& other);
		bool operator ==(const SubjectRepository& other) const;
		
		int getSize() const;
		int getCapacity() const;
		bool getOwnsObjects() const;
		
		void add(const std::string& subject);
		void remove(const std::string& subject);
		
		int findIndex(const std::string& subject) const;
		std::string& findByIndex(int index);
		int findIndexByPointer(const std::string* subject) const;

		bool exists(const std::string& subject) const;
		bool isEmpty() const;
		
		void print() const;
	};
}