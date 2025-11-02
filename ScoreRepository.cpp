#include "ScoreRepository.h"

#include <iostream>
#include <pqxx/pqxx>

using namespace Scores;
using namespace Students;
using namespace Subjects;
using namespace Professors;
using namespace Vectors;
using namespace std;
using namespace pqxx;

ScoreRepository::ScoreRepository(pqxx::connection* conn) : Repository(conn) {

	cout << "ScoreRepository all arguments constructor called." << endl;
}

Score* ScoreRepository::findById(int id) const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
			SELECT 
				s.id,
				s.student_id,
				st.first_name AS student_first_name,
				st.middle_name AS student_middle_name,
				st.last_name AS student_last_name,
				st.phone AS student_phone,
				st.group_id AS student_group_id,
				s.subject_id,
				su.name AS subject_name,
				s.professor_id,
				p.first_name AS professor_first_name,
				p.middle_name AS professor_middle_name,
				p.last_name AS professor_last_name,
				p.phone AS professor_phone,
				p.department AS professor_department,
				s.score
			FROM scores AS s
			LEFT JOIN students AS st ON st.id = s.student_id
			LEFT JOIN subjects AS su ON su.id = s.subject_id
			LEFT JOIN professors AS p ON p.id = s.professor_id
			WHERE s.id = )" + to_string(id);

	auto res = txn.exec(query);

	if (res.empty())
		return nullptr;

	if (res[0]["id"].is_null() ||
		res[0]["student_id"].is_null() ||
		res[0]["student_first_name"].is_null() ||
		res[0]["student_middle_name"].is_null() ||
		res[0]["student_last_name"].is_null() ||
		res[0]["student_phone"].is_null() ||
		res[0]["student_group_id"].is_null() ||
		res[0]["subject_id"].is_null() ||
		res[0]["subject_name"].is_null() ||
		res[0]["professor_id"].is_null() ||
		res[0]["professor_first_name"].is_null() ||
		res[0]["professor_middle_name"].is_null() ||
		res[0]["professor_last_name"].is_null() ||
		res[0]["professor_phone"].is_null() ||
		res[0]["professor_department"].is_null() ||
		res[0]["score"].is_null())
		return nullptr;

	Professor* professor = new Professor(Professor::Builder()
		.id(res[0]["professor_id"].as<int>())
		.firstName(res[0]["professor_first_name"].as<string>())
		.middleName(res[0]["professor_middle_name"].as<string>())
		.lastName(res[0]["professor_last_name"].as<string>())
		.phone(res[0]["professor_phone"].as<string>())
		.department(res[0]["professor_department"].as<int>())
		.build());

	Subject* subject = new Subject(Subject::Builder()
		.id(res[0]["subject_id"].as<int>())
		.name(res[0]["subject_name"].as<string>())
		.build());

	Student* student = new Student(Student::Builder()
		.id(res[0]["student_id"].as<int>())
		.firstName(res[0]["student_first_name"].as<string>())
		.middleName(res[0]["student_middle_name"].as<string>())
		.lastName(res[0]["student_last_name"].as<string>())
		.phone(res[0]["student_phone"].as<string>())
		.group(nullptr)
		.build());

	Score* score = new Score(Score::Builder()
		.id(res[0]["id"].as<int>())
		.professor(professor)
		.subject(subject)
		.student(student)
		.build());

	return score;
}

Vector<Score> ScoreRepository::findAll() const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
			SELECT 
				s.id,
				s.student_id,
				st.first_name AS student_first_name,
				st.middle_name AS student_middle_name,
				st.last_name AS student_last_name,
				st.phone AS student_phone,
				st.group_id AS student_group_id,
				s.subject_id,
				su.name AS subject_name,
				s.professor_id,
				p.first_name AS professor_first_name,
				p.middle_name AS professor_middle_name,
				p.last_name AS professor_last_name,
				p.phone AS professor_phone,
				p.department AS professor_department,
				s.score
			FROM scores AS s
			LEFT JOIN students AS st ON st.id = s.student_id
			LEFT JOIN subjects AS su ON su.id = s.subject_id
			LEFT JOIN professors AS p ON p.id = s.professor_id
			ORDER BY s.id
		)";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

