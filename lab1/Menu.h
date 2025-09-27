#pragma once
#include <iostream>

using namespace std;

namespace Menu {

    void startMenu() {
        cout << "=== Start Menu ===" << endl;
        cout << "1. Create new project" << endl;
        cout << "2. Open existing project" << endl;
        cout << "0. Exit program" << endl;
    }

    void mainMenu() {
        cout << "=== Main Menu ===" << endl;
        cout << "1. Admins" << endl;
        cout << "2. Students" << endl;
        cout << "3. Professors" << endl;
        cout << "4. Groups" << endl;
        cout << "5. Specialities" << endl;
        cout << "6. Subjects" << endl;
        cout << "7. Positions" << endl;
        cout << "8. Responsibilities" << endl;
        cout << "----------------------" << endl;
        cout << "9. Save changes" << endl;
        cout << "0. Back" << endl;
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

    void confirmMenu(const string& action) {
        cout << "Are you sure you want to " << action << "?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
    }
}
