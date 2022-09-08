#include "DBManager.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

void DBManager::addEntry(std::string studentName, short int grade) {
	gradeBook.insert_or_assign(studentName, grade);
}

void DBManager::removeEntry(std::string studentName) {
	gradeBook.erase(studentName);
}

// Does nothing if there's no entry with given name
void DBManager::modifyEntry(std::string studentName, short int newGrade) {
	try {
		gradeBook.at(studentName) = newGrade;
	} catch (const std::out_of_range&) {
		std::cout << "There's no such student in a database..." <<std::endl;
	}
}

std::vector<DBManager::DBEntry> DBManager::getEntries() {
	std::vector<DBEntry> entries;

	for (auto student : gradeBook) {
		DBEntry newEntry(student.first, student.second);
		entries.push_back(newEntry);
	}

	return entries;
}
