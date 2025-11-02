#include "StudentRepository.h"

#include <iostream>
#include <pqxx/pqxx>

using namespace Students;
using namespace Groups;
using namespace Vectors;
using namespace std;
using namespace pqxx;

StudentRepository::StudentRepository(connection* conn) : Repository(conn) {

    cout << "StudentRepository all arguments constructor called." << endl;
}

Student* StudentRepository::findById(int id) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
		SELECT 
			s.id,
			s.first_name,
			s.middle_name,
			s.last_name,	
			s.phone,
			s.group_id,
            g.name AS group_name
		FROM students AS s
        LEFT JOIN groups AS g ON g.id = s.group_id
		WHERE s.id = )" + to_string(id);

    auto res = txn.exec(query);

    if (res.empty())
        return nullptr;

    if (res[0]["id"].is_null() ||
        res[0]["first_name"].is_null() ||
        res[0]["middle_name"].is_null() ||
        res[0]["last_name"].is_null() ||
        res[0]["phone"].is_null() ||
        res[0]["group_id"].is_null() ||
		res[0]["group_name"].is_null())
        return nullptr;

    Group* group = new Group(Group::Builder()
        .id(res[0]["group_id"].as<int>())
        .name(res[0]["group_name"].as<string>())
        .course(0)
        .speciality(nullptr)
		.build());

    Student* student = new Student(Student::Builder()
        .id(res[0]["id"].as<int>())
        .firstName(res[0]["first_name"].as<string>())
        .middleName(res[0]["middle_name"].as<string>())
        .lastName(res[0]["last_name"].as<string>())
        .phone(res[0]["phone"].as<string>())
        .group(group)
        .build());

    return student;
}

Vector<Student> StudentRepository::findAll() const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			s.id,
			s.first_name,
			s.middle_name,
			s.last_name,	
			s.phone,
			s.group_id,
            g.name AS group_name
		FROM students AS s
        LEFT JOIN groups AS g ON g.id = s.group_id
        ORDER BY s.id
    )";

    auto res = txn.exec(query);

    Vector<Student> students;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["group_id"].is_null() ||
            row["group_name"].is_null())
            continue;

        Group* group = new Group(Group::Builder()
            .id(row["group_id"].as<int>())
            .name(row["group_name"].as<string>())
            .course(0)
            .speciality(nullptr)
            .build());

        Student* student = new Student(Student::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .group(group)
            .build());

        students.add(student);
    }

    return students;
}

Vector<Student> StudentRepository::findByFirstName(const std::string& firstName) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			s.id,
			s.first_name,
			s.middle_name,
			s.last_name,	
			s.phone,
			s.group_id,
            g.name AS group_name
		FROM students AS s
        LEFT JOIN groups AS g ON g.id = s.group_id
        WHERE s.first_name = )" + txn.quote(firstName) +
        " ORDER BY s.id";

    auto res = txn.exec(query);

    Vector<Student> students;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["group_id"].is_null() ||
            row["group_name"].is_null())
            continue;

        Group* group = new Group(Group::Builder()
            .id(row["group_id"].as<int>())
            .name(row["group_name"].as<string>())
            .course(0)
            .speciality(nullptr)
            .build());

        Student* student = new Student(Student::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .group(group)
            .build());

        students.add(student);
    }

    return students;
}

Vector<Student> StudentRepository::findByMiddleName(const std::string& middleName) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			s.id,
			s.first_name,
			s.middle_name,
			s.last_name,	
			s.phone,
			s.group_id,
            g.name AS group_name
		FROM students AS s
        LEFT JOIN groups AS g ON g.id = s.group_id
        WHERE s.middle_name = )" + txn.quote(middleName) +
        " ORDER BY s.id";
    
    auto res = txn.exec(query);

    Vector<Student> students;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["group_id"].is_null() ||
            row["group_name"].is_null())
            continue;

        Group* group = new Group(Group::Builder()
            .id(row["group_id"].as<int>())
            .name(row["group_name"].as<string>())
            .course(0)
            .speciality(nullptr)
            .build());

        Student* student = new Student(Student::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .group(group)
            .build());

        students.add(student);
    }

    return students;
}

Vector<Student> StudentRepository::findByLastName(const std::string& lastName) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			s.id,
			s.first_name,
			s.middle_name,
			s.last_name,	
			s.phone,
			s.group_id,
            g.name AS group_name
		FROM students AS s
        LEFT JOIN groups AS g ON g.id = s.group_id
        WHERE s.last_name = )" + txn.quote(lastName) +
        " ORDER BY s.id";

    auto res = txn.exec(query);

    Vector<Student> students;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["group_id"].is_null() ||
            row["group_name"].is_null())
            continue;

        Group* group = new Group(Group::Builder()
            .id(row["group_id"].as<int>())
            .name(row["group_name"].as<string>())
            .course(0)
            .speciality(nullptr)
            .build());

        Student* student = new Student(Student::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .group(group)
            .build());

        students.add(student);
    }

    return students;
}

