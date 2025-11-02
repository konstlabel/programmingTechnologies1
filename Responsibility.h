#pragma once

#include <string>

namespace Responsibilities {
	class Responsibility {
		int id;
		std::string name;

	public:
		Responsibility();
		explicit Responsibility(int id, const std::string& name);
		Responsibility(const Responsibility& other);

		~Responsibility();

		Responsibility& operator =(const Responsibility& other);
		bool operator ==(const Responsibility& other) const;

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

			Responsibility build();
		};
	};
}