#pragma once
#include <string>
#include "Speciality.h"

namespace Groups {
	class Group {
		int id;
		std::string name;
		Specialities::Speciality* speciality;
		int course;

	public:
		Group();
		explicit Group(int id, const std::string& name, Specialities::Speciality* speciality, int course);
		Group(const Group& other);

		~Group();

		Group& operator =(const Group& other);
		bool operator ==(const Group& other) const;

		int getId() const;
		std::string getName() const;
		Specialities::Speciality* getSpeciality() const;
		int getCourse() const;

		void setId(int id);
		void setName(const std::string& name);
		void setSpeciality(Specialities::Speciality* speciality);
		void setCourse(int course);

		std::string toString() const;

		class Builder {
		private:
			int _id;
			std::string _name;
			Specialities::Speciality* _speciality;
			int _course;

		public:
			Builder& id(int _id);
			Builder& name(const std::string& _name);
			Builder& speciality(Specialities::Speciality* _speciality);
			Builder& course(int _course);

			Group build();
		};
	};
}