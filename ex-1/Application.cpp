#include "Application.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>

int Application::run() {
    
    menuOptions state{ menuOptions::MENU};

    while (state != menuOptions::EXIT) {
        switch (state) {
        case menuOptions::MENU:
            state = displayMainMenu();
            break;
        case menuOptions::MODIFY_MENU:
            state = displayModifyMenu();
            break;
        case menuOptions::LOAD_OR_STORE_MENU:
            state = displayLoadOrStoreMenu();
            break;
        case menuOptions::FILTER_MENU:
            state = displayFilterMenu();
            break;
        case menuOptions::SORT_MENU:
            state = displaySortMenu();
            break;
        case menuOptions::VISUALIZE:
            state = displayDB();
            break;
        case menuOptions::EXIT:
            break;
        }
    }
    
    return 0;
}

Application::menuOptions Application::displayMainMenu() {
    menuOptions nextState{ menuOptions::MENU };
    int usersChoice{ 0 };

    // display the options
    system("cls");
    std::cout << "MAIN MENU" << std::endl << std::endl;
    std::cout << "1. Modify database" << std::endl;
    std::cout << "2. Load / store database" << std::endl;
    std::cout << "3. Filter database" << std::endl;
    std::cout << "4. Set sorting order" << std::endl;
    std::cout << "5. Visualize the database" << std::endl;
    std::cout << "6. Exit" << std::endl << std::endl;

    // take user input
    usersChoice = takeNumber(1, 6);

    // handle the request
    switch (usersChoice) {
    case 1:
        nextState = menuOptions::MODIFY_MENU;
        break;
    case 2:
        nextState = menuOptions::LOAD_OR_STORE_MENU;
        break;
    case 3:
        nextState = menuOptions::FILTER_MENU;
        break;
    case 4:
        nextState = menuOptions::SORT_MENU;
        break;
    case 5:
        nextState = menuOptions::VISUALIZE;
        break;
    case 6:
        nextState = menuOptions::EXIT;
        break;
    }

    return nextState;
}

Application::menuOptions Application::displayModifyMenu() {
    menuOptions nextState{ menuOptions::MODIFY_MENU };
    int usersChoice{ 0 };

    // display the options
    system("cls");
    std::cout << "MODIFY DATABASE" << std::endl << std::endl;
    std::cout << "1. Add entry" << std::endl;
    std::cout << "2. Remove entry" << std::endl;
    std::cout << "3. Modify entry" << std::endl;
    std::cout << "4. Back" << std::endl <<std::endl;

    // take user input
    usersChoice = takeNumber(1, 4);

    // handle the request
    switch (usersChoice) {
    case 1:
        displayAddEntryMenu();
        break;
    case 2:
        displayRemoveEntryMenu();
        break;
    case 3:
        displayModifyEntryMenu();
        break;
    case 4:
        nextState = menuOptions::MENU;
        break;
    }

    return nextState;
}

Application::menuOptions Application::displayLoadOrStoreMenu() {
    menuOptions nextState{ menuOptions::MENU };
    int usersChoice{ 0 };

    // display the options
    system("cls");
    std::cout << "LOAD / STORE DATABASE" << std::endl << std::endl;
    std::cout << "1. Load db from the file" << std::endl;
    std::cout << "2. Store db in the file" << std::endl;
    std::cout << "3. Back" << std::endl << std::endl;

    // take user input
    usersChoice = takeNumber(1, 3);

    // handle the request
    switch (usersChoice) {
    case 1:
        loadDBFromFile();
        break;
    case 2:
        storeDBToFile();
        break;
    case 3:
        nextState = menuOptions::MENU;
        break;
    }

    return nextState;
}

Application::menuOptions Application::displayFilterMenu() {
    menuOptions nextState{ menuOptions::MENU };
    int usersChoice{ 0 };

    // display the options
    system("cls");
    std::cout << "FILTER DATABASE" << std::endl << std::endl;
    std::cout << "1. Only passing grades" << std::endl;
    std::cout << "2. Only non-passing grades" << std::endl;
    std::cout << "3. All grades" << std::endl;
    std::cout << "4. Back" << std::endl << std::endl;

    // take user input
    usersChoice = takeNumber(1, 4);

    // handle the request
    switch (usersChoice) {
    case 1: // only passing grades
        filterNonPassingGrades();
        break;
    case 2: // only non-passing grades
        filterPassingGrades();      
        break;
    case 3: // all the grades       
        filterNoneGrades();        
        break;
    case 4:
        nextState = menuOptions::MENU; // unneccessary, but for the clarity of the code
        break;
    }

    return nextState;
}

