#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

namespace Menu {
    void mainMenu() {
        cout << "=== Main Menu ===" << endl;
        cout << "1. Admins" << endl;
        cout << "2. Groups" << endl;
        cout << "3. Positions" << endl;
        cout << "4. Professors" << endl;
        cout << "5. Responsibilities" << endl;
        cout << "6. Scores" << endl;
        cout << "7. Specialities" << endl;
        cout << "8. Students" << endl;
        cout << "9. Subjects" << endl;
        cout << "----------------------" << endl;
        cout << "0. Exit" << endl;
    }

    void entityMenu(const string& entityName) {
        cout << "=== " << entityName << " Menu ===" << endl;
        cout << "1. Create new" << endl;
        cout << "2. View all" << endl;
        cout << "3. Search" << endl;
        cout << "0. Back" << endl;
    }

    void recordMenu() {
        cout << "1. Edit" << endl;
        cout << "2. Delete" << endl;
        cout << "0. Back" << endl;
    }

    void adminSearch() {
        cout << "=== Admin Search ===" << endl;
        cout << "1. find by id" << endl;
        cout << "2. find by first name" << endl;
        cout << "3. find by middle name" << endl;
        cout << "4. find by last name" << endl;
        cout << "5. find by position id" << endl;
        cout << "6. find by responsibility id" << endl;
        cout << "0. Back" << endl;
    }

    void groupSearch() {
        cout << "=== Group Search ===" << endl;
        cout << "1. find by id" << endl;
        cout << "2. find by name" << endl;
        cout << "3. find by speciality id" << endl;
        cout << "4. find by course" << endl;
        cout << "0. Back" << endl;
    }

    void positionSearch() {
        cout << "=== Position Search ===" << endl;
        cout << "1. find by id" << endl;
        cout << "2. find by name" << endl;
        cout << "0. Back" << endl;
    }

    void professorSearch() {
        cout << "=== Professor Search ===" << endl;
        cout << "1. find by id" << endl;
        cout << "2. find by first name" << endl;
        cout << "3. find by middle name" << endl;
        cout << "4. find by last name" << endl;
        cout << "5. find by department" << endl;
        cout << "0. Back" << endl;
    }

    void responsibilitySearch() {
        cout << "=== Responsibility Search ===" << endl;
        cout << "1. find by id" << endl;
        cout << "2. find by name" << endl;
        cout << "0. Back" << endl;
    }

    void scoreSearch() {
        cout << "=== Score Search ===" << endl;
        cout << "  1. find by id" << endl;
        cout << "  2. find by student id" << endl;
        cout << "  3. find by subject id" << endl;
        cout << "  4. find by professor id" << endl;
        cout << "  5. find by score" << endl;
        cout << "  6. find by student id and subject id" << endl;
        cout << "  7. find by student id and professor id" << endl;
        cout << "  8. find by student id and score" << endl;
        cout << "  9. find by subject id and professor id" << endl;
        cout << "'q'. find by subject id and score" << endl;
        cout << "'w'. find by professor id and score" << endl;
        cout << "  0. Back" << endl;
    }

    void specialitySearch() {
        cout << "=== Speciality Search ===" << endl;
        cout << "1. find by id" << endl;
        cout << "2. find by name" << endl;
        cout << "0. Back" << endl;
    }

    void studentSearch() {
        cout << "=== Student Search ===" << endl;
        cout << "1. find by id" << endl;
        cout << "2. find by first name" << endl;
        cout << "3. find by middle name" << endl;
        cout << "4. find by last name" << endl;
        cout << "5. find by group id" << endl;
        cout << "0. Back" << endl;
    }

    void subjectSearch() {
        cout << "=== Subject Search ===" << endl;
        cout << "1. find by id" << endl;
        cout << "2. find by name" << endl;
        cout << "0. Back" << endl;
    }

    char validChoice(char min = '0', char max = '9', void (*menu) () = mainMenu) {
        char choice;

        menu();
        while (true) {
            choice = _getch();
            if (choice < min || choice > max)
                continue;
            break;
        }

        return choice;
    }

    char validChoiceAction(const string& entityName) {
        char choice;

        entityMenu(entityName);
        while (true) {
            choice = _getch();
            if (choice < '0' || choice > '3')
                continue;
            break;
        }

        return choice;
    }
}
