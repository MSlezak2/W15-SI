#pragma once
#include <string>
#include <unordered_map>

class DBManager {
public:
	DBManager() = default;
	~DBManager() = default;

	struct DBEntry {
		DBEntry() = default;
		DBEntry(std::string n, short int g) : studentName{ n }, grade{ g } {};
		std::string studentName;
		short int grade;

		friend std::ostream& operator<<(std::ostream& os, const DBEntry& entry);
		friend std::istream& operator>>(std::istream& is, DBEntry& entry);
	};

	bool addEntry(std::string studentName, short int grade);
	bool removeEntry(std::string studentName);
	bool modifyEntry(std::string studentName, short int newGrade);
	std::vector<DBEntry> getEntries();

private:
	std::unordered_map<std::string, int> gradeBook;
	bool isGradeValid(short int grade);
	bool isNameAlreadyInDB(std::string name);
	bool isNameFormatCorrect(std::string name);
};

