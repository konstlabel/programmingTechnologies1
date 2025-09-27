#pragma once

#include "Professor.h"
#include "Vector.h"

using namespace Vectors;

namespace ProfessorRepositories {
	using namespace Professors;

	class ProfessorRepository {
		Vector<Professor> professors;
	public:
		ProfessorRepository();
		ProfessorRepository(int capacity, bool ownsObjects);
		ProfessorRepository(const ProfessorRepository& other);
		~ProfessorRepository();
	
		ProfessorRepository& operator =(const ProfessorRepository& other);
		bool operator ==(const ProfessorRepository& other) const;
		
		int getSize() const;
		int getCapacity() const;
		bool getOwnsObjects() const;
		
		void add(const Professor* professor);
		
		void deleteByIndex(int index);
		void deleteByProfessor(Professor* professor);
		
		Professor* findByIndex(int index);
		int findIndexByPointer(Professor* professor) const;
		int findIndexByProfessor(const Professor& professor) const;
		
		bool exists(const Professor& professor) const;
		bool isEmpty() const;
		
		void print() const;
	};
}