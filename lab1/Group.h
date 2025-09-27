#pragma once

#include <string>
#include "Student.h"
#include "Vector.h"

namespace Groups {
    using namespace Students;
	using namespace Vectors;

    class Group {

        friend class Students::Student;

        std::string name;
        Vector<int> students;

    public:
        Group();
        explicit Group(const std::string& name);
        Group(const Group& other);

        ~Group();

        Group& operator =(const Group& other);
        bool operator ==(const Group& other) const;

		const std::string& getName() const;
		const Vector<int>& getStudents() const;

		void setName(const std::string& name);
		void setStudents(const Vector<int>& students);

		void clearName();

		void addStudentId(int studentId);
		void addStudent(const Student& student);
		void addStudent(std::unique_ptr<Student> student);
        
		void deleteStudentByIndex(int index);
		void deleteStudentById(int studentId);
		void deleteStudent(const Student& student);
		void deleteStudent(std::unique_ptr<Student> student);

		int findByIndex(int index) const;
		int findStudentIndex(int studentId) const;
		int findStudentIndex(const Student& student) const;
		int findStudentIndex(const std::unique_ptr<Student> student) const;

		bool studentExists(int studentId) const;
		bool studentExists(const Student& student) const;
		bool studentExists(const std::unique_ptr<Student> student) const;

		void print() const;

        std::string toString() const;
    };
}