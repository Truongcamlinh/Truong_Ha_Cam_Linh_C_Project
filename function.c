#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "function.h"

void displayMainMenu() {
        printf("\n\t*** Store Management ***\n");
    	printf("=========================================\n");
        printf("[1]. Quan ly danh muc\n");
        printf("[2]. Quan ly san pham\n");
        printf("[0]. Thoat\n");
        printf("=========================================\n");
        printf("Chon mot tuy chon: ");
}
void categaryManagement(category categories[], int *categoryCount) {
	int choice;
	do{
        system("cls");
    	printf("\n\t*** Quan ly danh muc ***\n");
        printf("=========================================================================================================\n");
        printf("| %-3s | %-75s |\n", "ID", "Hanh dong");
        printf("=========================================================================================================\n");
        printf("| %-3d | %-75s |\n", 1, "Hien thi danh sach danh muc");
        printf("| %-3d | %-75s |\n", 2, "Them danh muc moi");
        printf("| %-3d | %-75s |\n", 3, "Sua danh muc (Khong sua duoc ID)");
        printf("| %-3d | %-75s |\n", 4, "Xoa danh muc (Neu co san pham trong danh muc, xoa ca san pham)");
        printf("| %-3d | %-75s |\n", 5, "Tim kiem danh muc theo ten (Chi can chua chuoi nhap vao)");
        printf("| %-3d | %-75s |\n", 6, "Sap xep danh sach danh muc theo ten");
        printf("| %-3d | %-75s |\n", 7, "Luu tru du lieu");
        printf("| %-3d | %-75s |\n", 0, "Thoat");
        printf("=========================================================================================================\n");
        printf("Chon mot tuy chon: ");
        scanf("%d", &choice);

        system("cls");
    	switch (choice)
    	{
    		case 1:
    			displayCategoryList(categories, *categoryCount);
    			break;
    		case 2:
    			addCategory(categories, categoryCount);
    			break;
    		case 3:
                editCategory(categories, *categoryCount);
                break;
            case 4:
                deleteCategory(categories, categoryCount);
                break;
            case 5:
                searchCategoryByName(categories, *categoryCount);
                break;
            case 6:
                sortCategoriesByName(categories, *categoryCount);
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
                break;
		}
	}while(choice!=0);
}
void displayCategoryList(category categories[], int categoryCount) {
     if (categoryCount == 0) {
        getchar();
        printf("\n\t*** Hien thi danh muc ***\n");
        printf("==========================================\n");
        printf("\t\tDanh sach rong\n");
        printf("\n--- Nhan phim bat ky de quay lai ---\n");
        getchar();
        printf("==========================================\n");
        return;
    }
    printf("\n\t*** Hien thi danh muc ***\n");
    printf("=========================================================================================================\n");
    printf("| %-5s | %-10s | %-25s |\n", "STT", "CategoryId", "CategoryName");
    printf("=========================================================================================================\n");
	int i;
    for (i = 0; i < categoryCount; i++) {
        printf("| %-5d | %-10s | %-25s |\n", i + 1, categories[i].CategoryId, categories[i].CategoryName);
    }

    printf("=========================================================================================================\n");
    getchar();
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}
void addCategory(category categories[], int *categoryCount) {
    printf("\n\t*** Add Category ***\n");
    printf("=========================\n");
    int numCategoriesToAdd;
    printf("Nhap so luong danh muc can them: ");
    scanf("%d", &numCategoriesToAdd);
    getchar();
    int i;
    for (i = 0; i < numCategoriesToAdd; i++) {
        category newCategory;
        int isValid = 0;

        printf("\nThem danh muc so %d\n", *categoryCount + 1);
        while (!isValid) {
            isValid = 1;
            printf("Nhap CategoryId (toi da 9 ky tu): ");
            scanf("%s", newCategory.CategoryId);
            getchar();
            if (strlen(newCategory.CategoryId) == 0 || strlen(newCategory.CategoryId) > 9) {
                printf("Loi: CategoryId khong hop le. Vui long nhap lai.\n");
                isValid = 0;
                continue;
            }
            for (int j = 0; j < *categoryCount; j++) {
                if (strcmp(categories[j].CategoryId, newCategory.CategoryId) == 0) {
                    printf("Loi: CategoryId '%s' da ton tai. Vui long nhap ID khac.\n", newCategory.CategoryId);
                    isValid = 0;
                    break;
                }
            }
        }
        isValid = 0;
        while (!isValid) {
            isValid = 1;
            printf("Nhap CategoryName (toi da 9 ky tu): ");
            scanf("%s", newCategory.CategoryName);
            getchar();

            if (strlen(newCategory.CategoryName) == 0 || strlen(newCategory.CategoryName) > 9) {
                printf("Loi: CategoryName khong hop le. Vui long nhap lai.\n");
                isValid = 0;
                continue;
            }
            for (int j = 0; j < *categoryCount; j++) {
                if (strcmp(categories[j].CategoryName, newCategory.CategoryName) == 0) {
                    printf("Loi: CategoryName '%s' da ton tai. Vui long nhap ID khac.\n", newCategory.CategoryName);
                    isValid = 0;
                    break;
                }
            }
        }
        categories[*categoryCount] = newCategory;
        (*categoryCount)++;
        printf("Them danh muc thanh cong!\n");
        saveCategoriesToFile(categories, *categoryCount);
    }
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}
void editCategory(category categories[], int categoryCount) {
    if (categoryCount == 0) {
        getchar();
        printf("\nDanh sach danh muc trong. Khong co gi de sua!\n");
        printf("\n--- Nhan phim bat ky de quay lai ---\n");
        getchar();
        return;
    }
    printf("\n\t*** Hien thi danh muc ***\n");
    printf("=========================================================================================================\n");
    printf("| %-5s | %-10s | %-25s |\n", "STT", "CategoryId", "CategoryName");
    printf("=========================================================================================================\n");

    for (int i = 0; i < categoryCount; i++) {
        printf("| %-5d | %-10s | %-25s |\n", i + 1, categories[i].CategoryId, categories[i].CategoryName);
    }
    printf("=========================================================================================================\n");
    char targetId[10];
    int found = 0;
    printf("\n\t*** Sua danh muc ***\n");
    printf("=========================\n");
    printf("Nhap ID danh muc muon sua: ");
    scanf("%s", targetId);
    getchar();
    int categoryIndex = -1;
    for (int i = 0; i < categoryCount; i++) {
        if (strcmp(categories[i].CategoryId, targetId) == 0) {
            categoryIndex = i;
            break;
        }
    }
    if (categoryIndex == -1) {
        printf("\nLoi: ID danh muc '%s' khong ton tai.\n", targetId);
        return;
    }
    category *editedCategory = &categories[categoryIndex];
    printf("\nThong tin hien tai cua danh muc:\n");
    printf("ID: %s\n", editedCategory->CategoryId);
    printf("Ten: %s\n", editedCategory->CategoryName);

    int isValid = 0;
    while (!isValid) {
        isValid = 1;
        char newCategoryName[10];
        printf("Nhap ten moi cho danh muc (toi da 9 ky tu): ");
        scanf("%s", newCategoryName);
        getchar();
        if (strlen(newCategoryName) == 0 || strlen(newCategoryName) > 9) {
            printf("Loi: CategoryName khong hop le. Vui long nhap lai.\n");
            isValid = 0;
            continue;
        }
        for (int j = 0; j < categoryCount; j++) {
            if (j != categoryIndex && strcmp(categories[j].CategoryName, newCategoryName) == 0) {
                printf("Loi: Ten danh muc '%s' da ton tai. Vui long nhap ten khac.\n", newCategoryName);
                isValid = 0;
                break;
            }
        }
        if (isValid) {
            strcpy(editedCategory->CategoryName, newCategoryName);
            printf("\nSua thong tin danh muc thanh cong!\n");
            saveCategoriesToFile(categories, categoryCount);
        }
    }
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}


