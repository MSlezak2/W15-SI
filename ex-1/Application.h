#pragma once
#include "DBManager.h"
#include "UIDBContext.h"

class Application {
public:
	int run();

private:
	DBManager dbmanager;
	UIDBContext uidbcontext;
	enum class menuOptions{
		MENU,
		MODIFY_MENU,
		//ADD_ENTRY,
		//REMOVE_ENTRY,
		//MODIFY_ENTRY,
		LOAD_OR_STORE_MENU,
		FILTER_MENU,
		SORT_MENU,
		VISUALIZE,
		BACK,
		EXIT
	};
	
	menuOptions displayMainMenu();
	menuOptions displayModifyMenu();
	menuOptions displayLoadOrStoreMenu();
	menuOptions displayFilterMenu();
	menuOptions displaySortMenu();
	menuOptions displayDB();
	void displayAddEntryMenu();
	void displayRemoveEntryMenu();
	void displayModifyEntryMenu();
	void loadDBFromFile();
	void storeDBToFile();
	void filterNonPassingGrades();
	void filterPassingGrades();
	void filterNoneGrades();
	void sortIncreasingByName();
	void sortDecreasingByName();
	void sortIncreasingByGrade();
	void sortDecreasingByGrade();
	void filterEntries(std::vector<DBManager::DBEntry>& entries);
	void sortEntries(std::vector<DBManager::DBEntry>& entries);

	int takeNumber(int rangeStart, int rangeEnd);
};