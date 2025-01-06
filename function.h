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
void saveCategoriesToFile(category categories[], int categoryCount);
void loadCategoriesFromFile(category categories[], int *categoryCount);


void addProduct(product *products, int *productCount);
void displayProductList(product products[], int categoryCount);
void addProduct(product *products, int *productCount);
void saveProductsToFile(product *products, int productCount);
void loadProductsFromFile(product *products, int *productCount);
