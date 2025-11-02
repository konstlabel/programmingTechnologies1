#include "AdminRepository.h"

#include <iostream>
#include <pqxx/pqxx>

using namespace Admins;
using namespace Positions;
using namespace Responsibilities;
using namespace Vectors;
using namespace std;
using namespace pqxx;

AdminRepository::AdminRepository(connection* conn) : Repository(conn) {
	
	cout << "AdminRepository all arguments constructor called." << endl;
}

Admin* AdminRepository::findById(int id) const {

	read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
        SELECT 
			a.id,
			a.first_name,
			a.middle_name,
			a.last_name,	
			a.phone,
			a.position_id,
			p.name AS position_name,
			a.responsibility_id,
			r.name AS responsibility_name
		FROM admins AS a
		LEFT JOIN positions AS p ON p.id = a.position_id
		LEFT JOIN responsibilities AS r ON r.id = a.responsibility_id
		WHERE a.id = )" + to_string(id));

	auto res = txn.exec(query);

	if (res.empty())
		return nullptr;

	if (res[0]["position_id"].is_null() || 
			res[0]["position_name"].is_null() ||
			res[0]["responsibility_id"].is_null() ||
			res[0]["responsibility_name"].is_null() ||
			res[0]["id"].is_null() ||
			res[0]["first_name"].is_null() ||
			res[0]["middle_name"].is_null() ||
			res[0]["last_name"].is_null() ||
			res[0]["phone"].is_null())
		return nullptr;

	Position* position = new Position(Position::Builder()
		.id(res[0]["position_id"].as<int>())
		.name(res[0]["position_name"].as<string>())
		.build());
	
	Responsibility* responsibility = new Responsibility(Responsibility::Builder()
		.id(res[0]["responsibility_id"].as<int>())
		.name(res[0]["responsibility_name"].as<string>())
		.build());

	Admin* admin = new Admin(Admin::Builder()
		.id(res[0]["id"].as<int>())
		.firstName(res[0]["first_name"].as<string>())
		.middleName(res[0]["middle_name"].as<string>())
		.lastName(res[0]["last_name"].as<string>())
		.phone(res[0]["phone"].as<string>())
		.position(position)
		.responsibility(responsibility)
		.build());

	return admin;
}

Vector<Admin> AdminRepository::findAll() const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
        SELECT 
			a.id,
			a.first_name,
			a.middle_name,
			a.last_name,	
			a.phone,
			a.position_id,
			p.name AS position_name,
			a.responsibility_id,
			r.name AS responsibility_name
		FROM admins AS a
		LEFT JOIN positions AS p ON p.id = a.position_id
		LEFT JOIN responsibilities AS r ON r.id = a.responsibility_id)");

    auto res = txn.exec(query);

    Vector<Admin> admins;

    for (auto const& row : res) {
        if (row["position_id"].is_null() ||
            row["position_name"].is_null() ||
            row["responsibility_id"].is_null() ||
            row["responsibility_name"].is_null() ||
            row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null())
            continue;

        Position* position = nullptr;
        if (!row["position_id"].is_null() && !row["position_name"].is_null()) {
            position = new Position(Position::Builder()
                .id(row["position_id"].as<int>())
                .name(row["position_name"].as<string>())
                .build());
        }

        Responsibility* responsibility = nullptr;
        if (!row["responsibility_id"].is_null() && !row["responsibility_name"].is_null()) {
            responsibility = new Responsibility(Responsibility::Builder()
                .id(row["responsibility_id"].as<int>())
                .name(row["responsibility_name"].as<string>())
                .build());
        }

        Admin* admin = new Admin(Admin::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .position(position)
            .responsibility(responsibility)
            .build());

        admins.add(admin);
    }

    return admins;
}

Vector<Admin> AdminRepository::findByFirstName(const string& firstName) const {

	read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
	    SELECT 
		    a.id,
            a.first_name,
            a.middle_name,
            a.last_name,	
            a.phone,
            a.position_id,
            p.name AS position_name,
            a.responsibility_id,
            r.name AS responsibility_name
	    FROM admins AS a
	    LEFT JOIN positions AS p ON p.id = a.position_id
	    LEFT JOIN responsibilities AS r ON r.id = a.responsibility_id
	    WHERE a.first_name = )" + txn.quote(firstName) +
        "ORDER BY a.id");

	auto res = txn.exec(query);

    Vector<Admin> admins;

    for (auto const& row : res) {
        if (row["position_id"].is_null() ||
            row["position_name"].is_null() ||
            row["responsibility_id"].is_null() ||
            row["responsibility_name"].is_null() ||
            row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null())
            continue;

        Position* position = nullptr;
        if (!row["position_id"].is_null() && !row["position_name"].is_null()) {
            position = new Position(Position::Builder()
                .id(row["position_id"].as<int>())
                .name(row["position_name"].as<string>())
                .build());
        }

        Responsibility* responsibility = nullptr;
        if (!row["responsibility_id"].is_null() && !row["responsibility_name"].is_null()) {
            responsibility = new Responsibility(Responsibility::Builder()
                .id(row["responsibility_id"].as<int>())
                .name(row["responsibility_name"].as<string>())
                .build());
        }

        Admin* admin = new Admin(Admin::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .position(position)
            .responsibility(responsibility)
            .build());

        admins.add(admin);
    }

    return admins;
}

