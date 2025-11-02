#include "GroupRepository.h"

#include <iostream>
#include <pqxx/pqxx>

using namespace Groups;
using namespace Specialities;
using namespace Vectors;
using namespace std;
using namespace pqxx;

GroupRepository::GroupRepository(connection* conn) : Repository(conn) {

    cout << "GroupRepository all arguments constructor called." << endl;
}

Group* GroupRepository::findById(int id) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
		SELECT 
			g.id,
			g.name,
			g.course,
			g.speciality_id,
			s.name AS speciality_name
		FROM Student_Groups AS g
		LEFT JOIN specialities AS s ON s.id = g.speciality_id
		WHERE g.id = )" + to_string(id));

    auto res = txn.exec(query);

    if (res.empty())
        return nullptr;

    if (res[0]["speciality_id"].is_null() ||
        res[0]["speciality_name"].is_null() ||
        res[0]["id"].is_null() ||
        res[0]["name"].is_null() ||
        res[0]["course"].is_null())
        return nullptr;

    Speciality* speciality = new Speciality(Speciality::Builder()
        .id(res[0]["speciality_id"].as<int>())
        .name(res[0]["speciality_name"].as<string>())
        .build());

    Group* group = new Group(Group::Builder()
        .id(res[0]["id"].as<int>())
        .name(res[0]["name"].as<string>())
		.course(res[0]["course"].as<int>())
        .speciality(speciality)
        .build());

    return group;
}

Vector<Group> GroupRepository::findAll() const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			g.id,
			g.name,
			g.course,
			g.speciality_id,
			s.name AS speciality_name
		FROM Student_Groups AS g
		LEFT JOIN specialities AS s ON s.id = g.speciality_id
        ORDER BY g.id)";

    auto res = txn.exec(query);

    Vector<Group> groups;

    for (auto const& row : res) {
        if (row["speciality_id"].is_null() ||
            row["speciality_name"].is_null() ||
            row["id"].is_null() ||
            row["name"].is_null() ||
            row["course"].is_null())
            continue;

        Speciality* speciality = nullptr;
        if (!row["speciality_id"].is_null() && !row["speciality_name"].is_null()) {
            speciality = new Speciality(Speciality::Builder()
                .id(row["speciality_id"].as<int>())
                .name(row["speciality_name"].as<string>())
                .build());
        }

        Group* group = new Group(Group::Builder()
            .id(row["id"].as<int>())
            .name(row["name"].as<string>())
            .course(row["course"].as<int>())
            .speciality(speciality)
            .build());

        groups.add(group);
    }

    return groups;
}

Vector<Group> GroupRepository::findByName(const string& name) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
        SELECT 
			g.id,
			g.name,
			g.course,
			g.speciality_id,
			s.name AS speciality_name
		FROM Student_Groups AS g
		LEFT JOIN specialities AS s ON s.id = g.speciality_id
        WHERE g.name = )" + txn.quote(name) +
        " ORDER BY g.id");

    auto res = txn.exec(query);

    Vector<Group> groups;

    for (auto const& row : res) {
        if (row["speciality_id"].is_null() ||
            row["speciality_name"].is_null() ||
            row["id"].is_null() ||
            row["name"].is_null() ||
            row["course"].is_null())
            continue;

        Speciality* speciality = nullptr;
        if (!row["speciality_id"].is_null() && !row["speciality_name"].is_null()) {
            speciality = new Speciality(Speciality::Builder()
                .id(row["speciality_id"].as<int>())
                .name(row["speciality_name"].as<string>())
                .build());
        }

        Group* group = new Group(Group::Builder()
            .id(row["id"].as<int>())
            .name(row["name"].as<string>())
            .course(row["course"].as<int>())
            .speciality(speciality)
            .build());

        groups.add(group);
    }

    return groups;
}

