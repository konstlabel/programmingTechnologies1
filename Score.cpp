#include "Score.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace Scores;
using namespace Students;
using namespace Subjects;
using namespace Professors;
using namespace std;

Score::Score() : id(0), student(nullptr), subject(nullptr), professor(nullptr), score(0) {

	std::cout << "Score default constructor called." << std::endl;
}

Score::Score(int id, Student* student, Subject* subject, Professor* professor, int score)
	: id(id), student(student), subject(subject), professor(professor), score(score) {

	std::cout << "Score all arguments constructor called." << std::endl;
}

Score::Score(const Score& other)
	: id(other.id), student(other.student), subject(other.subject), professor(other.professor), score(other.score) {

	std::cout << "Score copy constructor called." << std::endl;
}

Score::~Score() {

	delete student;
	delete subject;
	delete professor;
	std::cout << "Score destructor called." << std::endl;
}

Score& Score::operator =(const Score& other) {

	if (this != &other) {
		id = other.id;
		student = other.student;
		subject = other.subject;
		professor = other.professor;
		score = other.score;
	}
	return *this;
}

bool Score::operator ==(const Score& other) const {

	if (this == &other) {
		return true;
	}

	return id == other.id &&
		student == other.student &&
		subject == other.subject &&
		professor == other.professor &&
		score == other.score;
}

int Score::getId() const {

	return id;
}

Student* Score::getStudent() const {

	return student;
}

Subject* Score::getSubject() const {

	return subject;
}

Professor* Score::getProfessor() const {

	return professor;
}

int Score::getScore() const {

	return score;
}

void Score::setId(int id) {

	this->id = id;
}

void Score::setStudent(Student* student) {

	this->student = student;
}

void Score::setSubject(Subject* subject) {

	this->subject = subject;
}

void Score::setProfessor(Professor* professor) {

	this->professor = professor;
}

void Score::setScore(int score) {

	this->score = score;
}

std::string Score::toString() const {

	stringstream oss;
	oss << "Score {"
		<< "id: " << id
		<< ", Student: " << student->getLastName() << " " << student->getLastName() << " " << student->getFirstName() << " " << student->getMiddleName()
		<< ", Subject: " << subject->getName()
		<< ", Professor: " << professor->getLastName() << " " << professor->getFirstName() << " " << professor->getMiddleName()
		<< ", Score: " << score
		<< "}";
	return oss.str();
}

Score::Builder& Score::Builder::id(int _id) {

	this->_id = _id;
	return *this;
}

Score::Builder& Score::Builder::student(Student* _student) {

	this->_student = _student;
	return *this;
}

Score::Builder& Score::Builder::subject(Subject* _subject) {

	this->_subject = _subject;
	return *this;
}

Score::Builder& Score::Builder::professor(Professor* _professor) {

	this->_professor = _professor;
	return *this;
}

Score::Builder& Score::Builder::score(int _score) {

	this->_score = _score;
	return *this;
}

Score Score::Builder::build() {

	return Score(_id, _student, _subject, _professor, _score);
}