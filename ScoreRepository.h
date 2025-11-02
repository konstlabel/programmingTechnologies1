#pragma once

#include <string>
#include "Score.h"
#include "Vector.h"
#include "Repository.h"

namespace Scores {
	class ScoreRepository : public Repositories::Repository {
	public:
		ScoreRepository(pqxx::connection* conn);

		Score* findById(int id) const;

		Vectors::Vector<Score> findAll() const;

		Vectors::Vector<Score> findByStudent(Students::Student* student) const;

		Vectors::Vector<Score> findBySubject(Subjects::Subject* subject) const;

		Vectors::Vector<Score> findByProfessor(Professors::Professor* professor) const;

		Vectors::Vector<Score> findByScore(int score) const;

		Vectors::Vector<Score> findByStudentAndSubject(Students::Student* student, Subjects::Subject* subject) const;

		Vectors::Vector<Score> findByStudentAndProfessor(Students::Student* student, Professors::Professor* professor) const;

		Vectors::Vector<Score> findByStudentAndScore(Students::Student* student, int score) const;

		Vectors::Vector<Score> findBySubjectAndProfessor(Subjects::Subject* subject, Professors::Professor* professor) const;

		Vectors::Vector<Score> findBySubjectAndScore(Subjects::Subject* subject, int score) const;

		Vectors::Vector<Score> findByProfessorAndScore(Professors::Professor* professor, int score) const;

		void save(Score* score) const;

		void deleteByObject(const Score* score) const;
		
		void deleteById(int id) const;
	};
}