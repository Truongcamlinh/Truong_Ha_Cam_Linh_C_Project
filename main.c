#include <stdio.h>
#include "function.h"

int main() {
    category categories[100];
    int categoryCount = 0;
    loadCategoriesFromFile(categories, &categoryCount);
    int choice;
    do {
        displayMainMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                categaryManagement(categories, &categoryCount);
                saveCategoriesToFile(categories, categoryCount);
                break;
            case 0:
                printf("\nThoat chuong trinh. Cam on ban da su dung chuong trinh!\n");
                break;

            default:
                printf("\nLua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
