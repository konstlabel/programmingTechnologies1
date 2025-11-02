#include "ScoreService.h"
#include <iostream>

using namespace Scores;
using namespace Students;
using namespace Subjects;
using namespace Professors;
using namespace Vectors;
using namespace std;

ScoreDto* ScoreService::toDto(const Score* score) const {

	ScoreDto* dto = new ScoreDto();

	dto->id = score->getId();
	dto->studentId = score->getStudent()->getId();
	dto->subjectId = score->getSubject()->getId();
	dto->professorId = score->getProfessor()->getId();
	dto->score = score->getScore();

	return dto;
}

ScoreService::ScoreService(ScoreRepository* scoreRepository, StudentRepository* studentRepository,
	SubjectRepository* subjectRepository, ProfessorRepository* professorRepository) {

	if (scoreRepository == nullptr) {
		throw std::invalid_argument("ScoreRepository pointer is null");
	}
	if (studentRepository == nullptr) {
		throw std::invalid_argument("StudentRepository pointer is null");
	}
	if (subjectRepository == nullptr) {
		throw std::invalid_argument("SubjectRepository pointer is null");
	}
	if (professorRepository == nullptr) {
		throw std::invalid_argument("ProfessorRepository pointer is null");
	}

	this->scoreRepository = scoreRepository;
	this->studentRepository = studentRepository;
	this->subjectRepository = subjectRepository;
	this->professorRepository = professorRepository;
	cout << "ScoreService default constructor called" << endl;

}

ScoreDto* ScoreService::findById(int id) const {

	auto score = scoreRepository->findById(id);
	if (score == nullptr)
		return nullptr;

	ScoreDto* dto = toDto(score);
	delete score;
	return dto;
}

Vector<ScoreDto> ScoreService::findAll() const {

	Vector<ScoreDto> scoreDtos;

	Vector<Score> scores = scoreRepository->findAll();

	if (scores.isEmpty())
		return scoreDtos;

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	return scoreDtos;
}

Vector<ScoreDto> ScoreService::findByStudentId(int studentId) const {

	Vector<ScoreDto> scoreDtos;

	Student* student = studentRepository->findById(studentId);

	if (student == nullptr)
		return scoreDtos;

	Vector<Score> scores = scoreRepository->findByStudent(student);

	if (scores.isEmpty()) {
		return scoreDtos;
	}

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	delete student;
	return scoreDtos;
}

Vector<ScoreDto> ScoreService::findBySubjectId(int subjectId) const {

	Vector<ScoreDto> scoreDtos;

	Subject* subject = subjectRepository->findById(subjectId);

	if (subject == nullptr)
		return scoreDtos;

	Vector<Score> scores = scoreRepository->findBySubject(subject);

	if (scores.isEmpty()) {
		return scoreDtos;
	}

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	delete subject;
	return scoreDtos;
}

Vector<ScoreDto> ScoreService::findByProfessorId(int professorId) const {

	Vector<ScoreDto> scoreDtos;

	Professor* professor = professorRepository->findById(professorId);

	if (professor == nullptr)
		return scoreDtos;

	Vector<Score> scores = scoreRepository->findByProfessor(professor);

	if (scores.isEmpty()) {
		return scoreDtos;
	}

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	delete professor;
	return scoreDtos;
}

Vector<ScoreDto> ScoreService::findByScore(int score) const {

	Vector<ScoreDto> scoreDtos;

	Vector<Score> scores = scoreRepository->findByScore(score);

	if (scores.isEmpty())
		return scoreDtos;

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	return scoreDtos;
}

Vector<ScoreDto> ScoreService::findByStudentIdAndSubjectId(int studentId, int subjectId) const {

	Vector<ScoreDto> scoreDtos;

	Student* student = studentRepository->findById(studentId);

	if (student == nullptr)
		return scoreDtos;

	Subject* subject = subjectRepository->findById(subjectId);

	if (subject == nullptr)
		return scoreDtos;

	Vector<Score> scores = scoreRepository->findByStudentAndSubject(student, subject);

	if (scores.isEmpty())
		return scoreDtos;

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	delete subject;
	delete student;
	return scoreDtos;
}

Vector<ScoreDto> ScoreService::findByStudentIdAndProfessorId(int studentId, int professorId) const {

	Vector<ScoreDto> scoreDtos;

	Student* student = studentRepository->findById(studentId);

	if (student == nullptr)
		return scoreDtos;

	Professor* professor = professorRepository->findById(professorId);

	if (professor == nullptr)
		return scoreDtos;

	Vector<Score> scores = scoreRepository->findByStudentAndProfessor(student, professor);

	if (scores.isEmpty())
		return scoreDtos;

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	delete student;
	delete professor;
	return scoreDtos;
}

