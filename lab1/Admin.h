#pragma once

#include <string>
#include "Person.h"

namespace Admins {
	using namespace Persons;

	class Admin : public Person {
		std::string position;
		std::string phone;
		std::string responsibility;

	public:
		Admin();
		explicit Admin(const std::string& surname,
			const std::string& name,
			const std::string& patronymic,
			const std::string& position,
			const std::string& phone,
			const std::string& responsibility);
		Admin(const Admin& other);

		~Admin();

		Admin& operator =(const Admin& other);

		std::string getPosition() const;
		std::string getPhone() const;
		std::string getResponsibity() const;

		void setPosition(const std::string& position);
		void setPhone(const std::string& phone);
		void setResponsibility(const std::string& responsibility);

		std::string toString() const;
	};
}