Application::menuOptions Application::displaySortMenu() {
    menuOptions nextState{ menuOptions::MENU };
    int usersChoice{ 0 };

    // display the options
    system("cls");
    std::cout << "GRADE BOOK" << std::endl << std::endl;
    std::cout << "SORT DATABASE" << std::endl << std::endl;
    std::cout << "1. Increasing by name" << std::endl;
    std::cout << "2. Decreasing by name" << std::endl;
    std::cout << "3. Increasing by grade" << std::endl;
    std::cout << "4. Decreasing by grade" << std::endl;
    std::cout << "5. Back" << std::endl << std::endl;

    // take user input
    usersChoice = takeNumber(1, 5);

    // handle the request
    switch (usersChoice) {
    case 1: // increasing by name
        sortIncreasingByName();
        break;
    case 2: // decreasing by name
        sortDecreasingByName();
        break;
    case 3: // increasing by grade   
        sortIncreasingByGrade();
        break;
    case 4: // decreasing by name
        sortDecreasingByGrade();
        break;
    case 5:
        nextState = menuOptions::MENU; // unneccessary, but for the clarity of the code
        break;
    }

    return nextState;
}

Application::menuOptions Application::displayDB() {
   
    // prepare the vector of entries
    std::vector<DBManager::DBEntry> entries = dbmanager.getEntries(); 
    filterEntries(entries);
    sortEntries(entries);

    // display them
    system("cls");
    std::cout
        << std::left << std::setw(20) << std::setfill(' ') << "NAME"
        << std::left << std::setw(20) << std::setfill(' ') << "GRADE" << std::endl;

    for (DBManager::DBEntry entry : entries) { 
        std::cout
            << std::left << std::setw(20) << std::setfill(' ') << entry.studentName
            << std::left << std::setw(20) << std::setfill(' ') << entry.grade << std::endl;
    }

    std::cout << std::endl;
    system("pause");

    return menuOptions::MENU;
}

void Application::displayAddEntryMenu() {
    std::string name;
    short int grade;
    bool operationCompleted{false};
 
    system("cls");
    std::cout << "ADD NEW ENTRY" <<std::endl << std::endl;
    std::cout << "Enter the name of the student:" << std::endl;
    std::cin >> name;
    std::cout << "Enter the grade:" << std::endl;
    grade = takeNumber(1,6);

    operationCompleted = dbmanager.addEntry(name, grade);

    if (operationCompleted) {
        std::cout << "Operation completed" << std::endl;
    }
    system("pause");
}

void Application::displayRemoveEntryMenu() {
    std::string name;
    bool operationCompleted{ false };

    system("cls");
    std::cout << "REMOVE ENTRY" << std::endl << std::endl;
    std::cout << "Enter the name of the student:" << std::endl;
    std::cin >> name;

    operationCompleted = dbmanager.removeEntry(name);

    if (operationCompleted) {
        std::cout << "Operation completed" << std::endl;
    }
    system("pause");
}

void Application::displayModifyEntryMenu() {
    std::string name;
    short int grade;
    bool operationCompleted{ false };

    system("cls");
    std::cout << "MODIFY ENTRY" << std::endl << std::endl;
    std::cout << "Enter the name of the student:" << std::endl;
    std::cin >> name;
    std::cout << "Enter the new grade:" << std::endl;
    grade = takeNumber(1, 6);

    operationCompleted = dbmanager.modifyEntry(name, grade);

    if (operationCompleted) {
        std::cout << "Operation completed" << std::endl;
    }
    system("pause");
}