Vector<Group> GroupRepository::findBySpeciality(Speciality* speciality) const {

    if (speciality == nullptr)
        return Vector<Group>();

    read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
            SELECT 
				g.id,
				g.name,
				g.course,
				g.speciality_id,
				s.name AS speciality_name
			FROM Student_Groups AS g
			LEFT JOIN specialities AS s ON s.id = g.speciality_id
        WHERE g.speciality_id = )" + to_string(speciality->getId()) +
        " ORDER BY g.id");

    auto res = txn.exec(query);

    Vector<Group> groups;

    for (auto const& row : res) {
        if (row["speciality_id"].is_null() ||
            row["speciality_name"].is_null() ||
            row["id"].is_null() ||
            row["name"].is_null() ||
            row["course"].is_null())
            continue;

        Speciality* speciality = nullptr;
        if (!row["speciality_id"].is_null() && !row["speciality_name"].is_null()) {
            speciality = new Speciality(Speciality::Builder()
                .id(row["speciality_id"].as<int>())
                .name(row["speciality_name"].as<string>())
                .build());
        }

        Group* group = new Group(Group::Builder()
            .id(row["id"].as<int>())
            .name(row["name"].as<string>())
            .course(row["course"].as<int>())
            .speciality(speciality)
            .build());

        groups.add(group);
    }

    return groups;
}

Vector<Group> GroupRepository::findByCourse(int course) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = (R"(
        SELECT 
			g.id,
			g.name,
			g.course,
			g.speciality_id,
			s.name AS speciality_name
		FROM Student_Groups AS g
		LEFT JOIN specialities AS s ON s.id = g.speciality_id
        WHERE g.course = )" + to_string(course) +
        " ORDER BY g.id");

    auto res = txn.exec(query);

    Vector<Group> groups;

    for (auto const& row : res) {
        if (row["speciality_id"].is_null() ||
            row["speciality_name"].is_null() ||
            row["id"].is_null() ||
            row["name"].is_null() ||
            row["course"].is_null())
            continue;

        Speciality* speciality = nullptr;
        if (!row["speciality_id"].is_null() && !row["speciality_name"].is_null()) {
            speciality = new Speciality(Speciality::Builder()
                .id(row["speciality_id"].as<int>())
                .name(row["speciality_name"].as<string>())
                .build());
        }

        Group* group = new Group(Group::Builder()
            .id(row["id"].as<int>())
            .name(row["name"].as<string>())
            .course(row["course"].as<int>())
            .speciality(speciality)
            .build());

        groups.add(group);
    }

    return groups;
}

void GroupRepository::save(Group* group) const {

    if (group == nullptr)
        return;

    work txn(*const_cast<connection*>(conn));

    pqxx::result res;

    string query;

    if (group->getId() == 0) {
        query = (R"(
			INSERT INTO Student_Groups (name, speciality_id, course)
			VALUES ()" + txn.quote(group->getName()) + ", " +
            to_string(group->getSpeciality()->getId()) + ", " +
            to_string(group->getCourse()) + ") RETURNING id");
    }
    else {
        query = (R"(
			INSERT INTO Student_Groups (id, name, speciality_id, course)
			VALUES ()" + to_string(group->getId()) + ", " +
            txn.quote(group->getName()) + ", " +
            to_string(group->getSpeciality()->getId()) + ", " +
            to_string(group->getCourse()) + R"()
            ON CONFLICT (id) DO UPDATE SET
            name = EXCLUDED.name,
            speciality_id = EXCLUDED.speciality_id,
            course = EXCLUDED.course
            RETURNING id)");
    }

    res = txn.exec(query);

    if (!res.empty())
        group->setId(res[0]["id"].as<int>());

    txn.commit();
}


void GroupRepository::deleteByObject(const Group* group) const {

    if (group == nullptr)
        return;

    work txn(*const_cast<connection*>(conn));
    
    string query = (R"(
            DELETE FROM Student_Groups 
            WHERE id = )" + to_string(group->getId()));

    txn.exec(query);
	
    txn.commit();
}

void GroupRepository::deleteById(int id) const {

    work txn(*const_cast<connection*>(conn));

    string query = (R"(
            DELETE FROM Student_Groups 
            WHERE id = )" + to_string(id));

    txn.exec(query);

    txn.commit();
}