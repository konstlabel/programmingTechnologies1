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
        explicit Student(const std::string& surname,
                        const std::string& name,
                        const std::string& patronymic,
                        const std::string& groupName,
                        const std::string& speciality,
                        int course,
                        float averageScore);
        Student(const Student& other);

        ~Student();

        Student& operator =(const Student& other);

        std::string getGroupName() const;
        std::string getSpeciality() const;
        int getCourse() const;
        float getAverageScore() const;

        void setGroupName(const std::string& groupName);
        void setSpeciality(const std::string& speciality);
        void setCourse(int course);
        void setAverageScore(float averageScore);

        std::string toString() const override;
    };
}