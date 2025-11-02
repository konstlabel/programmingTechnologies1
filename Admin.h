#pragma once

#include "Person.h"
#include <string>

#include "Position.h"
#include "Responsibility.h"

namespace Admins {
	class Admin : public Persons::Person {
		Positions::Position* position;
		Responsibilities::Responsibility* responsibility;

	public:
		Admin();
		explicit Admin(int id, std::string& firstName, std::string& middleName, std::string& lastName, std::string& phone, Positions::Position* position, Responsibilities::Responsibility* responsibility);
		Admin(const Admin& other);

		~Admin();

		Admin& operator =(const Admin& other);
		bool operator ==(const Admin& other) const;

		Positions::Position* getPosition() const;
		Responsibilities::Responsibility* getResponsibility() const;

		void setPosition(Positions::Position* position);
		void setResponsibility(Responsibilities::Responsibility* responsibility);

		std::string toString() const override;

		class Builder {
			int _id;
			std::string _firstName;
			std::string _middleName;
			std::string _lastName;
			std::string _phone;
			Positions::Position* _position;
			Responsibilities::Responsibility* _responsibility;

		public:
			Builder& id(int _id);
			Builder& firstName(const std::string& _firstName);
			Builder& middleName(const std::string& _middleName);
			Builder& lastName(const std::string& _lastName);
			Builder& phone(const std::string& _phone);
			Builder& position(Positions::Position* _position);
			Builder& responsibility(Responsibilities::Responsibility* _responsibility);

			Admin build();
		};
	};
}
