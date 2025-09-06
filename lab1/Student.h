#pragma once

#include "Person.h"
#include "Group.h"

namespace Students {
    using namespace Persons;
    using namespace Groups;

    class Student : public Person {
        std::string groupName;
        std::string speciality;
        int course;
        float averageScore;

    public:
        Student();
        explicit Student(const std::string&,
                        const std::string&,
                        const std::string&,
                        const std::string&,
                        const std::string&,
                        int,
                        float);
        Student(const Student&);

        ~Student();

        Student& operator =(const Student&);

        std::string getGroupName() const;
        std::string getSpeciality() const;
        int getCourse() const;
        float getAverageScore() const;
        Role getRole() const override;

        void setGroupName(const std::string&);
        //todo
        void setSpeciality(const std::string&);
        void setCourse(int);
        void setAverageScore(float);
        void setRole(Role) override;

        std::string toString() override;
    };
}