Vector<Score> ScoreRepository::findByStudent(Student* student) const {

	if (student == nullptr)
		return Vector<Score>();

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			s.id,
			s.student_id,
			st.first_name AS student_first_name,
			st.middle_name AS student_middle_name,
			st.last_name AS student_last_name,
			st.phone AS student_phone,
			st.group_id AS student_group_id,
			s.subject_id,
			su.name AS subject_name,
			s.professor_id,
			p.first_name AS professor_first_name,
			p.middle_name AS professor_middle_name,
			p.last_name AS professor_last_name,
			p.phone AS professor_phone,
			p.department AS professor_department,
			s.score
		FROM scores AS s
		LEFT JOIN students AS st ON st.id = s.student_id
		LEFT JOIN subjects AS su ON su.id = s.subject_id
		LEFT JOIN professors AS p ON p.id = s.professor_id
		WHERE s.student_id = )" + to_string(student->getId()) +
		" ORDER BY s.id";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

Vector<Score> ScoreRepository::findBySubject(Subject* subject) const {

	if (subject == nullptr)
		return Vector<Score>();

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			s.id,
			s.student_id,
			st.first_name AS student_first_name,
			st.middle_name AS student_middle_name,
			st.last_name AS student_last_name,
			st.phone AS student_phone,
			st.group_id AS student_group_id,
			s.subject_id,
			su.name AS subject_name,
			s.professor_id,
			p.first_name AS professor_first_name,
			p.middle_name AS professor_middle_name,
			p.last_name AS professor_last_name,
			p.phone AS professor_phone,
			p.department AS professor_department,
			s.score
		FROM scores AS s
		LEFT JOIN students AS st ON st.id = s.student_id
		LEFT JOIN subjects AS su ON su.id = s.subject_id
		LEFT JOIN professors AS p ON p.id = s.professor_id
		WHERE s.subject_id = )" + to_string(subject->getId()) +
		" ORDER BY s.id";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

Vector<Score> ScoreRepository::findByProfessor(Professor* professor) const {

	if (professor == nullptr)
		return Vector<Score>();

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			s.id,
			s.student_id,
			st.first_name AS student_first_name,
			st.middle_name AS student_middle_name,
			st.last_name AS student_last_name,
			st.phone AS student_phone,
			st.group_id AS student_group_id,
			s.subject_id,
			su.name AS subject_name,
			s.professor_id,
			p.first_name AS professor_first_name,
			p.middle_name AS professor_middle_name,
			p.last_name AS professor_last_name,
			p.phone AS professor_phone,
			p.department AS professor_department,
			s.score
		FROM scores AS s
		LEFT JOIN students AS st ON st.id = s.student_id
		LEFT JOIN subjects AS su ON su.id = s.subject_id
		LEFT JOIN professors AS p ON p.id = s.professor_id
		WHERE s.professor_id = )" + to_string(professor->getId()) +
		" ORDER BY s.id";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

Vector<Score> ScoreRepository::findByScore(int score) const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			s.id,
			s.student_id,
			st.first_name AS student_first_name,
			st.middle_name AS student_middle_name,
			st.last_name AS student_last_name,
			st.phone AS student_phone,
			st.group_id AS student_group_id,
			s.subject_id,
			su.name AS subject_name,
			s.professor_id,
			p.first_name AS professor_first_name,
			p.middle_name AS professor_middle_name,
			p.last_name AS professor_last_name,
			p.phone AS professor_phone,
			p.department AS professor_department,
			s.score
		FROM scores AS s
		LEFT JOIN students AS st ON st.id = s.student_id
		LEFT JOIN subjects AS su ON su.id = s.subject_id
		LEFT JOIN professors AS p ON p.id = s.professor_id
		WHERE s.score = )" + to_string(score) +
		" ORDER BY s.id";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

Vector<Score> ScoreRepository::findByStudentAndSubject(Student* student, Subject* subject) const {

	if (student == nullptr || subject == nullptr)
		return Vector<Score>();

	read_transaction txn(*const_cast<connection*>(conn));
	
	string query = R"(
		SELECT 
			s.id,
			s.student_id,
			st.first_name AS student_first_name,
			st.middle_name AS student_middle_name,
			st.last_name AS student_last_name,
			st.phone AS student_phone,
			st.group_id AS student_group_id,
			s.subject_id,
			su.name AS subject_name,
			s.professor_id,
			p.first_name AS professor_first_name,
			p.middle_name AS professor_middle_name,
			p.last_name AS professor_last_name,
			p.phone AS professor_phone,
			p.department AS professor_department,
			s.score
		FROM scores AS s
		LEFT JOIN students AS st ON st.id = s.student_id
		LEFT JOIN subjects AS su ON su.id = s.subject_id
		LEFT JOIN professors AS p ON p.id = s.professor_id
		WHERE s.student_id = )" + to_string(student->getId()) + " AND s.subject_id = " + to_string(subject->getId()) +
		" ORDER BY s.id";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

