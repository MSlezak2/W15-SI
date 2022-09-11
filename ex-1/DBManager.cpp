#include "DBManager.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

// If name or grade are invalid or there is already student with such name in db
// it does nothing but displays a warning
bool DBManager::addEntry(std::string studentName, short int grade) {
	bool operationCompleted{ false };
	
	if (!isGradeValid(grade)) {
		std::cout << "Add operation failed: Provided grade is out of range... Please enter the correct one." << std::endl;
	} else if (isNameAlreadyInDB(studentName)) {
		std::cout << "Add operation failed: There already is a student with that name in the db..." << std::endl;
	} else if (!isNameFormatCorrect(studentName)) {
		std::cout << "Add operation failed: Provided name is in incorrect format..." << std::endl;
	} else {
		gradeBook.insert({ studentName, grade });
		operationCompleted = true;
	} 

	return operationCompleted;
}

// Does nothing but warns you if there's no entry with given name
bool DBManager::removeEntry(std::string studentName) {
	bool operationCompleted{ false };
	if (!isNameAlreadyInDB(studentName)) {
		std::cout << "Remove operation failed: There's no such student in a database..." << std::endl;
	} else {
		gradeBook.erase(studentName);
		operationCompleted = true;
	}
	return operationCompleted;
}

// Does nothing but warns you if there's no entry with given name
bool DBManager::modifyEntry(std::string studentName, short int newGrade) {
	bool operationCompleted{ false };
	if (!isNameAlreadyInDB(studentName)) {
		std::cout << "Modify operation failed: There's no such student in a database..." << std::endl;
	} else if (!isGradeValid(newGrade)) {
		std::cout << "Modify operation failed: Provided grade is out of range..." << std::endl;
	} else {
		gradeBook.at(studentName) = newGrade;
		operationCompleted = true;
	}
	return operationCompleted;
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

std::ostream& operator<<(std::ostream& os, const DBManager::DBEntry& entry) {
	os << entry.studentName << std::endl;
	os << entry.grade << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, DBManager::DBEntry& entry) {
	// TODO: How to set failbit correctly? How to determine whether values in is are proper?
	is >> entry.studentName;
	is >> entry.grade;
	if (entry.studentName == "" || entry.grade == 0) {
		is.setstate(std::ios::failbit);
	}

	// TODO: Maybe I should handle exceptions thrown by methods like std::string >> operator etc.

	return is;
}

