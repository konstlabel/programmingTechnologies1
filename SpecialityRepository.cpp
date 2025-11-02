#include "SpecialityRepository.h"

#include <iostream>
#include <pqxx/pqxx>

using namespace Specialities;
using namespace Vectors;
using namespace std;
using namespace pqxx;

SpecialityRepository::SpecialityRepository(pqxx::connection* conn) : Repository(conn) {

	cout << "SpecialityRepository all arguments constructor called." << endl;
}

Speciality* SpecialityRepository::findById(int id) const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			id,
			name
		FROM Specialities
		WHERE id = )" + to_string(id);

	auto res = txn.exec(query);

	if (res.empty())
		return nullptr;

	if (res[0]["id"].is_null() ||
		res[0]["name"].is_null())
		return nullptr;

	Speciality* speciality = new Speciality(Speciality::Builder()
		.id(res[0]["id"].as<int>())
		.name(res[0]["name"].as<string>())
		.build());

	return speciality;
}

Vector<Speciality> SpecialityRepository::findAll() const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
		SELECT 
			id,
			name
		FROM Specialities
		)";

	auto res = txn.exec(query);

	Vector<Speciality> specialities;

	for (const auto& row : res) {

		if (row["id"].is_null() ||
			row["name"].is_null())
			continue;

		Speciality* speciality = new Speciality(Speciality::Builder()
			.id(row["id"].as<int>())
			.name(row["name"].as<string>())
			.build());

		specialities.add(speciality);
	}

	return specialities;
}

Vector<Speciality> SpecialityRepository::findByName(const string& name) const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = R"(
			SELECT 
				id,
				name
			FROM Specialities
			WHERE name = )" + txn.quote(name);

	auto res = txn.exec(query);

	Vector<Speciality> specialities;

	for (const auto& row : res) {

		if (row["id"].is_null() ||
			row["name"].is_null())
			continue;

		Speciality* speciality = new Speciality(Speciality::Builder()
			.id(row["id"].as<int>())
			.name(row["name"].as<string>())
			.build());

		specialities.add(speciality);
	}

	return specialities;
}

void SpecialityRepository::save(Speciality* speciality) const {

	if (speciality == nullptr)
		return;

	work txn(*const_cast<connection*>(conn));

	pqxx::result res;

	string query;

	if (speciality->getId() == 0) {
		query = R"(
			INSERT INTO specialities (name)
			VALUES ()" + txn.quote(speciality->getName()) + ") RETURNING id";

		res = txn.exec(query);
	}
	else {
		query = R"(
			INSERT INTO specialities (id, name)
			VALUES ()" +
			to_string(speciality->getId()) + ", " +
			txn.quote(speciality->getName()) + R"() 
			ON CONFLICT (id) DO UPDATE SET
				name = EXCLUDED.name
			RETURNING id)";
	}

	res = txn.exec(query);

	if (!res.empty())
		speciality->setId(res[0]["id"].as<int>());

	txn.commit();
}

void SpecialityRepository::deleteByObject(const Speciality* speciality) const {

	if (speciality == nullptr)
		return;

	work txn(*const_cast<connection*>(conn));

	string query = R"(
			DELETE FROM Specialities
			WHERE id = )" + to_string(speciality->getId());

	txn.exec(query);

	txn.commit();
}

void SpecialityRepository::deleteById(int id) const {

	work txn(*const_cast<connection*>(conn));

	string query = R"(
			DELETE FROM Specialities
			WHERE id = )" + to_string(id);

	txn.exec(query);

	txn.commit();
}