Vector<Score> ScoreRepository::findByStudentAndProfessor(Student* student, Professor* professor) const {

	if (student == nullptr || professor == nullptr)
		return Vector<Score>();

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			s.id,
			s.student_id,
			st.first_name AS student_first_name,
			st.middle_name AS student_middle_name,
			st.last_name AS student_last_name,
			st.phone AS student_phone,
			st.group_id AS student_group_id,
			s.subject_id,
			su.name AS subject_name,
			s.professor_id,
			p.first_name AS professor_first_name,
			p.middle_name AS professor_middle_name,
			p.last_name AS professor_last_name,
			p.phone AS professor_phone,
			p.department AS professor_department,
			s.score
		FROM scores AS s
		LEFT JOIN students AS st ON st.id = s.student_id
		LEFT JOIN subjects AS su ON su.id = s.subject_id
		LEFT JOIN professors AS p ON p.id = s.professor_id
		WHERE s.student_id = )" + to_string(student->getId()) + " AND s.professor_id = " + to_string(professor->getId()) +
		" ORDER BY s.id";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

Vector<Score> ScoreRepository::findByStudentAndScore(Student* student, int score) const {

	if (student == nullptr)
		return Vector<Score>();

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			s.id,
			s.student_id,
			st.first_name AS student_first_name,
			st.middle_name AS student_middle_name,
			st.last_name AS student_last_name,
			st.phone AS student_phone,
			st.group_id AS student_group_id,
			s.subject_id,
			su.name AS subject_name,
			s.professor_id,
			p.first_name AS professor_first_name,
			p.middle_name AS professor_middle_name,
			p.last_name AS professor_last_name,
			p.phone AS professor_phone,
			p.department AS professor_department,
			s.score
		FROM scores AS s
		LEFT JOIN students AS st ON st.id = s.student_id
		LEFT JOIN subjects AS su ON su.id = s.subject_id
		LEFT JOIN professors AS p ON p.id = s.professor_id
		WHERE s.student_id = )" + to_string(student->getId()) + " AND s.score = " + to_string(score) +
		" ORDER BY s.id";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

Vector<Score> ScoreRepository::findBySubjectAndProfessor(Subject* subject, Professor* professor) const {

	if (subject == nullptr || professor == nullptr)
		return Vector<Score>();

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			s.id,
			s.student_id,
			st.first_name AS student_first_name,
			st.middle_name AS student_middle_name,
			st.last_name AS student_last_name,
			st.phone AS student_phone,
			st.group_id AS student_group_id,
			s.subject_id,
			su.name AS subject_name,
			s.professor_id,
			p.first_name AS professor_first_name,
			p.middle_name AS professor_middle_name,
			p.last_name AS professor_last_name,
			p.phone AS professor_phone,
			p.department AS professor_department,
			s.score
		FROM scores AS s
		LEFT JOIN students AS st ON st.id = s.student_id
		LEFT JOIN subjects AS su ON su.id = s.subject_id
		LEFT JOIN professors AS p ON p.id = s.professor_id
		WHERE s.subject_id = )" + to_string(subject->getId()) + " AND s.professor_id = " + to_string(professor->getId()) +
		" ORDER BY s.id";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

Vector<Score> ScoreRepository::findBySubjectAndScore(Subject* subject, int score) const {

	if (subject == nullptr)
		return Vector<Score>();

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			s.id,
			s.student_id,
			st.first_name AS student_first_name,
			st.middle_name AS student_middle_name,
			st.last_name AS student_last_name,
			st.phone AS student_phone,
			st.group_id AS student_group_id,
			s.subject_id,
			su.name AS subject_name,
			s.professor_id,
			p.first_name AS professor_first_name,
			p.middle_name AS professor_middle_name,
			p.last_name AS professor_last_name,
			p.phone AS professor_phone,
			p.department AS professor_department,
			s.score
		FROM scores AS s
		LEFT JOIN students AS st ON st.id = s.student_id
		LEFT JOIN subjects AS su ON su.id = s.subject_id
		LEFT JOIN professors AS p ON p.id = s.professor_id
		WHERE s.subject_id = )" + to_string(subject->getId()) + " AND s.score = " + to_string(score) +
		" ORDER BY s.id";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

