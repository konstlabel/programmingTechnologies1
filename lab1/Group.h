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
        explicit Group(const std::string&);
        Group(const Group&);

        ~Group();

        Group& operator =(const Group&);

        std::string getName() const;
        Vector<Student>& getStudents();

        void setName(const std::string&);
        void setStudents(const Vector<Student>&);

        Student* findByIndex(int);
        void print();
    };
}