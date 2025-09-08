#pragma once

#include <string>
#include "Student.h"
#include "Vector.h"

namespace Groups {
    using namespace Students;
    using namespace Vectors;

    class Group {
        std::string name;
        Vector<Student> students;

    public:
        Group();
        explicit Group(const std::string& name);
        Group(const Group& other);

        ~Group();

        Group& operator =(const Group& other);

        std::string getName() const;
        Vector<Student>& getStudents();

        void setName(const std::string& name);
        void setStudents(const Vector<Student>& students);

        Student* findByIndex(int index);
        void print();
    };
}