Vector<Score> ScoreRepository::findByProfessorAndScore(Professor* professor, int score) const {

	if (professor == nullptr)
		return Vector<Score>();

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			s.id,
			s.student_id,
			st.first_name AS student_first_name,
			st.middle_name AS student_middle_name,
			st.last_name AS student_last_name,
			st.phone AS student_phone,
			st.group_id AS student_group_id,
			s.subject_id,
			su.name AS subject_name,
			s.professor_id,
			p.first_name AS professor_first_name,
			p.middle_name AS professor_middle_name,
			p.last_name AS professor_last_name,
			p.phone AS professor_phone,
			p.department AS professor_department,
			s.score
		FROM scores AS s
		LEFT JOIN students AS st ON st.id = s.student_id
		LEFT JOIN subjects AS su ON su.id = s.subject_id
		LEFT JOIN professors AS p ON p.id = s.professor_id
		WHERE s.professor_id = )" + to_string(professor->getId()) + " AND s.score = " + to_string(score) +
		" ORDER BY s.id";

	auto res = txn.exec(query);

	Vector<Score> scores;

	for (const auto row : res) {
		if (row["id"].is_null() ||
			row["student_id"].is_null() ||
			row["student_first_name"].is_null() ||
			row["student_middle_name"].is_null() ||
			row["student_last_name"].is_null() ||
			row["student_phone"].is_null() ||
			row["student_group_id"].is_null() ||
			row["subject_id"].is_null() ||
			row["subject_name"].is_null() ||
			row["professor_id"].is_null() ||
			row["professor_first_name"].is_null() ||
			row["professor_middle_name"].is_null() ||
			row["professor_last_name"].is_null() ||
			row["professor_phone"].is_null() ||
			row["professor_department"].is_null() ||
			row["score"].is_null())
			continue;

		Professor* professor = new Professor(Professor::Builder()
			.id(row["professor_id"].as<int>())
			.firstName(row["professor_first_name"].as<string>())
			.middleName(row["professor_middle_name"].as<string>())
			.lastName(row["professor_last_name"].as<string>())
			.phone(row["professor_phone"].as<string>())
			.department(row["professor_department"].as<int>())
			.build());

		Subject* subject = new Subject(Subject::Builder()
			.id(row["subject_id"].as<int>())
			.name(row["subject_name"].as<string>())
			.build());

		Student* student = new Student(Student::Builder()
			.id(row["student_id"].as<int>())
			.firstName(row["student_first_name"].as<string>())
			.middleName(row["student_middle_name"].as<string>())
			.lastName(row["student_last_name"].as<string>())
			.phone(row["student_phone"].as<string>())
			.group(nullptr)
			.build());

		Score* score = new Score(Score::Builder()
			.id(row["id"].as<int>())
			.professor(professor)
			.subject(subject)
			.student(student)
			.build());

		scores.add(score);
	}

	return scores;
}

void ScoreRepository::save(Score* score) const {

	if (score == nullptr)
		return;

	work txn(*const_cast<connection*>(conn));

	pqxx::result res;

	string query;

	if (score->getId() == 0) {
		query = R"(
			INSERT INTO scores (student_id, subject_id, professor_id, score)
			VALUES ()" +
			to_string(score->getStudent()->getId()) + ", " +
			to_string(score->getSubject()->getId()) + "," +
			to_string(score->getProfessor()->getId()) + "," +
			to_string(score->getScore()) + R"()
			RETURNING id)";
	}
	else {
		query = R"(
			INSERT INTO scores (id, student_id, subject_id, professor_id, score)
			VALUES ()" +
			to_string (score->getId()) + ", " +
			to_string(score->getStudent()->getId()) + ", " +
			to_string(score->getSubject()->getId()) + "," +
			to_string(score->getProfessor()->getId()) + "," +
			to_string(score->getScore()) + R"()
			ON CONFLICT (id) DO UPDATE SET
				student_id = EXCLUDED.student_id,
				subject_id = EXCLUDED.subject_id,
				professor_id = EXCLUDED.professor_id,
				score = EXCLUDED.score
			RETURNING id)";
	}

	res = txn.exec(query);

	if (!res.empty())
		score->setId(res[0]["id"].as<int>());

	txn.commit();
}

void ScoreRepository::deleteByObject(const Score* score) const {

	if (score == nullptr)
		return;

	work txn(*const_cast<connection*>(conn));

	string query = "DELETE FROM scores WHERE id = " + to_string(score->getId());

	txn.exec(query);

	txn.commit();
}

void ScoreRepository::deleteById(int id) const {

	work txn(*const_cast<connection*>(conn));

	string query = "DELETE FROM scores WHERE id = " + to_string(id);

	txn.exec(query);

	txn.commit();
}