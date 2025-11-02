#pragma once

#include "ScoreRepository.h"
#include "StudentRepository.h"
#include "SubjectRepository.h"
#include "ProfessorRepository.h"

#include "Service.h"
#include "Vector.h"
#include "ScoreDto.h"

namespace Scores {
	class ScoreService : public Services::Service {
	private:
		const ScoreRepository* scoreRepository;
		const Students::StudentRepository * studentRepository;
		const Subjects::SubjectRepository* subjectRepository;
		const Professors::ProfessorRepository * professorRepository;

		ScoreDto* toDto(const Score* score) const;
	public:
		ScoreService(ScoreRepository* scoreRepository, Students::StudentRepository* studentRepository,
			Subjects::SubjectRepository* subjectRepository, Professors::ProfessorRepository* professorRepository);

		ScoreDto* findById(int id) const;

		Vectors::Vector<ScoreDto> findAll() const;

		Vectors::Vector<ScoreDto> findByStudentId(int studentId) const;

		Vectors::Vector<ScoreDto> findBySubjectId(int subjectId) const;

		Vectors::Vector<ScoreDto> findByProfessorId(int professorId) const;

		Vectors::Vector<ScoreDto> findByScore(int score) const;

		Vectors::Vector<ScoreDto> findByStudentIdAndSubjectId(int studentId, int subjectId) const;

		Vectors::Vector<ScoreDto> findByStudentIdAndProfessorId(int studentId, int professorId) const;

		Vectors::Vector<ScoreDto> findByStudentIdAndScore(int studentId, int score) const;

		Vectors::Vector<ScoreDto> findBySubjectIdAndProfessorId(int subjectId, int professorId) const;

		Vectors::Vector<ScoreDto> findBySubjectIdAndScore(int subjectId, int score) const;

		Vectors::Vector<ScoreDto> findByProfessorIdAndScore(int professorId, int score) const;

		bool createScore(const ScoreDto* scoreDto) const;

		bool deleteScore(int id) const;

		bool updateScore(const ScoreDto* scoreDto) const;
	};
}