#include <iostream>
#include <conio.h>

#include "University.h"
#include "Menu.h"
#include "Project.h"

using namespace Universities;
using namespace Menu;
using namespace Projects;


int main() {

	char choice;
	while (true) {
		system("cls");
		startMenu();
		choice = _getch();
		if (choice < '0' || choice > '2')
			continue;
		break;
	}

	switch (choice) {
	case '1': 
		createProject();
		break;
	case '2':
		openProject();
		break;
	case '0':
		return 0;
	}


	return 0;
}