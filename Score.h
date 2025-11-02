#pragma once

#include <string>
#include "Student.h"
#include "Subject.h"
#include "Professor.h"

namespace Scores {
	class Score {
		int id;
		Students::Student* student;
		Subjects::Subject* subject;
		Professors::Professor* professor;
		int score;

	public:
		Score();
		Score(int id, Students::Student* student, Subjects::Subject* subject, Professors::Professor* professor, int score);
		Score(const Score& other);

		~Score();

		Score& operator =(const Score& other);
		bool operator ==(const Score& other) const;

		int getId() const;
		Students::Student* getStudent() const;
		Subjects::Subject* getSubject() const;
		Professors::Professor* getProfessor() const;
		int getScore() const;

		void setId(int id);
		void setStudent(Students::Student* student);
		void setSubject(Subjects::Subject* subject);
		void setProfessor(Professors::Professor* professor);
		void setScore(int score);

		std::string toString() const;

		class Builder {
			int _id;
			Students::Student* _student;
			Subjects::Subject* _subject;
			Professors::Professor* _professor;
			int _score;

		public:
			Builder& id(int _id);
			Builder& student(Students::Student* _student);
			Builder& subject(Subjects::Subject* _subject);
			Builder& professor(Professors::Professor* _professor);
			Builder& score(int _score);
			
			Score build();
		};
	};
}