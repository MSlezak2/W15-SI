#include "DBManager.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

// If name or grade are invalid or there is already student with such name in db
// it does nothing but displays a warning
void DBManager::addEntry(std::string studentName, short int grade) {
	if (!isGradeValid(grade)) {
		std::cout << "Add operation failed: Provided grade is out of range... Please enter the correct one." << std::endl;
	} else if (isNameAlreadyInDB(studentName)) {
		std::cout << "Add operation failed: There already is a student with that name in the db..." << std::endl;
	} else if (!isNameFormatCorrect(studentName)) {
		std::cout << "Add operation failed: Provided name is in incorrect format..." << std::endl;
	} else {
		gradeBook.insert({ studentName, grade });
	} 
}

// Does nothing but warns you if there's no entry with given name
void DBManager::removeEntry(std::string studentName) {
	if (!isNameAlreadyInDB(studentName)) {
		std::cout << "Remove operation failed: There's no such student in a database..." << std::endl;
	} else {
		gradeBook.erase(studentName);
	}
}

// Does nothing but warns you if there's no entry with given name
void DBManager::modifyEntry(std::string studentName, short int newGrade) {
	if (!isNameAlreadyInDB(studentName)) {
		std::cout << "Modify operation failed: There's no such student in a database..." << std::endl;
	} else if (!isGradeValid(newGrade)) {
		std::cout << "Modify operation failed: Provided grade is out of range..." << std::endl;
	} else {
		gradeBook.at(studentName) = newGrade;
	}
}

std::vector<DBManager::DBEntry> DBManager::getEntries() {
	std::vector<DBEntry> entries(gradeBook.size());
	//std::vector<DBEntry> entries; // TODO: Why doesn't it work?

	std::transform(gradeBook.begin(), gradeBook.end(),
		entries.begin(), [](std::pair<std::string, short int> student) {
			return DBEntry(student.first, student.second);
		});

	return entries;
}

bool DBManager::isGradeValid(short int grade) {
	return (1 <= grade && grade <= 6);
}

bool DBManager::isNameAlreadyInDB(std::string name) {
	bool alreadyIs{ false };

	if (gradeBook.find(name) != gradeBook.end()) {
		alreadyIs = true;
	}

	return alreadyIs;
}

bool DBManager::isNameFormatCorrect(std::string name) {
	return name.compare("") != 0;
}
