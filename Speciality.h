#pragma once

#include <string>

namespace Specialities {
	class Speciality {
		int id;
		std::string name;

	public:
		Speciality();
		explicit Speciality(int id, const std::string& name);
		Speciality(const Speciality& other);

		~Speciality();

		Speciality& operator =(const Speciality& other);
		bool operator ==(const Speciality& other) const;

		int getId() const;
		std::string getName() const;

		void setId(int id);
		void setName(const std::string& name);

		std::string toString() const;

		class Builder {
		private:
			int _id;
			std::string _name;

		public:
			Builder& id(int _id);
			Builder& name(const std::string& _name);

			Speciality build();
		};
	};
}