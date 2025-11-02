#pragma once
#include "University.h"
#include <regex>
#include <iostream>
#include <limits>

using namespace Universities;

namespace Creates {
    bool isValidName(const std::string& str) {
        return std::regex_match(str, std::regex("^[A-Za-z]+$"));
    }

    bool isValidPhone(const std::string& str) {
        return std::regex_match(str, std::regex("^[+0-9 ()-]+$"));
    }

    int inputInt(const std::string& prompt, int minValue = 0, int maxValue = 999999999) {
        int value;
        while (true) {
            std::cout << prompt;
            if (std::cin >> value && value >= minValue && value <= maxValue)
                return value;

            std::cout << "Invalid input. Please enter an integer from "
                << minValue << " to " << maxValue << ".\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::string inputString(const std::string& prompt, bool (*validator)(const std::string&)) {
        std::string value;
        while (true) {
            std::cout << prompt;
            std::getline(std::cin >> std::ws, value);

            if (validator(value))
                return value;

            std::cout << "Invalid input. Please try again.\n";
        }
    }

    AdminDto* createAdmin(int id) {

        system("cls");
        AdminDto* dto = new AdminDto();

        dto->id = id;
        dto->firstName = inputString("Enter first name: ", isValidName);
        dto->middleName = inputString("Enter middle name: ", isValidName);
        dto->lastName = inputString("Enter last name: ", isValidName);
        dto->phone = inputString("Enter phone number: ", isValidPhone);
        dto->positionId = inputInt("Enter position id: ", 0);
        dto->responsibilityId = inputInt("Enter responsibility id: ", 0);

        return dto;
    }

    GroupDto* createGroup(int id) {

        system("cls");
        GroupDto* dto = new GroupDto();

        dto->id = id;
        dto->name = to_string(inputInt("Enter name (1000-9999): ", 1000, 9999));
        dto->specialityId = inputInt("Enter speciality id: ", 0);
        dto->course = inputInt("Enter course (1-5): ", 1, 5);

        return dto;
    }

    PositionDto* createPosition(int id) {

        system("cls");
        PositionDto* dto = new PositionDto();

        dto->id = id;
        dto->name = inputString("Enter name: ", isValidName);

        return dto;
    }

    ProfessorDto* createProfessor(int id) {

        system("cls");
        ProfessorDto* dto = new ProfessorDto();

        dto->id = id;
        dto->firstName = inputString("Enter first name: ", isValidName);
        dto->middleName = inputString("Enter middle name: ", isValidName);
        dto->lastName = inputString("Enter last name: ", isValidName);
        dto->phone = inputString("Enter phone number: ", isValidPhone);
        dto->department = inputInt("Enter department: ", 0);

        return dto;
    }

    ResponsibilityDto* createResponsibility(int id) {

        system("cls");
        ResponsibilityDto* dto = new ResponsibilityDto();

        dto->id = id;
        dto->name = inputString("Enter name: ", isValidName);

        return dto;
    }

    ScoreDto* createScore(int id) {

        system("cls");
        ScoreDto* dto = new ScoreDto();

        dto->id = id;
        dto->studentId = inputInt("Enter student id: ", 0);
        dto->subjectId = inputInt("Enter subject id: ", 0);
        dto->professorId = inputInt("Enter professor id: ", 0);
        dto->score = inputInt("Enter score: ", 0);

        return dto;
    }

    SpecialityDto* createSpeciality(int id) {

        system("cls");
        SpecialityDto* dto = new SpecialityDto();

        dto->id = id;
        dto->name = inputString("Enter name: ", isValidName);

        return dto;
    }

    StudentDto* createStudent(int id) {

        system("cls");
        StudentDto* dto = new StudentDto();

        dto->id = id;
        dto->firstName = inputString("Enter first name: ", isValidName);
        dto->middleName = inputString("Enter middle name: ", isValidName);
        dto->lastName = inputString("Enter last name: ", isValidName);
        dto->phone = inputString("Enter phone number: ", isValidPhone);
        dto->groupId = inputInt("Enter group id: ", 0);

        return dto;
    }

    SubjectDto* createSubject(int id) {

        system("cls");
        SubjectDto* dto = new SubjectDto();

        dto->id = id;
        dto->name = inputString("Enter name: ", isValidName);

        return dto;
    }

}