Vector<ScoreDto> ScoreService::findByStudentIdAndScore(int studentId, int score) const {

	Vector<ScoreDto> scoreDtos;

	Student* student = studentRepository->findById(studentId);

	if (student == nullptr)
		return scoreDtos;

	Vector<Score> scores = scoreRepository->findByStudentAndScore(student, score);

	if (scores.isEmpty())
		return scoreDtos;

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	delete student;
	return scoreDtos;
}

Vector<ScoreDto> ScoreService::findBySubjectIdAndProfessorId(int subjectId, int professorId) const {

	Vector<ScoreDto> scoreDtos;

	Subject* subject = subjectRepository->findById(subjectId);

	if (subject == nullptr)
		return scoreDtos;

	Professor* professor = professorRepository->findById(professorId);

	if (professor == nullptr)
		return scoreDtos;

	Vector<Score> scores = scoreRepository->findBySubjectAndProfessor(subject, professor);

	if (scores.isEmpty())
		return scoreDtos;

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	delete subject;
	delete professor;
	return scoreDtos;
}

Vector<ScoreDto> ScoreService::findBySubjectIdAndScore(int subjectId, int score) const {

	Vector<ScoreDto> scoreDtos;

	Subject* subject = subjectRepository->findById(subjectId);

	if (subject == nullptr)
		return scoreDtos;

	Vector<Score> scores = scoreRepository->findBySubjectAndScore(subject, score);

	if (scores.isEmpty())
		return scoreDtos;

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	delete subject;
	return scoreDtos;
}

Vector<ScoreDto> ScoreService::findByProfessorIdAndScore(int professorId, int score) const {

	Vector<ScoreDto> scoreDtos;

	Professor* professor = professorRepository->findById(professorId);

	if (professor == nullptr)
		return scoreDtos;

	Vector<Score> scores = scoreRepository->findByProfessorAndScore(professor, score);

	if (scores.isEmpty())
		return scoreDtos;

	for (Score* score : scores) {
		scoreDtos.add(toDto(score));
	}

	delete professor;
	return scoreDtos;
}



bool ScoreService::createScore(const ScoreDto* scoreDto) const {

	if (scoreDto == nullptr)
		throw std::invalid_argument("ScoreDto pointer is null");

	Student* student = studentRepository->findById(scoreDto->studentId);
	if (student == nullptr)
		throw std::invalid_argument("Error found subject by id");

	Subject* subject = subjectRepository->findById(scoreDto->subjectId);
	if (subject == nullptr)
		throw std::invalid_argument("Error found subject by id");

	Professor* professor = professorRepository->findById(scoreDto->professorId);
	if (professor == nullptr)
		throw std::invalid_argument("Error found professor by id");

	if (scoreDto->score < 2 || scoreDto->score > 5)
		throw std::invalid_argument("Score must be between 2 and 5");

	Score* score = new Score(Score::Builder()
		.id(0)
		.student(student)
		.subject(subject)
		.professor(professor)
		.score(scoreDto->score)
		.build());

	scoreRepository->save(score);
	delete score;
	return true;
}

bool ScoreService::deleteScore(int id) const {

	if (scoreRepository->findById(id) == nullptr)
		return false;

	scoreRepository->deleteById(id);
	return true;
}

bool ScoreService::updateScore(const ScoreDto* scoreDto) const {

	if (scoreDto == nullptr)
		throw std::invalid_argument("ScoreDto pointer is null");

	Score* score = scoreRepository->findById(scoreDto->id);
	if (score == nullptr)
		return false;

	if (scoreDto->studentId != 0) {
		Student* student = studentRepository->findById(scoreDto->studentId);
		if (student == nullptr)
			throw std::invalid_argument("Error found subject by id");

		score->setStudent(student);
	}
	
	if (scoreDto->subjectId != 0) {
		Subject* subject = subjectRepository->findById(scoreDto->subjectId);
		if (subject == nullptr)
			throw std::invalid_argument("Error found subject by id");

		score->setSubject(subject);
	}

	if (scoreDto->professorId != 0) {
		Professor* professor = professorRepository->findById(scoreDto->professorId);
		if (professor == nullptr)
			throw std::invalid_argument("Error found professor by id");

		score->setProfessor(professor);
	}
	
	if (scoreDto->score != 0) {
		if (scoreDto->score < 2 || scoreDto->score > 5)
			throw std::invalid_argument("Score must be between 2 and 5");

		score->setScore(scoreDto->score);
	}
	
	scoreRepository->save(score);
	delete score;
	return true;
}