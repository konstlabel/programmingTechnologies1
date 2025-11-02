#include "Libraries.h"

using namespace std;
using namespace Universities;
using namespace Menu;
using namespace Creates;

int main() {
    try {
        pqxx::connection conn = pqxx::connection("dbname=PT1 user=postgres password=Kivilag123 host=localhost port=5432");
        if (conn.is_open()) {
            std::cout << "Connected to database: " << conn.dbname() << std::endl;
        }
        else {
            std::cout << "Failed to connect." << std::endl;
            return 1;
        }

        bool exit = false;
        University* university = new University(&conn);

        while (!exit) {
            system("cls");
            char choice = validChoice('0', '9', mainMenu);

            switch (choice) {
            // ----------- ADMIN -----------
            case '1': {
                system("cls");
                choice = validChoiceAction("Admin");
                switch (choice) {

                // Create
                case '1': {
                    try {
                        AdminDto* dto = createAdmin(0);
                        university->adminService()->createAdmin(dto);
                        delete dto;
                    }
                    catch (const std::exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                }

                // All
                case '2': {
                    university->adminDtos(university->adminService()->findAll());
                    
                    printDtos(university->adminDtos());

                    break;
                }

                // Search
                case '3': {
                    system("cls");
                    choice = validChoice('0', '6', adminSearch);
                    switch (choice) {

                    // id
                    case '1': {
                        int id = inputInt("Enter id: ", 1);
                        AdminDto* dto = university->adminService()->findById(id);
                        if (dto == nullptr) {
                            cout << "Admin with id " << id << " not found" << endl;
                            break;
                        }

                        Vector<Vector<std::string>> table;
                        table.add(new Vector<std::string>(dto->toPrintable()));
                        Vector<std::string> headers = AdminDto::headers();
                        printMarkdownTable(headers, table);

                        delete dto;

                        choice = validChoice('0', '2', recordMenu);
                        switch (choice) {

                        // Edit
                        case '1': {
                            AdminDto* newDto = createAdmin(id);
                            university->adminService()->updateAdmin(newDto);
                            delete newDto;

                            break;
                        }
                        // Delete
                        case '2': {
                            university->adminService()->deleteAdmin(id);
                            
                            break;
                        }
                        default:
                            break;
                        }
                        break;
                    }

                    // first name
                    case '2': {
                        std::string name = inputString("Enter first name: ", isValidName);
                        university->adminDtos(university->adminService()->findByFirstName(name));

                        printDtos(university->adminDtos());

                        break;
                    }

                    // middle name
                    case '3': {
                        std::string name = inputString("Enter middle name: ", isValidName);
                        university->adminDtos(university->adminService()->findByMiddleName(name));

                        printDtos(university->adminDtos());

                        break;
                    }

                    // last name
                    case '4': {
                        std::string name = inputString("Enter last name: ", isValidName);
                        university->adminDtos(university->adminService()->findByLastName(name));

                        printDtos(university->adminDtos());
                        
                        break;
                    }

                    // position
                    case '5': {
                        int positionId = inputInt("Enter position id: ");
                        university->adminDtos(university->adminService()->findByPositionId(positionId));

                        printDtos(university->adminDtos());

                        break;
                    }

                    // responsibility
                    case '6': {
                        int responsibilityId = inputInt("Enter responsibility id: ");
                        university->adminDtos(university->adminService()->findByResponsibilityId(responsibilityId));

                        printDtos(university->adminDtos());

                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }

            // ----------- GROUP -----------
            case '2': {
                system("cls");
                choice = validChoiceAction("Groups");
                switch (choice) {

                // Create
                case '1': {
                    try {
                        GroupDto* dto = createGroup(0);
                        university->groupService()->createGroup(dto);
                        delete dto;
                    }
                    catch (const std::exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                }

                // All
                case '2': {
                    university->groupDtos(university->groupService()->findAll());

                    printDtos(university->groupDtos());

                    break;
                }

                // Search
                case '3': {
                    system("cls");
                    choice = validChoice('0', '4', groupSearch);
                    switch (choice) {

                    // id
                    case '1': {
                        int id = inputInt("Enter id: ", 1);
                        GroupDto* dto = university->groupService()->findById(id);
                        if (dto == nullptr) {
                            cout << "Group with id " << id << " not found" << endl;
                            break;
                        }

                        Vector<Vector<std::string>> table;
                        table.add(new Vector<std::string>(dto->toPrintable()));
                        Vector<std::string> headers = GroupDto::headers();
                        printMarkdownTable(headers, table);

                        delete dto;

                        choice = validChoice('0', '2', recordMenu);
                        switch (choice) {

                        // Edit
                        case '1': {
                            GroupDto* newDto = createGroup(id);
                            university->groupService()->updateGroup(newDto);
                            delete newDto;

                            break;
                        }

                        // Delete
                        case '2': {
                            university->groupService()->deleteGroup(id);

                            break;
                        }
                        default:
                            break;
                        }
                        break;
                    }

                    // name
                    case '2': {
                        std::string name = inputString("Enter name: ", isValidName);
                        university->groupDtos(university->groupService()->findByName(name));

                        printDtos(university->groupDtos());

                        break;
                    }

                    // speciality
                    case '3': {
                        int specialityId = inputInt("Enter speciality id: ");
                        university->groupDtos(university->groupService()->findBySpecialityId(specialityId));

                        printDtos(university->groupDtos());


                        break;
                    }

                    // course
                    case '4': {
                        int course = inputInt("Enter course: ", 1, 5);
                        university->groupDtos(university->groupService()->findByCourse(course));

                        printDtos(university->groupDtos());

                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }
               
            // ----------- Positions -----------
            case '3': {
                system("cls");
                choice = validChoiceAction("Positions");
                switch (choice) {

                // Create
                case '1': {
                    try {
                        PositionDto* dto = createPosition(0);
                        university->positionService()->createPosition(dto);
                        delete dto;
                    }
                    catch (const std::exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                }

                // All
                case '2': {
                    university->positionDtos(university->positionService()->findAll());

                    printDtos(university->positionDtos());

                    break;
                }

                // Search
                case '3': {
                    system("cls");
                    choice = validChoice('0', '2', positionSearch);
                    switch (choice) {

                    // id
                    case '1': {
                        int id = inputInt("Enter id: ", 1);
                        PositionDto* dto = university->positionService()->findById(id);
                        if (dto == nullptr) {
                            cout << "Position with id " << id << " not found" << endl;
                            break;
                        }

                        Vector<Vector<std::string>> table;
                        table.add(new Vector<std::string>(dto->toPrintable()));
                        Vector<std::string> headers = PositionDto::headers();
                        printMarkdownTable(headers, table);

                        delete dto;

                        choice = validChoice('0', '2', recordMenu);
                        switch (choice) {

                        // Edit
                        case '1': {
                            PositionDto* newDto = createPosition(id);
                            university->positionService()->updatePosition(newDto);
                            delete newDto;

                            break;
                        }

                        // Delete
                        case '2': {
                            university->positionService()->deletePosition(id);

                            break;
                        }
                        default:
                            break;
                        }
                        break;
                    }

                    // name
                    case '2': {
                        std::string name = inputString("Enter name: ", isValidName);
                        university->positionDtos(university->positionService()->findByName(name));

                        printDtos(university->positionDtos());

                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }

            // ----------- Professors -----------
            case '4': {
                system("cls");
                choice = validChoiceAction("Professors");
                switch (choice) {

                // Create
                case '1': {
                    try {
                        ProfessorDto* dto = createProfessor(0);
                        university->professorService()->createProfessor(dto);
                        delete dto;
                    }
                    catch (const std::exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                }

                // All
                case '2': {
                    university->professorDtos(university->professorService()->findAll());
                    
                    printDtos(university->professorDtos());

                    break;
                }

                // Search
                case '3': {
                    system("cls");
                    choice = validChoice('0', '5', professorSearch);
                    switch (choice) {

                    // id
                    case '1': {
                        int id = inputInt("Enter id: ", 1);
                        ProfessorDto* dto = university->professorService()->findById(id);
                        if (dto == nullptr) {
                            cout << "Professor with id " << id << " not found" << endl;
                            break;
                        }

                        Vector<Vector<std::string>> table;
                        table.add(new Vector<std::string>(dto->toPrintable()));
                        Vector<std::string> headers = ProfessorDto::headers();
                        printMarkdownTable(headers, table);

                        delete dto;

                        choice = validChoice('0', '2', recordMenu);
                        switch (choice) {

                        // Edit
                        case '1': {
                            ProfessorDto* newDto = createProfessor(id);
                            university->professorService()->updateProfessor(newDto);
                            delete newDto;

                            break;
                        }
                        // Delete
                        case '2': {
                            university->professorService()->deleteProfessor(id);
                            
                            break;
                        }
                        default:
                            break;
                        }
                        break;
                    }

                    // first name
                    case '2': {
                        std::string name = inputString("Enter first name: ", isValidName);
                        university->professorDtos(university->professorService()->findByFirstName(name));

                        printDtos(university->professorDtos());

                        break;
                    }

                    // middle name
                    case '3': {
                        std::string name = inputString("Enter middle name: ", isValidName);
                        university->professorDtos(university->professorService()->findByMiddleName(name));

                        printDtos(university->professorDtos());

                        break;
                    }

                    // last name
                    case '4': {
                        std::string name = inputString("Enter last name: ", isValidName);
                        university->professorDtos(university->professorService()->findByLastName(name));

                        printDtos(university->professorDtos());
                        
                        break;
                    }

                    // department
                    case '5': {
                        int department = inputInt("Enter department: ");
                        university->professorDtos(university->professorService()->findByDepartment(department));

                        printDtos(university->professorDtos());

                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }

            // ----------- Responsibilities -----------
            case '5': {
                system("cls");
                choice = validChoiceAction("Responsibilities");
                switch (choice) {

                // Create
                case '1': {
                    try {
                        ResponsibilityDto* dto = createResponsibility(0);
                        university->responsibilityService()->createResponsibility(dto);
                        delete dto;
                    }
                    catch (const std::exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                }

                // All
                case '2': {
                    university->responsibilityDtos(university->responsibilityService()->findAll());

                    printDtos(university->responsibilityDtos());

                    break;
                }

                // Search
                case '3': {
                    system("cls");
                    choice = validChoice('0', '2', responsibilitySearch);
                    switch (choice) {

                    // id
                    case '1': {
                        int id = inputInt("Enter id: ", 1);
                        ResponsibilityDto* dto = university->responsibilityService()->findById(id);
                        if (dto == nullptr) {
                            cout << "Responsibility with id " << id << " not found" << endl;
                            break;
                        }

                        Vector<Vector<std::string>> table;
                        table.add(new Vector<std::string>(dto->toPrintable()));
                        Vector<std::string> headers = ResponsibilityDto::headers();
                        printMarkdownTable(headers, table);

                        delete dto;

                        choice = validChoice('0', '2', recordMenu);
                        switch (choice) {

                        // Edit
                        case '1': {
                            ResponsibilityDto* newDto = createResponsibility(id);
                            university->responsibilityService()->updateResponsibility(newDto);
                            delete newDto;

                            break;
                        }

                        // Delete
                        case '2': {
                            university->responsibilityService()->deleteResponsibility(id);

                            break;
                        }
                        default:
                            break;
                        }
                        break;
                    }

                    // name
                    case '2': {
                        std::string name = inputString("Enter name: ", isValidName);
                        university->responsibilityDtos(university->responsibilityService()->findByName(name));

                        printDtos(university->responsibilityDtos());

                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }

            // ----------- Scores -----------
            case '6': {
                system("cls");
                choice = validChoiceAction("Scores");
                switch (choice) {

                // Create
                case '1': {
                    try {
                        ScoreDto* dto = createScore(0);
                        university->scoreService()->createScore(dto);
                        delete dto;
                    }
                    catch (const std::exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                }

                // All
                case '2': {
                    university->scoreDtos(university->scoreService()->findAll());

                    printDtos(university->scoreDtos());

                    break;
                }

                // Search
                case '3': {
                    system("cls");
                    scoreSearch();
                    while (true) {
                        choice = _getch();
                        if (choice < '0' || choice > '9' || choice != 'q' || choice != 'w')
                            continue;
                        break;
                    }
                    switch (choice) {

                    // id
                    case '1': {
                        int id = inputInt("Enter id: ", 1);
                        ScoreDto* dto = university->scoreService()->findById(id);
                        if (dto == nullptr) {
                            cout << "Score with id " << id << " not found" << endl;
                            break;
                        }

                        Vector<Vector<std::string>> table;
                        table.add(new Vector<std::string>(dto->toPrintable()));
                        Vector<std::string> headers = ScoreDto::headers();
                        printMarkdownTable(headers, table);

                        delete dto;

                        choice = validChoice('0', '2', recordMenu);
                        switch (choice) {

                        // Edit
                        case '1': {
                            ScoreDto* newDto = createScore(id);
                            university->scoreService()->updateScore(newDto);
                            delete newDto;

                            break;
                        }

                        // Delete
                        case '2': {
                            university->scoreService()->deleteScore(id);

                            break;
                        }
                        default:
                            break;
                        }
                        break;
                    }

                    // student
                    case '2': {
                        int studentId  = inputInt("Enter student id: ");
                        university->scoreDtos(university->scoreService()->findByStudentId(studentId));

                        printDtos(university->scoreDtos());

                        break;
                    }
                    // subject
                    case '3': {
                        int subjectId = inputInt("Enter subject id: ");
                        university->scoreDtos(university->scoreService()->findBySubjectId(subjectId));

                        printDtos(university->scoreDtos());

                        break;
                    }
                    // professor
                    case '4': {
                        int professorId = inputInt("Enter professor id: ");
                        university->scoreDtos(university->scoreService()->findByProfessorId(professorId));

                        printDtos(university->scoreDtos());

                        break;
                    }
                    // score
                    case '5': {
                        int score = inputInt("Enter professor id: ", 2, 5 );
                        university->scoreDtos(university->scoreService()->findByScore(score));

                        printDtos(university->scoreDtos());

                        break;
                    }
                    // student and subject
                    case '6': {
                        int studentId = inputInt("Enter student id: ");
                        int subjectId = inputInt("Enter subject id: ");
                        university->scoreDtos(university->scoreService()->findByStudentIdAndSubjectId(studentId, subjectId));

                        printDtos(university->scoreDtos());

                        break;
                    }
                    // student and professor
                    case '7': {
                        int studentId = inputInt("Enter student id: ");
                        int professorId = inputInt("Enter professor id: ");
                        university->scoreDtos(university->scoreService()->findByStudentIdAndProfessorId(studentId, professorId));

                        printDtos(university->scoreDtos());

                        break;
                    }
                    // student and score
                    case '8': {
                        int studentId = inputInt("Enter student id: ");
                        int score = inputInt("Enter professor id: ", 2, 5);
                        university->scoreDtos(university->scoreService()->findByStudentIdAndScore(studentId, score));

                        printDtos(university->scoreDtos());

                        break;
                    }
                    // subject id and professor
                    case '9': {
                        int subjectId = inputInt("Enter subject id: ");
                        int professorId = inputInt("Enter professor id: ");
                        university->scoreDtos(university->scoreService()->findBySubjectIdAndProfessorId(subjectId, professorId));

                        printDtos(university->scoreDtos());

                        break;
                    }
                    // subject id and score
                    case 'q': {
                        int subjectId = inputInt("Enter subject id: ");
                        int score = inputInt("Enter professor id: ", 2, 5);
                        university->scoreDtos(university->scoreService()->findBySubjectIdAndScore(subjectId, score));

                        printDtos(university->scoreDtos());

                        break;
                    }
                    // studeprofessor and scorent
                    case 'w': {
                        int professorId = inputInt("Enter professor id: ");
                        int score = inputInt("Enter professor id: ", 2, 5);
                        university->scoreDtos(university->scoreService()->findByProfessorIdAndScore(professorId, score));

                        printDtos(university->scoreDtos());

                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }

            // ----------- Specialities -----------
            case '7': {
                system("cls");
                choice = validChoiceAction("Specialities");
                switch (choice) {

                    // Create
                case '1': {
                    try {
                        SpecialityDto* dto = createSpeciality(0);
                        university->specialityService()->createSpeciality(dto);
                        delete dto;
                    }
                    catch (const std::exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                }

                        // All
                case '2': {
                    university->specialityDtos(university->specialityService()->findAll());

                    printDtos(university->specialityDtos());

                    break;
                }

                        // Search
                case '3': {
                    system("cls");
                    choice = validChoice('0', '2', specialitySearch);
                    switch (choice) {

                        // id
                    case '1': {
                        int id = inputInt("Enter id: ", 1);
                        SpecialityDto* dto = university->specialityService()->findById(id);
                        if (dto == nullptr) {
                            cout << "Speciality with id " << id << " not found" << endl;
                            break;
                        }

                        Vector<Vector<std::string>> table;
                        table.add(new Vector<std::string>(dto->toPrintable()));
                        Vector<std::string> headers = SpecialityDto::headers();
                        printMarkdownTable(headers, table);

                        delete dto;

                        choice = validChoice('0', '2', recordMenu);
                        switch (choice) {

                            // Edit
                        case '1': {
                            SpecialityDto* newDto = createSpeciality(id);
                            university->specialityService()->updateSpeciality(newDto);
                            delete newDto;

                            break;
                        }

                                // Delete
                        case '2': {
                            university->specialityService()->deleteSpeciality(id);

                            break;
                        }
                        default:
                            break;
                        }
                        break;
                    }

                            // name
                    case '2': {
                        std::string name = inputString("Enter name: ", isValidName);
                        university->specialityDtos(university->specialityService()->findByName(name));

                        printDtos(university->specialityDtos());

                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }

            // ----------- Students -----------
            case '8': {
                system("cls");
                choice = validChoiceAction("Students");
                switch (choice) {

                    // Create
                case '1': {
                    try {
                        StudentDto* dto = createStudent(0);
                        university->studentService()->createStudent(dto);
                        delete dto;
                    }
                    catch (const std::exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                }

                        // All
                case '2': {
                    university->studentDtos(university->studentService()->findAll());

                    printDtos(university->studentDtos());

                    break;
                }

                        // Search
                case '3': {
                    system("cls");
                    choice = validChoice('0', '5', studentSearch);
                    switch (choice) {

                        // id
                    case '1': {
                        int id = inputInt("Enter id: ", 1);
                        StudentDto* dto = university->studentService()->findById(id);
                        if (dto == nullptr) {
                            cout << "Student with id " << id << " not found" << endl;
                            break;
                        }

                        Vector<Vector<std::string>> table;
                        table.add(new Vector<std::string>(dto->toPrintable()));
                        Vector<std::string> headers = StudentDto::headers();
                        printMarkdownTable(headers, table);

                        delete dto;

                        choice = validChoice('0', '2', recordMenu);
                        switch (choice) {

                            // Edit
                        case '1': {
                            StudentDto* newDto = createStudent(id);
                            university->studentService()->updateStudent(newDto);
                            delete newDto;

                            break;
                        }
                                // Delete
                        case '2': {
                            university->studentService()->deleteStudent(id);

                            break;
                        }
                        default:
                            break;
                        }
                        break;
                    }

                            // first name
                    case '2': {
                        std::string name = inputString("Enter first name: ", isValidName);
                        university->studentDtos(university->studentService()->findByFirstName(name));

                        printDtos(university->studentDtos());

                        break;
                    }

                            // middle name
                    case '3': {
                        std::string name = inputString("Enter middle name: ", isValidName);
                        university->studentDtos(university->studentService()->findByMiddleName(name));

                        printDtos(university->studentDtos());

                        break;
                    }

                            // last name
                    case '4': {
                        std::string name = inputString("Enter last name: ", isValidName);
                        university->studentDtos(university->studentService()->findByLastName(name));

                        printDtos(university->studentDtos());

                        break;
                    }

                            // group
                    case '5': {
                        int group = inputInt("Enter group id: ");
                        university->studentDtos(university->studentService()->findByGroupId(group));

                        printDtos(university->studentDtos());

                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }

            // ----------- Subjects -----------
            case '9': {
                system("cls");
                choice = validChoiceAction("Subjects");
                switch (choice) {

                    // Create
                case '1': {
                    try {
                        SubjectDto* dto = createSubject(0);
                        university->subjectService()->createSubject(dto);
                        delete dto;
                    }
                    catch (const std::exception& e) {
                        cerr << "Error: " << e.what() << endl;
                    }
                    break;
                }

                        // All
                case '2': {
                    university->subjectDtos(university->subjectService()->findAll());

                    printDtos(university->subjectDtos());

                    break;
                }

                        // Search
                case '3': {
                    system("cls");
                    choice = validChoice('0', '2', subjectSearch);
                    switch (choice) {

                        // id
                    case '1': {
                        int id = inputInt("Enter id: ", 1);
                        SubjectDto* dto = university->subjectService()->findById(id);
                        if (dto == nullptr) {
                            cout << "Subject with id " << id << " not found" << endl;
                            break;
                        }

                        Vector<Vector<std::string>> table;
                        table.add(new Vector<std::string>(dto->toPrintable()));
                        Vector<std::string> headers = SubjectDto::headers();
                        printMarkdownTable(headers, table);

                        delete dto;

                        choice = validChoice('0', '2', recordMenu);
                        switch (choice) {

                            // Edit
                        case '1': {
                            SubjectDto* newDto = createSubject(id);
                            university->subjectService()->updateSubject(newDto);
                            delete newDto;

                            break;
                        }

                                // Delete
                        case '2': {
                            university->subjectService()->deleteSubject(id);

                            break;
                        }
                        default:
                            break;
                        }
                        break;
                    }

                            // name
                    case '2': {
                        std::string name = inputString("Enter name: ", isValidName);
                        university->subjectDtos(university->subjectService()->findByName(name));

                        printDtos(university->subjectDtos());

                        break;
                    }
                    default:
                        break;
                    }
                    break;
                }
                default:
                    break;
                }
                break;
            }

            case '0': {
                exit = true;
                break;
            }
            }
        }

        delete university;
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}
