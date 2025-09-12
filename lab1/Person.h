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
        explicit Person(const std::string& surname, const std::string& name, const std::string& patronymic);
        Person(const Person& other);

        virtual ~Person();
        
        Person& operator =(const Person& other);

        const std::string& getSurname() const;
        const std::string& getName() const;
        const std::string& getPatronymic() const;
        virtual const Role& getRole() const;

        void setSurname(const std::string& surname);
        void setName(const std::string& name);
        void setPatronymic(const std::string& patronymic);
        virtual void setRole(Role role);

        virtual std::string toString() const = 0;
    };
}