void Application::loadDBFromFile() {
    std::ifstream ifs("db.txt", std::ios_base::in);
    int noEntries{ 0 };
    std::string tempName{ "" };
    short int tempGrade{ 0 };

    if (ifs.is_open()) {
        ifs >> noEntries;
        for (int i = 0; i < noEntries; i++) {
            ifs >> tempName;
            ifs >> tempGrade;
            dbmanager.addEntry(tempName, tempGrade);
        }
    }
}

void Application::storeDBToFile() {
    std::ofstream ofs("db.txt", std::ios_base::out);

    std::vector<DBManager::DBEntry> entries = dbmanager.getEntries();

    ofs << entries.size() << std::endl;

    if (true) {

    }
    std::for_each(entries.begin(), entries.end(), [&ofs](DBManager::DBEntry entry) {
        ofs
            << entry.studentName << std::endl
            << entry.grade << std::endl;
        });

    ofs.close();
}

void Application::filterNonPassingGrades() {
    uidbcontext.setFilteringFunction([](DBManager::DBEntry entry) {
        return entry.grade < 3;
        });
}

void Application::filterPassingGrades() {
    uidbcontext.setFilteringFunction([](DBManager::DBEntry entry) {
        return entry.grade >= 3;
        });
}

void Application::filterNoneGrades() {
    uidbcontext.setFilteringFunction([](DBManager::DBEntry entry) {
        return false;
        });
}

void Application::sortIncreasingByName() {
    uidbcontext.setSortingFunction([](const DBManager::DBEntry& leftOne, const DBManager::DBEntry& rightOne) {
        bool isLeftOneLess{ false };
        if (leftOne.studentName.compare(rightOne.studentName) < 0) {
            isLeftOneLess = true;
        }
        return isLeftOneLess;
        });
}

void Application::sortDecreasingByName() {
    uidbcontext.setSortingFunction([](const DBManager::DBEntry& leftOne, const DBManager::DBEntry& rightOne) {
        bool isLeftOneLess{ false };
        if (leftOne.studentName.compare(rightOne.studentName) > 0) {
            isLeftOneLess = true;
        }
        return isLeftOneLess;
        });
}

void Application::sortIncreasingByGrade() {
    uidbcontext.setSortingFunction([](const DBManager::DBEntry& leftOne, const DBManager::DBEntry& rightOne) {
        bool isLeftOneLess{ false };
        if (leftOne.grade < rightOne.grade) {
            isLeftOneLess = true;
        }
        return isLeftOneLess;
        });
}

void Application::sortDecreasingByGrade() {
    uidbcontext.setSortingFunction([](const DBManager::DBEntry& leftOne, const DBManager::DBEntry& rightOne) {
        bool isLeftOneLess{ false };
        if (leftOne.grade > rightOne.grade) {
            isLeftOneLess = true;
        }
        return isLeftOneLess;
        });
}

void Application::filterEntries(std::vector<DBManager::DBEntry>& entries) {
    std::vector<DBManager::DBEntry>::iterator lastElement = std::remove_if(entries.begin(), entries.end(), uidbcontext.getFilteringFunction());
    entries.erase(lastElement, entries.end());
}

void Application::sortEntries(std::vector<DBManager::DBEntry>& entries) {
    std::sort(entries.begin(), entries.end(), uidbcontext.getSortingFunction());
}

int Application::takeNumber(int rangeStart, int rangeEnd) {
    /// <summary>
    /// Prompts user to input a number from rangeStart to rangeEnd (both inclusive). If given number
    /// is out of defined range or is not a number, it keeps asking.
    /// </summary>
    /// <param name="rangeStart"></param>
    /// <param name="rangeEnd"></param>
    /// <returns>Validated integer number provided by user</returns>
    /// 
    int number = HUGE_VAL;
    std::string userInput;

    do {
        std::cin >> userInput;
        try {
            number = std::stoi(userInput);
            if (number < rangeStart || number > rangeEnd) {
                std::cout << "Look, you've reached out of the allowed range" << std::endl;
            }
        } catch (const std::invalid_argument&) {
            std::cout << "It's not even a number!" << std::endl;
        } catch (const std::out_of_range&) {
            std::cout << "That number is way out of range!" << std::endl;
        }
    } while (number < rangeStart || number > rangeEnd);

    return number;
    //TODO: What if rangeStart > rangeEnd
}
