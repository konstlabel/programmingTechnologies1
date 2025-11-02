#include "PositionRepository.h"

#include <iostream>
#include <pqxx/pqxx>

using namespace Positions;
using namespace Vectors;
using namespace std;
using namespace pqxx;

PositionRepository::PositionRepository(pqxx::connection* conn) : Repository(conn) {

	std::cout << "PositionRepository all arguments constructor called." << std::endl;
}

Position* PositionRepository::findById(int id) const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = (R"(
		SELECT 
			id,
			name
		FROM positions
		WHERE id = )" + to_string(id));

	auto res = txn.exec(query);
	
	if (res.empty())
		return nullptr;
	
	if (res[0]["id"].is_null() ||
		res[0]["name"].is_null())
		return nullptr;
	
	Position* position = new Position(Position::Builder()
		.id(res[0]["id"].as<int>())
		.name(res[0]["name"].as<std::string>())
		.build());
	
	return position;
}

Vector<Position> PositionRepository::findAll() const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = (R"(
		SELECT 
			id,
			name
		FROM positions)");

	auto res = txn.exec(query);

	Vector<Position> positions;

	for (const auto& row : res) {

		if (row["id"].is_null() ||
			row["name"].is_null())
			continue;

		Position* position = new Position(Position::Builder()
			.id(row["id"].as<int>())
			.name(row["name"].as<std::string>())
			.build());

		positions.add(position);
	}

	return positions;
}

Vector<Position> PositionRepository::findByName(const std::string& name) const {

	read_transaction txn(*const_cast<connection*>(conn));

	string query = (R"(
		SELECT 
			id,
			name
		FROM positions
		WHERE name = )" + txn.quote(name));

	auto res = txn.exec(query);

	Vector<Position> positions;

	for (const auto& row : res) {

		if (row["id"].is_null() ||
			row["name"].is_null())
			continue;

		Position* position = new Position(Position::Builder()
			.id(row["id"].as<int>())
			.name(row["name"].as<std::string>())
			.build());

		positions.add(position);
	}

	return positions;
}

void PositionRepository::save(Position* position) const {

	if (position == nullptr)
		return;

	work txn(*const_cast<connection*>(conn));

	pqxx::result res;

	string query;

	if (position->getId() == 0) {
		query = (R"(
			INSERT INTO positions (name)
			VALUES ()" + txn.quote(position->getName()) + ") RETURNING id");
	}
	else {
		query = (R"(
			INSERT INTO positions (id, name)
			VALUES ()" + 
			to_string(position->getId()) + ", " +
			txn.quote(position->getName()) + R"()
			ON CONFLICT (id) DO UPDATE SET
			name = EXCLUDED.name
			RETURNING id)");
	}

	res = txn.exec(query);

	if (!res.empty())
		position->setId(res[0]["id"].as<int>());

	txn.commit();
}

void PositionRepository::deleteByObject(const Position* position) const {

	if (position == nullptr)
		return;

	work txn(*const_cast<connection*>(conn));
	
	string query = (R"(
			DELETE FROM positions
			WHERE id = $1
		)" + to_string(position->getId()));

	txn.exec(query);
	
	txn.commit();
}

void PositionRepository::deleteById(int id) const {

	work txn(*const_cast<connection*>(conn));

	string query = (R"(
			DELETE FROM positions
			WHERE id = $1
		)" + to_string(id));

	txn.exec(query);

	txn.commit();
}