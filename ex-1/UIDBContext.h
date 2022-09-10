#pragma once
#include <functional>
#include "DBManager.h"

class UIDBContext {
public:
	UIDBContext();
	void setSortingFunction(std::function<bool(const DBManager::DBEntry, const DBManager::DBEntry)> newSortingFunction);
	std::function<bool(const DBManager::DBEntry, const DBManager::DBEntry)> getSortingFunction();
	void setFilteringFunction(std::function<bool(const DBManager::DBEntry)> newFilteringFunction);
	std::function<bool(const DBManager::DBEntry)> getFilteringFunction();

private:
	std::function<bool(const DBManager::DBEntry, const DBManager::DBEntry)> sortingFunction;
	std::function<bool(const DBManager::DBEntry)> filteringFunction;
};