void deleteCategory(category categories[], int *categoryCount) {
    if (*categoryCount == 0) {
        getchar();
        printf("\nDanh sach danh muc trong. Khong co gi de sua!\n");
        printf("\n--- Nhan phim bat ky de quay lai ---\n");
        getchar();
        return;
    }
    printf("\n\t*** Hien thi danh muc ***\n");
    printf("=========================================================================================================\n");
    printf("| %-5s | %-10s | %-25s |\n", "STT", "CategoryId", "CategoryName");
    printf("=========================================================================================================\n");
	int i;
    for (i = 0; i < *categoryCount; i++) {
        printf("| %-5d | %-10s | %-25s |\n", i + 1, categories[i].CategoryId, categories[i].CategoryName);
    }

    printf("=========================================================================================================\n");
    char targetId[10];
    int found = -1;
    printf("\n\t*** Xoa danh muc ***\n");
    printf("=========================\n");
    printf("Nhap ID danh muc muon xoa: ");
    scanf("%s", targetId);
    getchar();
    for (int i = 0; i < *categoryCount; i++) {
        if (strcmp(categories[i].CategoryId, targetId) == 0) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("\nLoi: ID danh muc '%s' khong ton tai.\n", targetId);
        return;
    }

    char confirm;
    printf("\nDanh muc voi ID '%s' da ton tai. Ban co chac chan muon xoa? (Y/N): ", targetId);
    scanf(" %c", &confirm);
    getchar();

    if (confirm == 'Y' || confirm == 'y') {
        for (int i = found; i < *categoryCount - 1; i++) {
            categories[i] = categories[i + 1];
        }
        (*categoryCount)--;
        saveCategoriesToFile(categories, *categoryCount);
        printf("\nXoa danh muc voi ID '%s' thanh cong!\n", targetId);
    } else {
        printf("\nHuy thao tac xoa danh muc.\n");
    }
    getchar();
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}
void sortCategoriesByName(category categories[], int categoryCount) {
    if (categoryCount == 0) {
        printf("\nDanh sach danh muc trong. Khong co gi de sap xep!\n");
        return;
    }
    int choice;
    printf("\n\t*** Sap xep danh sach danh muc theo ten ***\n");
    printf("=========================================\n");
    printf("1. Sap xep tang dan theo ten\n");
    printf("2. Sap xep giam dan theo ten\n");
    printf("0. Thoat\n");
    printf("=========================================\n");
    printf("Chon mot tuy chon: ");
    scanf("%d", &choice);

    if (choice == 0) {
        printf("\nThoat sap xep.\n");
        return;
    }
    for (int i = 0; i < categoryCount - 1; i++) {
        for (int j = i + 1; j < categoryCount; j++) {
            int condition = 0;

            if (choice == 1) {
                condition = strcmp(categories[i].CategoryName, categories[j].CategoryName) > 0;
            } else if (choice == 2) {
                condition = strcmp(categories[i].CategoryName, categories[j].CategoryName) < 0;
            }
            if (condition) {
                category temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
            }
        }
    }
    printf("\nSap xep danh sach danh muc thanh cong!\n");
    displayCategoryList(categories, categoryCount);
    getchar();
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}
int containsIndependentWord(const char *haystack, const char *needle) {
    const char *current = haystack;
    size_t needleLength = strlen(needle);

    while ((current = strstr(current, needle)) != NULL) {
        char before = (current == haystack) ? ' ' : *(current - 1);
        char after = *(current + needleLength);

        if (isspace(before) || ispunct(before)) {
            if (isspace(after) || ispunct(after) || after == '\0') {
                return 1;
            }
        }
        current += needleLength;
    }
    return 0;
}
void searchCategoryByName(category categories[], int categoryCount) {
    if (categoryCount == 0) {
        printf("\nDanh sach danh muc trong. Khong co gi de tim kiem!\n");
        return;
    }
    char searchTerm[50];
    int foundCount = 0;
    printf("\n\t*** Tim kiem danh muc theo ten ***\n");
    printf("Nhap chuoi can tim kiem: ");
    getchar();
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';
    printf("\nKet qua tim kiem cho '%s':\n", searchTerm);
    printf("=====================================================================================\n");
    printf("| %-5s | %-10s | %-25s |\n", "STT", "CategoryID", "CategoryName");
    printf("=====================================================================================\n");
    for (int i = 0; i < categoryCount; i++) {
        if (containsIndependentWord(categories[i].CategoryName, searchTerm)) {
            foundCount++;
            printf("| %-5d | %-10s | %-25s |\n", foundCount, categories[i].CategoryId, categories[i].CategoryName);
        }
    }
    if (foundCount == 0) {
        printf("\nKhong tim thay danh muc nao phu hop voi chuoi '%s'.\n", searchTerm);
    } else {
        printf("=====================================================================================\n");
    }
    getchar();
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}
void saveCategoriesToFile(category categories[], int categoryCount) {
    FILE *file = fopen("categories.txt", "w");
    if (file == NULL) {
        printf("Loi: Khong the mo file de ghi.\n");
        return;
    }
    for (int i = 0; i < categoryCount; i++) {
        fprintf(file, "%s,%s\n", categories[i].CategoryId, categories[i].CategoryName);
    }
    fclose(file);
    printf("Luu danh muc vao file thanh cong!\n");
}
void loadCategoriesFromFile(category categories[], int *categoryCount) {
    FILE *file = fopen("categories.txt", "r");
    if (file == NULL) {
        printf("File danh muc khong ton tai. Khoi tao danh sach rong.\n");
        return;
    }
    *categoryCount = 0;
    while (fscanf(file, "%[^,],%[^\n]\n", categories[*categoryCount].CategoryId, categories[*categoryCount].CategoryName) != EOF) {
        (*categoryCount)++;
    }
    fclose(file);
    printf("Nap danh muc tu file thanh cong!\n");
}

void displayProductMenu() {
    printf("\nQuan ly san pham:\n");
    printf("1. Hien thi danh sach san pham\n");
    printf("2. Them san pham\n");
    printf("3. Sua thong tin san pham\n");
    printf("4. Xoa san pham\n");
    printf("5. Tim kiem san pham theo ten\n");
    printf("6. Sap xep san pham theo gia tien\n");
    printf("7. Loc san pham theo gia hoac danh muc\n");
    printf("8. Kiem tra du lieu nhap cho san pham\n");
    printf("9. Luu tru du lieu\n");
    printf("0. Thoat\n");
}
void displayLoginMenu() {
    printf("\nXac thuc admin:\n");
    printf("1. Dang nhap\n");
}
