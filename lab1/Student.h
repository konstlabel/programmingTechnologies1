#pragma once

#include "Person.h"

namespace Groups { class Group; }

namespace Students {
    using namespace Groups;
    using namespace Persons;

    class Student : public Person {

        int groupId;
        std::string speciality;
        int course;
        float averageScore;

    public:
        Student();
        explicit Student(int id,
                        const std::string& surname,
                        const std::string& name,
                        const std::string& patronymic,
                        int groupId,
                        const std::string& speciality,
                        int course,
                        float averageScore);
        Student(const Student& other);

        ~Student();

        Student& operator =(const Student& other);

        int getGroupId() const;
        const std::string& getSpeciality() const;
        int getCourse() const;
        float getAverageScore() const;

        void setGroupId(int groupId);
        void setSpeciality(const std::string& speciality);
        void setCourse(int course);
        void setAverageScore(float averageScore);

        void clearGroup();

        std::string toString() const override;
    };
}