Vector<Admin> AdminRepository::findByMiddleName(const string& middleName) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
	    SELECT 
		    a.id,
            a.first_name,
            a.middle_name,
            a.last_name,	
            a.phone,
            a.position_id,
            p.name AS position_name,
            a.responsibility_id,
            r.name AS responsibility_name
	    FROM admins AS a
	    LEFT JOIN positions AS p ON p.id = a.position_id
	    LEFT JOIN responsibilities AS r ON r.id = a.responsibility_id
	    WHERE a.middle_name = )" + txn.quote(middleName) +
        "ORDER BY a.id");

    auto res = txn.exec(query);

    Vector<Admin> admins;

    for (auto const& row : res) {
        if (row["position_id"].is_null() ||
            row["position_name"].is_null() ||
            row["responsibility_id"].is_null() ||
            row["responsibility_name"].is_null() ||
            row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null())
            continue;

        Position* position = nullptr;
        if (!row["position_id"].is_null() && !row["position_name"].is_null()) {
            position = new Position(Position::Builder()
                .id(row["position_id"].as<int>())
                .name(row["position_name"].as<string>())
                .build());
        }

        Responsibility* responsibility = nullptr;
        if (!row["responsibility_id"].is_null() && !row["responsibility_name"].is_null()) {
            responsibility = new Responsibility(Responsibility::Builder()
                .id(row["responsibility_id"].as<int>())
                .name(row["responsibility_name"].as<string>())
                .build());
        }

        Admin* admin = new Admin(Admin::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .position(position)
            .responsibility(responsibility)
            .build());

        admins.add(admin);
    }

    return admins;
}

Vector<Admin> AdminRepository::findByLastName(const string& lastName) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
	    SELECT 
		    a.id,
            a.first_name,
            a.middle_name,
            a.last_name,	
            a.phone,
            a.position_id,
            p.name AS position_name,
            a.responsibility_id,
            r.name AS responsibility_name
	    FROM admins AS a
	    LEFT JOIN positions AS p ON p.id = a.position_id
	    LEFT JOIN responsibilities AS r ON r.id = a.responsibility_id
	    WHERE a.last_name = )" + txn.quote(lastName) +
        "ORDER BY a.id");

    auto res = txn.exec(query);

    Vector<Admin> admins;

    for (auto const& row : res) {
        if (row["position_id"].is_null() ||
            row["position_name"].is_null() ||
            row["responsibility_id"].is_null() ||
            row["responsibility_name"].is_null() ||
            row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null())
            continue;

        Position* position = nullptr;
        if (!row["position_id"].is_null() && !row["position_name"].is_null()) {
            position = new Position(Position::Builder()
                .id(row["position_id"].as<int>())
                .name(row["position_name"].as<string>())
                .build());
        }

        Responsibility* responsibility = nullptr;
        if (!row["responsibility_id"].is_null() && !row["responsibility_name"].is_null()) {
            responsibility = new Responsibility(Responsibility::Builder()
                .id(row["responsibility_id"].as<int>())
                .name(row["responsibility_name"].as<string>())
                .build());
        }

        Admin* admin = new Admin(Admin::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .position(position)
            .responsibility(responsibility)
            .build());

        admins.add(admin);
    }

    return admins;
}

Vector<Admin> AdminRepository::findByPosition(Position* position) const {

    if (position == nullptr)
        return Vector<Admin>();

    read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
	    SELECT 
		    a.id,
            a.first_name,
            a.middle_name,
            a.last_name,	
            a.phone,
            a.position_id,
            p.name AS position_name,
            a.responsibility_id,
            r.name AS responsibility_name
	    FROM admins AS a
	    LEFT JOIN positions AS p ON p.id = a.position_id
	    LEFT JOIN responsibilities AS r ON r.id = a.responsibility_id
	    WHERE a.position_id = )" + to_string(position->getId()) +
        "ORDER BY a.id");

    auto res = txn.exec(query);

    Vector<Admin> admins;

    for (auto const& row : res) {
        if (row["position_id"].is_null() ||
            row["position_name"].is_null() ||
            row["responsibility_id"].is_null() ||
            row["responsibility_name"].is_null() ||
            row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null())
            continue;

        Position* position = nullptr;
        if (!row["position_id"].is_null() && !row["position_name"].is_null()) {
            position = new Position(Position::Builder()
                .id(row["position_id"].as<int>())
                .name(row["position_name"].as<string>())
                .build());
        }

        Responsibility* responsibility = nullptr;
        if (!row["responsibility_id"].is_null() && !row["responsibility_name"].is_null()) {
            responsibility = new Responsibility(Responsibility::Builder()
                .id(row["responsibility_id"].as<int>())
                .name(row["responsibility_name"].as<string>())
                .build());
        }

        Admin* admin = new Admin(Admin::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .position(position)
            .responsibility(responsibility)
            .build());

        admins.add(admin);
    }

    return admins;
}

