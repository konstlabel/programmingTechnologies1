#include "SubjectService.h"

using namespace Subjects;
using namespace Vectors;
using namespace std;

SubjectDto* SubjectService::toDto(const Subject* subject) const {

	SubjectDto* dto = new SubjectDto();

	dto->id = subject->getId();
	dto->name = subject->getName();

	return dto;
}

SubjectService::SubjectService(SubjectRepository* subjectRepository) {

	if (subjectRepository == nullptr) {
		throw std::invalid_argument("AdminRepository pointer is null");
	}

	this->subjectRepository = subjectRepository;

	cout << "SubjectService default constructor called" << endl;
}

SubjectDto* SubjectService::findById(int id) const {

	auto subject = subjectRepository->findById(id);
	if (subject == nullptr)
		return nullptr;

	SubjectDto* dto = toDto(subject);
	delete subject;
	return dto;
}

Vector<SubjectDto> SubjectService::findAll() const {

	Vector<Subject> subjects = subjectRepository->findAll();

	Vector<SubjectDto> subjectDtos;

	if (subjects.isEmpty())
		return subjectDtos;

	for (Subject* subject : subjects) {
		subjectDtos.add(toDto(subject));
	}

	return subjectDtos;
}

Vector<SubjectDto> SubjectService::findByName(const std::string& name) const {

	Vector<Subject> subjects = subjectRepository->findByName(name);

	Vector<SubjectDto> subjectDtos;

	if (subjects.isEmpty())
		return subjectDtos;

	for (Subject* subject : subjects) {
		subjectDtos.add(toDto(subject));
	}

	return subjectDtos;
}

bool SubjectService::createSubject(const SubjectDto* subjectDto) const {

	if (subjectDto == nullptr)
		throw std::invalid_argument("SubjectDto pointer is null");

	std::string name = trim(subjectDto->name);
	if (name.empty())
		throw std::invalid_argument("Empty subjectDto's name is not allowed");

	Subject* subject = new Subject(Subject::Builder()
		.id(0)
		.name(name)
		.build());

	subjectRepository->save(subject);
	delete subject;
	return true;
}

bool SubjectService::deleteSubject(int id) const {

	if (subjectRepository->findById(id) == nullptr)
		return false;

	subjectRepository->deleteById(id);
	return true;

}

bool SubjectService::updateSubject(const SubjectDto* subjectDto) const {

	if (subjectDto == nullptr)
		throw std::invalid_argument("SubjectDto pointer is null");

	if (subjectDto->id < 1)
		throw std::invalid_argument("SubjectDto's id less than 1");

	std::string name = trim(subjectDto->name);
	if (name.empty())
		throw std::invalid_argument("Empty subjectDto's name is not allowed");

	Subject* subject = new Subject(Subject::Builder()
		.id(subjectDto->id)
		.name(name)
		.build());

	subjectRepository->save(subject);
	delete subject;
	return true;
}
