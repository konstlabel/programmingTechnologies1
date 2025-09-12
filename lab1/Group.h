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
        Vector<Student> students;

    public:
        Group();
        explicit Group(const std::string& name);
        Group(const Group& other);

        ~Group();

        Group& operator =(const Group& other);
        bool operator ==(const Group& other) const;

        const std::string& getName() const;
        const Vector<Student>& getStudents() const;

        void setName(const std::string& name);
        void setStudents(const Vector<Student>& students);

        void clearName();

        void addStudent(Student* student);
        
        void deleteStudentByIndex(int index);
        void deleteStudent(Student* student);
        
        Student* findByIndex(int index);
        int findStudentIndex(Student* student) const;
        
        void print();

        std::string toString() const;
    };
}