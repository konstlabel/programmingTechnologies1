#include "ResponsibilityRepository.h"

#include <iostream>
#include <pqxx/pqxx>

using namespace Responsibilities;
using namespace Vectors;
using namespace std;
using namespace pqxx;

ResponsibilityRepository::ResponsibilityRepository(pqxx::connection* conn) : Repository(conn) {

	cout << "ResponsibilityRepository all arguments constructor called." << endl;
}

Responsibility* ResponsibilityRepository::findById(int id) const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			id,
			name
		FROM responsibilities
		WHERE id = )" + to_string(id);

	auto res = txn.exec(query);

	if (res.empty())
		return nullptr;

	if (res[0]["id"].is_null() ||
		res[0]["name"].is_null())
		return nullptr;

	Responsibility* responsibility = new Responsibility(Responsibility::Builder()
		.id(res[0]["id"].as<int>())
		.name(res[0]["name"].as<string>())
		.build());

	txn.commit();
	return responsibility;
}

Vector<Responsibility> ResponsibilityRepository::findAll() const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			id,
			name
		FROM responsibilities)";

	auto res = txn.exec(query);

	Vector<Responsibility> responsibilities;

	for (const auto& row : res) {

		if (row["id"].is_null() ||
			row["name"].is_null())
			continue;

		Responsibility* responsibility = new Responsibility(Responsibility::Builder()
			.id(row["id"].as<int>())
			.name(row["name"].as<string>())
			.build());

		responsibilities.add(responsibility);
	}
	
	return responsibilities;
}

Vector<Responsibility> ResponsibilityRepository::findByName(const string& name) const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			id,
			name
		FROM responsibilities
		WHERE name = )" + txn.quote(name) + 
		"ORDER BY id";

	auto res = txn.exec(query);

	Vector<Responsibility> responsibilities;

	for (const auto& row : res) {

		if (row["id"].is_null() ||
			row["name"].is_null())
			continue;

		Responsibility* responsibility = new Responsibility(Responsibility::Builder()
			.id(row["id"].as<int>())
			.name(row["name"].as<string>())
			.build());

		responsibilities.add(responsibility);
	}

	return responsibilities;
}

void ResponsibilityRepository::save(Responsibility* responsibility) const {

	if (responsibility == nullptr)
		return;

	work txn(*const_cast<connection*>(conn));

	pqxx::result res;

	string query;

	if (responsibility->getId() == 0) {
		query = R"(
			INSERT INTO responsibilities (name)
			VALUES ()" +
			txn.quote(responsibility->getName()) + ") RETURNING id";
	}
	else {
		query = R"(
			INSERT INTO responsibilities (id, name)
			VALUES ()" +
			to_string(responsibility->getId()) + ", " +
			txn.quote(responsibility->getName()) + R"()
			ON CONFLICT (id) DO UPDATE SET
			name = EXCLUDED.name
			RETURNING id)";
	}

	res = txn.exec(query);
	
	if (!res.empty())
		responsibility->setId(res[0]["id"].as<int>());

	txn.commit();
}

void ResponsibilityRepository::deleteByObject(const Responsibility* responsibility) const {

	if (responsibility == nullptr)
		return;

	work txn(*const_cast<connection*>(conn));

	string query = R"(
			DELETE FROM responsibilities
			WHERE id = )" + to_string(responsibility->getId());

	txn.exec(query);

	txn.commit();
}

void ResponsibilityRepository::deleteById(int id) const {

	work txn(*const_cast<connection*>(conn));

	string query = R"(
			DELETE FROM responsibilities
			WHERE id = )" + to_string(id);

	txn.exec(query);

	txn.commit();
}