Vector<Admin> AdminRepository::findByResponsibility(Responsibility* responsibility) const {

    if (responsibility == nullptr)
        return Vector<Admin>();

    read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
	    SELECT 
		    a.id,
            a.first_name,
            a.middle_name,
            a.last_name,	
            a.phone,
            a.position_id,
            p.name AS position_name,
            a.responsibility_id,
            r.name AS responsibility_name
	    FROM admins AS a
	    LEFT JOIN positions AS p ON p.id = a.position_id
	    LEFT JOIN responsibilities AS r ON r.id = a.responsibility_id
	    WHERE a.responsibility_id = )" + to_string(responsibility->getId()) +
        "ORDER BY a.id");

    auto res = txn.exec(query);

    Vector<Admin> admins;

    for (auto const& row : res) {
        if (row["position_id"].is_null() ||
            row["position_name"].is_null() ||
            row["responsibility_id"].is_null() ||
            row["responsibility_name"].is_null() ||
            row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null())
            continue;

        Position* position = nullptr;
        if (!row["position_id"].is_null() && !row["position_name"].is_null()) {
            position = new Position(Position::Builder()
                .id(row["position_id"].as<int>())
                .name(row["position_name"].as<string>())
                .build());
        }

        Responsibility* responsibility = nullptr;
        if (!row["responsibility_id"].is_null() && !row["responsibility_name"].is_null()) {
            responsibility = new Responsibility(Responsibility::Builder()
                .id(row["responsibility_id"].as<int>())
                .name(row["responsibility_name"].as<string>())
                .build());
        }

        Admin* admin = new Admin(Admin::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .position(position)
            .responsibility(responsibility)
            .build());

        admins.add(admin);
    }

    return admins;
}

void AdminRepository::save(Admin* admin) const {

    if (admin == nullptr)
        return;

    work txn(*const_cast<connection*>(conn));

    pqxx::result res;

    string query;
    
    if (admin->getId() == 0) {
        query = (R"(
            INSERT INTO admins (first_name, middle_name, last_name, phone, position_id, responsibility_id)
		    VALUES ()" +
            txn.quote(admin->getFirstName()) + ", " +
            txn.quote(admin->getMiddleName()) + ", " + 
            txn.quote(admin->getLastName()) + ", " +
            to_string(admin->getPosition()->getId()) + ", " + 
            to_string(admin->getResponsibility()->getId()) + ") RETURNING id");
    }
    else {
        query = (R"(
            INSERT INTO admins (id, first_name, middle_name, last_name, phone, position_id, responsibility_id)
		    VALUES ()" + 
            to_string(admin->getId()) + ", " + 
            txn.quote(admin->getFirstName()) + ", " +
            txn.quote(admin->getMiddleName()) + ", " + 
            txn.quote(admin->getLastName()) + ", " +
            to_string(admin->getPosition()->getId()) + ", " +
            to_string(admin->getResponsibility()->getId()) + R"()
            ON CONFLICT (id) DO UPDATE SET
                first_name = EXCLUDED.first_name,
			    middle_name = EXCLUDED.middle_name,
			    last_name = EXCLUDED.last_name,
			    phone = EXCLUDED.phone,
			    position_id = EXCLUDED.position_id,
			    responsibility_id = EXCLUDED.responsibility_id
		    RETURNING id
        )");
    }

    res = txn.exec(query);

    if (!res.empty())
        admin->setId(res[0]["id"].as<int>());

    txn.commit();
}

void AdminRepository::deleteByObject(const Admin* admin) const {

    if (admin == nullptr)
        return;

    work txn(*const_cast<connection*>(conn));

    string query = (R"(
	    DELETE FROM admins 
        WHERE id = )" + to_string(admin->getId()) + "");

    txn.exec(query);

    txn.commit();
}

void AdminRepository::deleteById(int id) const {

    work txn(*const_cast<connection*>(conn));

    string query = (R"(
	    DELETE FROM admins 
        WHERE id = )" + to_string(id) + "");

    txn.exec(query);

    txn.commit();
}