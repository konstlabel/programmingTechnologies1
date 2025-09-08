#pragma once

#include <string>
#include "Role.h"

namespace Persons {
    class Person {
    protected:
        std::string surname;
        std::string name;
        std::string patronymic;
        Role role;

    public:
        Person();
        explicit Person(const std::string&, const std::string&, const std::string&);
        Person(const Person&);

        virtual ~Person();
        
        Person& operator =(const Person&);

        std::string getSurname() const;
        std::string getName() const;
        std::string getPatronymic() const;
        virtual Role getRole() const;

        void setSurname(const std::string&);
        void setName(const std::string&);
        void setPatronymic(const std::string&);
        virtual void setRole(Role);

        virtual std::string toString() = 0;
    };
}