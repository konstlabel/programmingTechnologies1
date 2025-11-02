#pragma once

#include "Person.h"
#include "Group.h"
#include <string>


namespace Students {
	class Student : public Persons::Person{
		Groups::Group* group;

	public:
		Student();
		explicit Student(int id, std::string& firstName, std::string& middleName, std::string& lastName, std::string& phone, Groups::Group* group);
		Student(const Student& other);

		~Student();

		Student& operator =(const Student& other);
		bool operator ==(const Student& other) const;

		Groups::Group* getGroup() const;

		void setGroup(Groups::Group* group);

		std::string toString() const override;

		class Builder {
			int _id;
			std::string _firstName;
			std::string _middleName;
			std::string _lastName;
			std::string _phone;
			Groups::Group* _group;

		public:
			Builder& id(int _id);
			Builder& firstName(const std::string& _firstName);
			Builder& middleName(const std::string& _middleName);
			Builder& lastName(const std::string& _lastName);
			Builder& phone(const std::string& _phone);
			Builder& group(Groups::Group* _group);

			Student build();
		};
	};
}
