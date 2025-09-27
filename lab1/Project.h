#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <regex>
#include <filesystem>
#include <windows.h>

#include "University.h"

using namespace std;
using namespace Universities;

namespace Projects {
	
	auto loadFile(const string& filePath) {
		ifstream fin(filePath);
		if (!fin) return;
		string line;
		while (getline(fin, line)) {
			if (line.empty()) continue;
			
		}
	}

	const std::string SAVED_FILES_PATH = "Saves/";

	bool existsProject(const string& name) {

		std::filesystem::path dir = SAVED_FILES_PATH + name;
		return std::filesystem::exists(dir) && std::filesystem::is_directory(dir);
	}

	University* getData(const string& name) {
		string projectPath = SAVED_FILES_PATH + name + "/";

		University* university = new University();

		string filenames[] = {	"students.txt",
								"groups.txt",
								"specialities.txt",
								"subjects.txt",
								"positions.txt",
								"responsibilities.txt",
								"professors.txt",
								"admins.txt" };

		for (string filename : filenames) {
			loadFile(projectPath + filename);
		}

		return university;
	}

	string writeName() {

		string name;
		cin >> name;

		name.erase(0, name.find_first_not_of(" \t\n\r"));
		name.erase(name.find_last_not_of(" \t\n\r") + 1);

		if (name == "q") {
			return name;
		}
		const regex Temple(R"([A-Za-z][A-Za-z0-9_]*)");
		if (std::regex_match(name, Temple))
			return name;

		cout << "Please, write correct project's name" << endl;
		_getch();
		return "";
	}

	University* createProject() {

		string name = "";

		while (name == "") {
			system("cls");
			cout << "Only letters, numbers and '_' can be used" << endl;
			cout << "The first character must be a letter" << endl << endl;
			cout << "Write \"q\" to exit" << endl;

			cout << "Project Name:" << endl;

			name = writeName();
			if (name == "q")
				return nullptr;

			if (existsProject(name)) {
				name = "";
				cout << "Project with this name already exists!" << endl;
				_getch();
			}
		}

		std::filesystem::path projectDir = SAVED_FILES_PATH + name;
		if (!std::filesystem::create_directories(projectDir)) {
			cout << "Error: cannot create project directory!" << endl;
			return nullptr;
		}

		vector<string> files = {
			"admins.txt", "students.txt", "professors.txt",
			"groups.txt", "specialities.txt", "subjects.txt",
			"positions.txt", "responsibilities.txt"
		};

		for (auto& f : files) {
			ofstream fout(projectDir.string() + "/" + f);
			fout.close();
		}

		cout << "Project created successfully!" << endl;
		_getch();
		return new University();
	}

	bool saveProject(const string& name, const University& uni) {

		if (!existsProject(name)) {
			cout << "Error: project does not exist!" << endl;
			return false;
		}

		string basePath = SAVED_FILES_PATH + name + "/";

		// Заглушки: пример записи
		auto saveFile = [&](const string& filename, const vector<string>& data) {
			ofstream fout(basePath + filename);
			if (!fout) return;
			for (auto& d : data) {
				fout << d << "\n";
			}
			};

		// пока фейковые данные, позже заменим на сериализацию uni
		saveFile("admins.txt", { "Admin1", "Admin2" });
		saveFile("students.txt", { "Student1", "Student2" });
		saveFile("professors.txt", { "Prof1" });
		saveFile("groups.txt", { "GroupA" });
		saveFile("specialities.txt", { "SpecX" });
		saveFile("subjects.txt", { "Math" });
		saveFile("positions.txt", { "Pos1" });
		saveFile("responsibilities.txt", { "Resp1" });

		cout << "Project saved!" << endl;
		return true;
	}

	University* openProject(const string& name) {
		if (!existsProject(name)) {
			cout << "Error: project does not exist!" << endl;
			return nullptr;
		}

		cout << "Opening project: " << name << endl;
		University* university = getData(name);

		cout << "Project opened!" << endl;
		return university;
	}
}
