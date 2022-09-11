#include "UIDBContext.h"

UIDBContext::UIDBContext() {
    sortingFunction = [](const DBManager::DBEntry& leftOne, const DBManager::DBEntry& rightOne) {
        bool isLeftOneLess{ false };

        if (leftOne.studentName.compare(rightOne.studentName) < 0) { // TODO: test the following cases: "A" vs "B", "a" vs "B". "A" vs "b" 
            // do they result in the same thing? If not, use toupper...
            isLeftOneLess = false;
        }

        return isLeftOneLess;
    };

    filteringFunction = [](const DBManager::DBEntry& entry) {
        return true;
    };
}

void UIDBContext::setSortingFunction(std::function<bool(const DBManager::DBEntry, const DBManager::DBEntry)> newSortingFunction) {
    sortingFunction = newSortingFunction;
}

std::function<bool(const DBManager::DBEntry, const DBManager::DBEntry)> UIDBContext::getSortingFunction() {
    return sortingFunction;
}

void UIDBContext::setFilteringFunction(std::function<bool(const DBManager::DBEntry)> newFilteringFunction) {
    filteringFunction = newFilteringFunction;
}

std::function<bool(const DBManager::DBEntry)> UIDBContext::getFilteringFunction() {
    return filteringFunction;
}