Vector<Student> StudentRepository::findByPhone(const string& phone) const {

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			s.id,
			s.first_name,
			s.middle_name,
			s.last_name,	
			s.phone,
			s.group_id,
            g.name AS group_name
		FROM students AS s
        LEFT JOIN groups AS g ON g.id = s.group_id
        WHERE s.phone = )" + txn.quote(phone) +
        " ORDER BY s.id";

    auto res = txn.exec(query);

    Vector<Student> students;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["group_id"].is_null() ||
            row["group_name"].is_null())
            continue;

        Group* group = new Group(Group::Builder()
            .id(row["group_id"].as<int>())
            .name(row["group_name"].as<string>())
            .course(0)
            .speciality(nullptr)
            .build());

        Student* student = new Student(Student::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .group(group)
            .build());

        students.add(student);
    }

    return students;
}


Vector<Student> StudentRepository::findByGroup(Group* group) const {

    if (group == nullptr)
        return Vector<Student>();

    read_transaction txn(*const_cast<connection*>(conn));

    string query = R"(
        SELECT 
			s.id,
			s.first_name,
			s.middle_name,
			s.last_name,	
			s.phone,
			s.group_id,
            g.name AS group_name
		FROM students AS s
        LEFT JOIN groups AS g ON g.id = s.group_id
        WHERE s.group_id = )" + to_string(group->getId()) +
        " ORDER BY s.id";

    auto res = txn.exec(query);

    Vector<Student> students;

    for (auto const& row : res) {
        if (row["id"].is_null() ||
            row["first_name"].is_null() ||
            row["middle_name"].is_null() ||
            row["last_name"].is_null() ||
            row["phone"].is_null() ||
            row["group_id"].is_null() ||
            row["group_name"].is_null())
            continue;

        Group* group = new Group(Group::Builder()
            .id(row["group_id"].as<int>())
            .name(row["group_name"].as<string>())
            .course(0)
            .speciality(nullptr)
            .build());

        Student* student = new Student(Student::Builder()
            .id(row["id"].as<int>())
            .firstName(row["first_name"].as<string>())
            .middleName(row["middle_name"].as<string>())
            .lastName(row["last_name"].as<string>())
            .phone(row["phone"].as<string>())
            .group(group)
            .build());

        students.add(student);
    }

    return students;
}

void StudentRepository::save(Student* student) const {

    if (student == nullptr)
        return;

    work txn(*const_cast<connection*>(conn));

    pqxx::result res;

    string query;

    if (student->getId() == 0) {
        query = R"(
			INSERT INTO students (first_name, middle_name, last_name, phone, group_id)
			VALUES ()" +
            txn.quote(student->getFirstName()) + ", " +
            txn.quote(student->getMiddleName()) + ", " +
            txn.quote(student->getLastName()) + ", " +
            txn.quote(student->getPhone()) + ", " +
            to_string(student->getGroup()->getId()) + ", " +
            ") RETURNING id";
    }
    else {
        query = R"(
			INSERT INTO students (id, first_name, middle_name, last_name, phone, group_id)
			VALUES ()" +
            to_string(student->getId()) + ", " +
            txn.quote(student->getFirstName()) + ", " +
            txn.quote(student->getMiddleName()) + ", " +
            txn.quote(student->getLastName()) + ", " +
            txn.quote(student->getPhone()) + ", " +
            to_string(student->getGroup()->getId()) + ", " + R"()
            ON CONFLICT (id) DO UPDATE SET
				first_name = EXCLUDED.first_name,
				middle_name = EXCLUDED.middle_name,
				last_name = EXCLUDED.last_name,
				phone = EXCLUDED.phone,
				group_id = EXCLUDED.group_id
			RETURNING id)";
    }

    res = txn.exec(query);

    if (!res.empty())
        student->setId(res[0]["id"].as<int>());

    txn.commit();
}

void StudentRepository::deleteByObject(const Student* student) const {

    if (student == nullptr)
        return;

    work txn(*const_cast<connection*>(conn));

    string query = R"(
            DELETE FROM students 
            WHERE id = )" + to_string(student->getId());

    txn.exec(query);

    txn.commit();
}

void StudentRepository::deleteById(int id) const {

    work txn(*const_cast<connection*>(conn));

    string query = R"(
            DELETE FROM students 
            WHERE id = )" + to_string(id);

    txn.exec(query);

    txn.commit();
}