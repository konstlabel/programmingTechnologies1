#pragma once

#include <string>

namespace Persons {
	class Person {
	protected:
		int id;
		std::string firstName;
		std::string middleName;
		std::string lastName;
		std::string phone;

	public:
		Person();
		explicit Person(int id, const std::string& firstName, const std::string& middleName, const std::string& lastName, const std::string& phone);
		Person(const Person& other);

		virtual ~Person();

		Person& operator =(const Person& other);
		bool operator ==(const Person& other) const;

		int getId() const;
		std::string getFirstName() const;
		std::string getMiddleName() const;
		std::string getLastName() const;
		std::string getPhone() const;

		void setId(int id);
		void setFirstName(const std::string& firstName);
		void setMiddleName(const std::string& middleName);
		void setLastName(const std::string& lastName);
		void setPhone(const std::string& phone);

		virtual std::string toString() const = 0;
	};
}