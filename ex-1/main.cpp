#include "DBManager.h"

int main() {
	DBManager dbmanager;

	// add new entries:
	dbmanager.addEntry("A", 4);
	dbmanager.addEntry("B", 2);
	dbmanager.addEntry("C", 3);
	dbmanager.addEntry("D", 6);
	dbmanager.addEntry("E", 1);
	dbmanager.addEntry("F", 1);
	dbmanager.addEntry("G", 4);
	dbmanager.addEntry("H", 4);
	dbmanager.addEntry("I", 7);
	dbmanager.addEntry("", 1);

	// erase a few:
	dbmanager.removeEntry("D");
	dbmanager.removeEntry("");
	dbmanager.removeEntry("Michal");

	// modify:
	dbmanager.modifyEntry("A",1);
	dbmanager.modifyEntry("", 1);
	dbmanager.modifyEntry("Michal", 1);
	dbmanager.modifyEntry("A", 0);

	// get all entries:
	std::vector<DBManager::DBEntry> entries = dbmanager.getEntries();

	return 0;
}