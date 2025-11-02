#include "SubjectRepository.h"

#include <iostream>
#include <pqxx/pqxx>

using namespace Subjects;
using namespace Vectors;
using namespace std;
using namespace pqxx;

SubjectRepository::SubjectRepository(pqxx::connection* conn) : Repository(conn) {

	cout << "SubjectRepository all arguments constructor called." << endl;
}

Subject* SubjectRepository::findById(int id) const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
			SELECT 
				id,
				name
			FROM subjects
			WHERE id = )" + to_string(id);

	auto res = txn.exec(query);

	if (res.empty())
		return nullptr;

	if (res[0]["id"].is_null() ||
		res[0]["name"].is_null())
		return nullptr;

	Subject* subject = new Subject(Subject::Builder()
		.id(res[0]["id"].as<int>())
		.name(res[0]["name"].as<string>())
		.build());

	txn.commit();
	return subject;
}

Vector<Subject> SubjectRepository::findAll() const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
			SELECT 
				id,
				name
			FROM subjects
		)";

	auto res = txn.exec(query);

	Vector<Subject> subjects;

	for (const auto& row : res) {

		if (row["id"].is_null() ||
			row["name"].is_null())
			continue;

		Subject* subject = new Subject(Subject::Builder()
			.id(row["id"].as<int>())
			.name(row["name"].as<string>())
			.build());

		subjects.add(subject);
	}

	return subjects;
}

Vector<Subject> SubjectRepository::findByName(const std::string& name) const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
			SELECT 
				id,
				name
			FROM subjects
			WHERE name = )" + txn.quote(name);

	auto res = txn.exec(query);

	Vector<Subject> subjects;

	for (const auto& row : res) {

		if (row["id"].is_null() ||
			row["name"].is_null())
			continue;

		Subject* subject = new Subject(Subject::Builder()
			.id(row["id"].as<int>())
			.name(row["name"].as<string>())
			.build());

		subjects.add(subject);
	}
	txn.commit();
	return subjects;
}

void SubjectRepository::save(Subject* subject) const {

	if (subject == nullptr)
		return;

	work txn(*const_cast<connection*>(conn));

	pqxx::result res;

	string query;

	if (subject->getId() == 0) {
		query = R"(
			INSERT INTO subjects (name)
			VALUES ()" + txn.quote(subject->getName()) + ") RETURNING id";
	}
	else {
		query = R"(
			INSERT INTO subjects (id, name)
			VALUES ()" +
			to_string(subject->getId()) + ", " +
			txn.quote(subject->getName()) + R"()
			ON CONFLICT (id) DO UPDATE SET
				name = EXCLUDED.name
			RETURNING id)";
	}

	res = txn.exec(query);

	if (!res.empty())
		subject->setId(res[0]["id"].as<int>());

	txn.commit();
}

void SubjectRepository::deleteByObject(const Subject* subject) const {

	work txn(*const_cast<connection*>(conn));
	
	string query = R"(
			DELETE FROM subjects
			WHERE id = )" + to_string(subject->getId());

	txn.exec(query);

	txn.commit();
}

void SubjectRepository::deleteById(int id) const {

	work txn(*const_cast<connection*>(conn));

	string query = R"(
			DELETE FROM subjects
			WHERE id = )" + to_string(id);

	txn.exec(query);

	txn.commit();
}