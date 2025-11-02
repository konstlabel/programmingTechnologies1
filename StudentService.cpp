#include "StudentService.h"
#include <regex>
#include <iostream>

using namespace Students;
using namespace Groups;
using namespace Vectors;
using namespace std;

StudentDto* StudentService::toDto(const Student* student) const {

	StudentDto* dto = new StudentDto();

	dto->id = student->getId();
	dto->firstName = student->getFirstName();
	dto->middleName = student->getMiddleName();
	dto->lastName = student->getLastName();
	dto->phone = student->getPhone();
	dto->groupId = (student->getGroup() == nullptr) ? -1 : student->getGroup()->getId();

	return dto;
}

StudentService::StudentService(StudentRepository* studentRepository, GroupRepository* groupRepository) {

	if (studentRepository == nullptr) {
		throw std::invalid_argument("StudentRepository pointer is null");
	}
	if (groupRepository == nullptr) {
		throw std::invalid_argument("GroupRepository pointer is null");
	}

	this->studentRepository = studentRepository;
	this->groupRepository = groupRepository;
	cout << "StudentService default constructor called" << endl;
}

StudentDto* StudentService::findById(int id) const {

	auto student = studentRepository->findById(id);
	if (student == nullptr)
		return nullptr;

	StudentDto* dto = toDto(student);
	delete student;
	return dto;
}

Vector<StudentDto> StudentService::findAll() const {

	Vector<Student> students = studentRepository->findAll();

	Vector<StudentDto> studentDtos;

	if (students.isEmpty())
		return studentDtos;

	for (Student* student : students) {
		studentDtos.add(toDto(student));
	}

	return studentDtos;
}

Vector<StudentDto> StudentService::findByFirstName(const std::string& firstName) const {

	Vector<Student> students = studentRepository->findByFirstName(firstName);

	Vector<StudentDto> studentDtos;

	if (students.isEmpty()) {
		return studentDtos;
	}

	for (Student* student : students) {
		studentDtos.add(toDto(student));
	}

	return studentDtos;
}

Vector<StudentDto> StudentService::findByMiddleName(const std::string& middleName) const {

	Vector<Student> students = studentRepository->findByMiddleName(middleName);

	Vector<StudentDto> studentDtos;

	if (students.isEmpty()) {
		return studentDtos;
	}

	for (Student* student : students) {
		studentDtos.add(toDto(student));
	}

	return studentDtos;
}

Vector<StudentDto> StudentService::findByLastName(const std::string& lastName) const {

	Vector<Student> students = studentRepository->findByLastName(lastName);

	Vector<StudentDto> studentDtos;

	if (students.isEmpty()) {
		return studentDtos;
	}

	for (Student* student : students) {
		studentDtos.add(toDto(student));
	}

	return studentDtos;
}

Vector<StudentDto> StudentService::findByGroupId(int groupId) const {

	Vector<StudentDto> studentDtos;

	Group* group = groupRepository->findById(groupId);

	if (group == nullptr)
		studentDtos;

	Vector<Student> students = studentRepository->findByGroup(group);

	if (students.isEmpty()) {
		return studentDtos;
	}

	for (Student* student : students) {
		studentDtos.add(toDto(student));
	}

	delete group;
	return studentDtos;
}

bool StudentService::createStudent(const StudentDto* studentDto) const {

	if (studentDto == nullptr)
		throw std::invalid_argument("StudentDto pointer is null");

	std::string firstName = trim(studentDto->firstName);
	if (firstName.empty())
		throw std::invalid_argument("Empty studentDto's first_name is not allowed");

	std::string middleName = trim(studentDto->middleName);
	if (middleName.empty())
		throw std::invalid_argument("Empty studentDto's middle_name is not allowed");

	std::string lastName = trim(studentDto->lastName);
	if (lastName.empty())
		throw std::invalid_argument("Empty studentDto's last_name is not allowed");

	std::string phone = trim(studentDto->phone);
	if (phone.empty())
		throw std::invalid_argument("Empty studentDto's phone is not allowed");
	const std::regex phoneTemplate(R"(^\+7\d{10}$)");
	if (!std::regex_match(phone, phoneTemplate))
		throw std::invalid_argument("Invalid studentDto's phone format");

	Group* group = groupRepository->findById(studentDto->groupId);
	if (group == nullptr)
		throw std::invalid_argument("Error found group by id");


	Student* student = new Student(Student::Builder()
		.id(0)
		.firstName(firstName)
		.middleName(middleName)
		.lastName(lastName)
		.phone(phone)
		.group(group)
		.build());

	studentRepository->save(student);
	delete student;
	return true;
}

bool StudentService::deleteStudent(int id) const {

	if (studentRepository->findById(id) == nullptr)
		return false;

	studentRepository->deleteById(id);
	return true;
}

bool StudentService::updateStudent(const StudentDto* studentDto) const {

	if (studentDto == nullptr)
		throw std::invalid_argument("StudentDto pointer is null");

	Student* student = studentRepository->findById(studentDto->id);

	if (student == nullptr)
		return false;

	if (!studentDto->firstName.empty()) {
		std::string firstName = trim(studentDto->firstName);
		if (firstName.empty())
			throw std::invalid_argument("Empty studentDto's first_name is not allowed");

		student->setFirstName(firstName);
	}

	if (!studentDto->middleName.empty()) {
		std::string middleName = trim(studentDto->middleName);
		if (middleName.empty())
			throw std::invalid_argument("Empty studentDto's middle_name is not allowed");

		student->setMiddleName(middleName);
	}

	if (!studentDto->lastName.empty()) {
		std::string lastName = trim(studentDto->lastName);
		if (lastName.empty())
			throw std::invalid_argument("Empty studentDto's last_name is not allowed");

		student->setLastName(lastName);
	}

	if (!studentDto->lastName.empty()) {
		std::string phone = trim(studentDto->phone);
		if (phone.empty())
			throw std::invalid_argument("Empty studentDto's phone is not allowed");
		const std::regex phoneTemplate(R"(^\+7\d{10}$)");
		if (!std::regex_match(phone, phoneTemplate))
			throw std::invalid_argument("Invalid studentDto's phone format");

		student->setPhone(phone);
	}

	if (studentDto->groupId != 0) {
		Group* group = groupRepository->findById(studentDto->groupId);
		if (group == nullptr)
			throw std::invalid_argument("Error found position by id");

		student->setGroup(group);
	}

	studentRepository->save(student);
	delete student;
	return true;
}