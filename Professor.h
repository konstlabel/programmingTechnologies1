#pragma once

#include "Person.h"
#include <string>

namespace Professors {
	class Professor : public Persons::Person {
		int department;
	public:
		Professor();
		explicit Professor(int id, std::string& firstName, std::string& middleName, std::string& lastName, std::string& phone, int deparment);
		Professor(const Professor& other);

		~Professor();

		Professor& operator =(const Professor& other);
		bool operator ==(const Professor& other) const;

		int getDepartment() const;

		void setDepartment(int department);

		std::string toString() const override;

		class Builder {
			int _id;
			std::string _firstName;
			std::string _middleName;
			std::string _lastName;
			std::string _phone;
			int _department;

		public:
			Builder& id(int _id);
			Builder& firstName(const std::string& _firstName);
			Builder& middleName(const std::string& _middleName);
			Builder& lastName(const std::string& _lastName);
			Builder& phone(const std::string& _phone);
			Builder& department(int _department);

			Professor build();
		};
	};
}
