#pragma once

#include "Student.h"
#include "Vector.h"

using namespace Vectors;

namespace StudentRepositories {
	using namespace Students;

	class StudentRepository {
		Vector<Student> students;
	public:
		StudentRepository();
		StudentRepository(int capacity, bool ownsObjects);
		StudentRepository(const StudentRepository& other);
		~StudentRepository();

		StudentRepository& operator =(const StudentRepository& other);
		bool operator ==(const StudentRepository& other) const;

		int getSize() const;
		int getCapacity() const;
		bool getOwnsObjects() const;

		void add(const Student* student);
		void add(const Student& student);
		void add(std::unique_ptr<Student> student);

		void deleteByIndex(int index);
		void deleteByStudent(Student* student);

		Student* findByIndex(int index);
		int findIndexByPointer(Student* student) const;
		int findIndexByStudent(const Student& student) const;

		bool exists(const Student& student) const;
		bool isEmpty() const;

		void print() const;
	};
}