#include "DBManager.h"
#include <iostream>
#include <algorithm>
#include "UIDBContext.h"
#include "Application.h"

int main() {
	//------------------TESTS:-------------------------
	//DBManager dbmanager;
	//UIDBContext uidbcontext;

	//// add new entries:
	//dbmanager.addEntry("H", 4);
	//dbmanager.addEntry("A", 4);
	//dbmanager.addEntry("D", 6);
	//dbmanager.addEntry("C", 3);
	//dbmanager.addEntry("E", 1);
	//dbmanager.addEntry("F", 1);
	//dbmanager.addEntry("B", 2);
	//dbmanager.addEntry("G", 4);
	//dbmanager.addEntry("I", 7);
	//dbmanager.addEntry("", 1);

	//// erase a few:
	//dbmanager.removeEntry("D");
	//dbmanager.removeEntry("");
	//dbmanager.removeEntry("Michal");

	//// modify:
	//dbmanager.modifyEntry("A",1);
	//dbmanager.modifyEntry("", 1);
	//dbmanager.modifyEntry("Michal", 1);
	//dbmanager.modifyEntry("A", 0);

	//// get all entries:
	//std::vector<DBManager::DBEntry> entries = dbmanager.getEntries();

	//// send entry to cout stream:
	//std::cout << entries[1];

	//// read entry from cout stream:
	//std::cin >> entries[0];
	//-----------------------------------------------------

	//// sort using default lambda from UIDBContext class
	//std::sort(entries.begin(), entries.end(), uidbcontext.getSortingFunction());

	//// filter using default lambda from UIDBContext class
	//std::cout << entries.size() << std::endl;
	//std::vector<DBManager::DBEntry>::iterator lastElement = std::remove_if(entries.begin(), entries.end(), uidbcontext.getFilteringFunction());
	//entries.erase(lastElement, entries.end());
	//std::cout << entries.size() <<std::endl;
	Application application;

	return application.run();
}