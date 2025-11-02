#include "ProfessorRepository.h"

#include <iostream>
#include <pqxx/pqxx>

using namespace Professors;
using namespace Vectors;
using namespace std;
using namespace pqxx;

ProfessorRepository::ProfessorRepository(connection* conn) : Repository(conn) {

    cout << "ProfessorRepository all arguments constructor called." << endl;
}

Professor* ProfessorRepository::findById(int id) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
			SELECT 
				p.id,
				p.first_name,
				p.middle_name,
				p.last_name,	
				p.phone,
				p.department
			FROM professors AS p
			WHERE p.id = )" + to_string(id);

    auto res = txn.exec(query);

    if (res.empty())
        return nullptr;

    if (res[0]["id"].is_null() ||
        res[0]["first_name"].is_null() ||
        res[0]["middle_name"].is_null() ||
        res[0]["last_name"].is_null() ||
        res[0]["phone"].is_null() ||
        res[0]["department"].is_null())
        return nullptr;

    Professor* professor = new Professor(Professor::Builder()
        .id(res[0]["id"].as<int>())
        .firstName(res[0]["first_name"].as<string>())
        .middleName(res[0]["middle_name"].as<string>())
        .lastName(res[0]["last_name"].as<string>())
        .phone(res[0]["phone"].as<string>())
        .department(res[0]["department"].as<int>())
        .build());

    return professor;
}

Vector<Professor> ProfessorRepository::findAll() const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			p.id,
			p.first_name,
			p.middle_name,
			p.last_name,	
			p.phone,
			p.department
		FROM professors AS p
        ORDER BY p.id
    )";

    auto res = txn.exec(query);

    Vector<Professor> professors;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["department"].is_null())
            continue;

        Professor* professor = new Professor(Professor::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .department(row["department"].as<int>())
            .build());

        professors.add(professor);
    }

    return professors;
}

Vector<Professor> ProfessorRepository::findByFirstName(const string& firstName) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			p.id,
			p.first_name,
			p.middle_name,
			p.last_name,	
			p.phone,
			p.department
		FROM professors AS p
        WHERE p.first_name = )" + txn.quote(firstName) +
        " ORDER BY p.id";

    auto res = txn.exec(query);

    Vector<Professor> professors;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["department"].is_null())
            continue;

        Professor* professor = new Professor(Professor::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .department(row["department"].as<int>())
            .build());

        professors.add(professor);
    }

    return professors;
}

Vector<Professor> ProfessorRepository::findByMiddleName(const string& middleName) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			p.id,
			p.first_name,
			p.middle_name,
			p.last_name,	
			p.phone,
			p.department
		FROM professors AS p
        WHERE p.middle_name = )" + txn.quote(middleName) +
        " ORDER BY p.id";

    auto res = txn.exec(query);

    Vector<Professor> professors;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["department"].is_null())
            continue;

        Professor* professor = new Professor(Professor::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .department(row["department"].as<int>())
            .build());

        professors.add(professor);
    }

    return professors;
}

Vector<Professor> ProfessorRepository::findByLastName(const string& lastName) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			p.id,
			p.first_name,
			p.middle_name,
			p.last_name,	
			p.phone,
			p.department
		FROM professors AS p
        WHERE p.last_name = )" + txn.quote(lastName) +
        " ORDER BY p.id";

    auto res = txn.exec(query);

    Vector<Professor> professors;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["department"].is_null())
            continue;

        Professor* professor = new Professor(Professor::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .department(row["department"].as<int>())
            .build());

        professors.add(professor);
    }

    return professors;
}

Vector<Professor> ProfessorRepository::findByPhone(const string& phone) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			p.id,
			p.first_name,
			p.middle_name,
			p.last_name,	
			p.phone,
			p.department
		FROM professors AS p
        WHERE p.phone = )" + txn.quote(phone) +
        " ORDER BY p.id";

    auto res = txn.exec(query);

    Vector<Professor> professors;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["department"].is_null())
            continue;

        Professor* professor = new Professor(Professor::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .department(row["department"].as<int>())
            .build());

        professors.add(professor);
    }

    return professors;
}


Vector<Professor> ProfessorRepository::findByDepartment(int department) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			p.id,
			p.first_name,
			p.middle_name,
			p.last_name,	
			p.phone,
			p.department
		FROM professors AS p
        WHERE p.department = )" + to_string(department) +
        " ORDER BY p.id";

    auto res = txn.exec(query);

    Vector<Professor> professors;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["department"].is_null())
            continue;

        Professor* professor = new Professor(Professor::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .department(row["department"].as<int>())
            .build());

        professors.add(professor);
    }

    return professors;
}

void ProfessorRepository::save(Professor* professor) const {

    if (professor == nullptr)
        return;

    work txn(*const_cast<connection*>(conn));

    pqxx::result res;

    string query;

    if (professor->getId() == 0) {
        query = R"(
            INSERT INTO professors (first_name, middle_name, last_name, phone, department)
	        VALUES ()" +
            txn.quote(professor->getFirstName()) + ", " +
            txn.quote(professor->getMiddleName()) + ", " +
            txn.quote(professor->getLastName()) + ", " +
            txn.quote(professor->getPhone()) + ", " +
            to_string(professor->getDepartment()) + R"() 
            RETURNING id)";
    }
    else {
        query = R"(
            INSERT INTO professors (id, first_name, middle_name, last_name, phone, department)
	        VALUES ()" +
            to_string(professor->getId()) + ", " +
            txn.quote(professor->getFirstName()) + ", " +
            txn.quote(professor->getMiddleName()) + ", " +
            txn.quote(professor->getLastName()) + ", " +
            txn.quote(professor->getPhone()) + ", " +
            to_string(professor->getDepartment()) + R"() 
            ON CONFLICT (id) DO UPDATE SET
				first_name = EXCLUDED.first_name,
				middle_name = EXCLUDED.middle_name,
				last_name = EXCLUDED.last_name,
				phone = EXCLUDED.phone,
				department = EXCLUDED.department
			RETURNING id)";
    }

    res = txn.exec(query);

    if (!res.empty())
        professor->setId(res[0]["id"].as<int>());

    txn.commit();
}


void ProfessorRepository::deleteByObject(const Professor* professor) const {

    if (professor == nullptr)
        return;

    work txn(*const_cast<connection*>(conn));
    
    string query = R"(
            DELETE FROM professors 
            WHERE id = )" + to_string(professor->getId());

    txn.exec(query);

    txn.commit();
}

void ProfessorRepository::deleteById(int id) const {

    work txn(*const_cast<connection*>(conn));

    string query = R"(
            DELETE FROM professors 
            WHERE id = )" + to_string(id);

    txn.exec(query);

    txn.commit();
}