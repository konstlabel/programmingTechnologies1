#pragma once

#include <string>
#include "Role.h"

namespace Persons {
    class Person {
    protected:
        int id;
        std::string surname;
        std::string name;
        std::string patronymic;
        Role role;

		static std::string trim(const std::string& str);
    public:
        Person();
        explicit Person(int id, const std::string& surname, const std::string& name, const std::string& patronymic, Role role);
        Person(const Person& other);

        virtual ~Person();
        
        Person& operator =(const Person& other);
		bool operator ==(const Person& other) const;

        int getId() const;
        const std::string& getSurname() const;
        const std::string& getName() const;
        const std::string& getPatronymic() const;
        virtual const Role& getRole() const;

        void setSurname(const std::string& surname);
        void setName(const std::string& name);
        void setPatronymic(const std::string& patronymic);
        virtual void setRole(Role role);

        void clearSurname();
        void clearName();
        void clearPatronymic();

        virtual std::string toString() const = 0;
    };
}