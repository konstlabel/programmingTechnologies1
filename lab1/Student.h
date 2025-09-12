#pragma once

#include "Person.h"

namespace Groups { class Group; }

namespace Students {
    using namespace Groups;
    using namespace Persons;

    class Student : public Person {

        friend class Groups::Group;
        
        Group* group;
        std::string speciality;
        int course;
        float averageScore;

        void attachToGroup(Group* group);
        void detachFromGroup();
    public:
        Student();
        explicit Student(const std::string& surname,
                        const std::string& name,
                        const std::string& patronymic,
                        Group* group,
                        const std::string& speciality,
                        int course,
                        float averageScore);
        Student(const Student& other);

        ~Student();

        Student& operator =(const Student& other);

        const Group* getGroup() const;
        const std::string& getSpeciality() const;
        int getCourse() const;
        float getAverageScore() const;

        void setGroup(Group* group);
        void setSpeciality(const std::string& speciality);
        void setCourse(int course);
        void setAverageScore(float averageScore);

        void clearGroup();

        std::string toString() const override;
    };
}