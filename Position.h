#pragma once
#include <string>


namespace Positions {
	class Position {
		int id;
		std::string name;
	
	public:
		Position();
		explicit Position(int id, const std::string& name);
		Position(const Position& other);
	
		~Position();

		Position& operator =(const Position& other);
		bool operator ==(const Position& other) const;

		int getId() const;
		std::string getName() const;

		void setId(int id);
		void setName(const std::string& name);

		std::string toString() const;

		class Builder {
		private:
			int _id = 0;
			std::string _name = "";

		public:
			Builder& id(int _id);
			Builder& name(const std::string& _name);

			Position build();
		};
	};
}