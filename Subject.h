#pragma once
#include <string>

namespace Subjects {
	class Subject {
		int id;
		std::string name;

	public:
		Subject();
		explicit Subject(int id, const std::string& name);
		Subject(const Subject& other);

		~Subject();

		Subject& operator =(const Subject& other);
		bool operator ==(const Subject& other) const;

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

			Subject build();
		};
	};
}