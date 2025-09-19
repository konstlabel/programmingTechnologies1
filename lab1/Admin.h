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
		explicit Admin(int id,
			const std::string& surname,
			const std::string& name,
			const std::string& patronymic,
			const std::string& position,
			const std::string& phone,
			const std::string& responsibility);
		Admin(const Admin& other);

		~Admin();

		Admin& operator =(const Admin& other);

		const std::string& getPosition() const;
		const std::string& getPhone() const;
		const std::string& getResponsibility() const;

		void setPosition(const std::string& position);
		void setPhone(const std::string& phone);
		void setResponsibility(const std::string& responsibility);

		void clearPosition();
		void clearPhone();
		void clearResponsibility();

		std::string toString() const override;
	};
}