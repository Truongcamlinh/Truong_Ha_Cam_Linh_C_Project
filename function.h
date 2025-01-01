#include "dataType.h"

void displayMainMenu();
void categaryManagement(category categories[], int *categoryCount);
void displayCategoryList(category categories[], int categoryCount);
void addCategory(category categories[], int *categoryCount);
void editCategory(category categories[], int categoryCount);
void deleteCategory(category categories[], int *categoryCount);
void sortCategoriesByName(category categories[], int categoryCount);
int containsIndependentWord(const char *haystack, const char *needle);
void searchCategoryByName(category categories[], int categoryCount);
void displayProductMenu();

