#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "function.h"

void displayMainMenu() {
        system("cls");
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
                break;
            case 7:
                saveCategoriesToFile(categories, *categoryCount);
                break;
            case 0:
                break;
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
        printf("\nDanh sach danh muc trong. Khong co gi de xoa!\n");
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
        printf("\n--- Nhan phim bat ky de quay lai ---\n");
        getchar();
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
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}
void sortCategoriesByName(category categories[], int categoryCount) {
    if (categoryCount == 0) {
        getchar();
        printf("\nDanh sach danh muc trong. Khong co gi de sap xep!\n");
        getchar();
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
        getchar();
        printf("\nDanh sach danh muc trong. Khong co gi de tim kiem!\n");
        getchar();
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
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}
void saveCategoriesToFile(category categories[], int categoryCount) {
    FILE *file = fopen("categories.dat", "w");
    if (file == NULL) {
        printf("Loi: Khong the mo file de ghi.\n");
        return;
    }
    for (int i = 0; i < categoryCount; i++) {
        fprintf(file, "%s,%s\n", categories[i].CategoryId, categories[i].CategoryName);
    }
    fclose(file);
    getchar();
    printf("Luu danh muc vao file thanh cong!\n");
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}
void loadCategoriesFromFile(category categories[], int *categoryCount) {
    FILE *file = fopen("categories.dat", "r");
    if (file == NULL) {
        printf("File danh muc khong ton tai. Khoi tao danh sach rong.\n");
        return;
    }
    *categoryCount = 0;
    while (fscanf(file, "%[^,],%[^\n]\n", categories[*categoryCount].CategoryId, categories[*categoryCount].CategoryName) != EOF) {
        (*categoryCount)++;
    }
    fclose(file);
}


void displayProductMenu(product products[], int *productCount, category categories[], int *categoryCount) {
    int choice;
    do {
        system("cls");
        printf("\n\t*** Quan Ly San Pham ***\n");
        printf("=========================================================================================================\n");
        printf("| %-3s | %-75s |\n", "ID", "Hanh dong");
        printf("=========================================================================================================\n");
        printf("| %-3d | %-75s |\n", 1, "Hien thi danh sach san pham");
        printf("| %-3d | %-75s |\n", 2, "Them san pham");
        printf("| %-3d | %-75s |\n", 3, "Sua thong tin san pham");
        printf("| %-3d | %-75s |\n", 4, "Xoa san pham");
        printf("| %-3d | %-75s |\n", 5, "Tim kiem san pham theo ten");
        printf("| %-3d | %-75s |\n", 6, "Sap xep san pham theo gia tien");
        printf("| %-3d | %-75s |\n", 7, "Loc san pham");
        printf("| %-3d | %-75s |\n", 0, "Thoat");
        printf("=========================================================================================================\n");
        printf("Chon mot tuy chon: ");
        scanf("%d", &choice);

        system("cls");
        switch (choice) {
            case 1:
                displayProductList(products, *productCount);
                break;
            case 2:
                addProduct(products, productCount);
                break;
            case 3:
                editProduct(products, *productCount);
                break;
            case 4:
                deleteProduct(products, productCount);
                break;
            case 5:
                searchProductByName(products, *productCount);
                break;
            case 6:
                sortProductsByPrice(products, *productCount);
                break;
            case 7:
                filterProductsByCategory(products, *productCount, categories, *categoryCount);
                break;
            case 0:
                printf("Thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
}

void displayProductList(product products[], int productCount) {
    if (productCount == 0) {
        getchar();
        printf("\n\t*** Danh sach san pham ***\n");
        printf("==========================================\n");
        printf("\t\tDanh sach rong\n");
        printf("\n--- Nhan phim bat ky de quay lai ---\n");
        getchar();
        printf("==========================================\n");
        return;
    }
    printf("\n\t*** Hien thi danh sach san pham ***\n");
    printf("=========================================================================================================\n");
    printf("| %-5s | %-10s | %-25s | %-10s | %-10s |\n", "STT", "ProductId", "ProductName", "Quantity", "Price");
    printf("=========================================================================================================\n");
    for (int i = 0; i < productCount; i++) {
        printf("| %-5d | %-10s | %-25s | %-10d | %-10d |\n", i + 1, products[i].productId, products[i].productName, products[i].quantity, products[i].price);
    }
    printf("=========================================================================================================\n");
    getchar();
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}

void addProduct(product products[], int *productCount) {
    printf("\n\t*** Them san pham ***\n");
    printf("=========================================================================================================\n");
    product newProduct;
    int idExist = 0;
    int nameExist = 0;
    getchar();

    do {
        idExist = 0;
        printf("Nhap ID san pham (ID duy nhat): ");
        fgets(newProduct.productId, 100, stdin);
        newProduct.productId[strcspn(newProduct.productId, "\n")] = '\0';
        for (int i = 0; i < *productCount; i++) {
            if (strcmp(products[i].productId, newProduct.productId) == 0) {
                idExist = 1;
                break;
            }
        }
        if (idExist) {
            printf("ID san pham da ton tai. Vui long nhap ID khac.\n");
        }
    } while (idExist);
    do {
        nameExist = 0;
        printf("Nhap ten san pham: ");
        fgets(newProduct.productName, sizeof(newProduct.productName), stdin);
        newProduct.productName[strcspn(newProduct.productName, "\n")] = '\0';

        if (strlen(newProduct.productName) == 0) {
            printf("Ten san pham khong duoc rong. Vui long nhap lai.\n");
        } else {
            nameExist = 0;
            for (int i = 0; i < *productCount; i++) {
                if (strcmp(products[i].productName, newProduct.productName) == 0) {
                    nameExist = 1;
                    break;
                }
            }
            if (nameExist) {
                printf("Ten san pham da ton tai. Vui long nhap ten san pham khac.\n");
            }
        }
    } while (strlen(newProduct.productName) == 0 || nameExist);
    do {
        printf("Nhap so luong san pham: ");
        if (scanf("%d", &newProduct.quantity) != 1) {
            printf("Nhap sai, vui long nhap lai so luong.\n");
            while(getchar() != '\n');
        } else if (newProduct.quantity < 0) {
            printf("So luong san pham khong the am. Vui long nhap lai.\n");
        }
    } while (newProduct.quantity < 0);
    do {
        printf("Nhap gia san pham: ");
        if (scanf("%d", &newProduct.price) != 1) {
            printf("Nhap sai, vui long nhap lai gia.\n");
            while(getchar() != '\n');
        } else if (newProduct.price <= 0) {
            printf("Gia san pham phai lon hon 0. Vui long nhap lai.\n");
        }
    } while (newProduct.price <= 0);
    products[*productCount] = newProduct;
    (*productCount)++;
    printf("San pham da them thanh cong!\n");
    getchar();
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}

void editProduct(product products[], int productCount) {
    getchar();
    if (productCount == 0) {
        getchar();
        printf("\n\t*** Danh sach san pham ***\n");
        printf("==========================================\n");
        printf("\t\tDanh sach rong\n");
        printf("\n--- Nhan phim bat ky de quay lai ---\n");
        getchar();
        printf("==========================================\n");
        return;
    }
    printf("\n\t*** Sua san pham ***\n");
    printf("=========================================================================================================\n");
    printf("\n\t*** Hien thi danh sach san pham ***\n");
    printf("=========================================================================================================\n");
    printf("| %-5s | %-10s | %-25s | %-10s | %-10s |\n", "STT", "ProductId", "ProductName", "Quantity", "Price");
    printf("=========================================================================================================\n");

    for (int i = 0; i < productCount; i++) {
        printf("| %-5d | %-10s | %-25s | %-10d | %-10d |\n", i + 1, products[i].productId, products[i].productName, products[i].quantity, products[i].price);
    }
    printf("=========================================================================================================\n");
    char productId[10];
    int found = 0;
    printf("Nhap ID san pham muon sua: ");
    fgets(productId, 100, stdin);
    productId[strcspn(productId, "\n")] = '\0';
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].productId, productId) == 0) {
            found = 1;
            printf("\nThong tin san pham hien tai:\n");
            printf("ID: %s\n", products[i].productId);
            printf("Ten: %s\n", products[i].productName);
            printf("So luong: %d\n", products[i].quantity);
            printf("Gia: %d\n", products[i].price);
            do {
                printf("Nhap ten san pham moi: ");
                fgets(products[i].productName, 100, stdin);
                products[i].productName[strcspn(products[i].productName, "\n")] = '\0';
                if (strlen(products[i].productName) == 0) {
                    printf("Ten san pham khong duoc rong. Vui long nhap lai.\n");
                }
            } while (strlen(products[i].productName) == 0);
            do {
                printf("Nhap so luong san pham moi: ");
                if (scanf("%d", &products[i].quantity) != 1) {
                    printf("Nhap sai, vui long nhap lai so luong.\n");
                    while(getchar() != '\n');
                } else if (products[i].quantity < 0) {
                    printf("So luong san pham khong the am. Vui long nhap lai.\n");
                }
            } while (products[i].quantity < 0);
            do {
                printf("Nhap gia san pham moi: ");
                if (scanf("%d", &products[i].price) != 1) {
                    printf("Nhap sai, vui long nhap lai gia.\n");
                    while(getchar() != '\n');
                } else if (products[i].price <= 0) {
                    printf("Gia san pham phai lon hon 0. Vui long nhap lai.\n");
                }
            } while (products[i].price <= 0);
            printf("San pham da duoc cap nhat thanh cong!\n");
            break;
            getchar();
        }
    }
    if (!found) {
        printf("ID san pham khong ton tai.\n");
    }
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}

void deleteProduct(product products[], int *productCount) {
    getchar();
    if (*productCount == 0) {
        printf("\n\t*** Danh sach san pham ***\n");
        printf("==========================================\n");
        printf("\t\tDanh sach rong\n");
        printf("\n--- Nhan phim bat ky de quay lai ---\n");
        getchar();
        printf("==========================================\n");
        return;
    }
    printf("\n\t*** Xoa san pham ***\n");
    printf("=========================================================================================================\n");
    printf("\n\t*** Hien thi danh sach san pham ***\n");
    printf("=========================================================================================================\n");
    printf("| %-5s | %-10s | %-25s | %-10s | %-10s |\n", "STT", "ProductId", "ProductName", "Quantity", "Price");
    printf("=========================================================================================================\n");
    for (int i = 0; i < *productCount; i++) {
        printf("| %-5d | %-10s | %-25s | %-10d | %-10d |\n", i + 1, products[i].productId, products[i].productName, products[i].quantity, products[i].price);
    }
    printf("=========================================================================================================\n");
    char productId[10];
    int found = 0;
    printf("Nhap ID san pham muon xoa: ");
    fgets(productId, sizeof(productId), stdin);
    productId[strcspn(productId, "\n")] = '\0';
    for (int i = 0; i < *productCount; i++) {
        if (strcmp(products[i].productId, productId) == 0) {
            found = 1;
            printf("\nThong tin san pham can xoa:\n");
            printf("ID: %s\n", products[i].productId);
            printf("Ten: %s\n", products[i].productName);
            printf("So luong: %d\n", products[i].quantity);
            printf("Gia: %d\n", products[i].price);
            char confirm;
            printf("Ban co chac chan muon xoa san pham nay? (y/n): ");
            scanf(" %c", &confirm);
            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < *productCount - 1; j++) {
                    products[j] = products[j + 1];
                }
                (*productCount)--;
                printf("San pham da duoc xoa thanh cong!\n");
            } else {
                printf("Huy xoa san pham.\n");
            }
            getchar();
            break;
        }
    }
    if (!found) {
        printf("ID san pham khong ton tai.\n");
    }
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}

void searchProductByName(product products[], int productCount) {
    getchar();
    if (productCount == 0) {
        printf("\n\t*** Danh sach san pham ***\n");
        printf("==========================================\n");
        printf("\t\tDanh sach rong\n");
        printf("\n--- Nhan phim bat ky de quay lai ---\n");
        getchar();
        printf("==========================================\n");
        return;
    }
    char searchName[50];
    int found = 0;
    printf("\n\t*** Tim kiem san pham theo ten ***\n");
    printf("Nhap ten san pham muon tim: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';
    printf("\n\t*** KET QUA TIM KIEM ***\n");
    printf("=========================================================================================================\n");
    printf("| %-5s | %-10s | %-25s | %-10s | %-10s |\n", "STT", "ProductId", "ProductName", "Quantity", "Price");
    printf("=========================================================================================================\n");
    for (int i = 0; i < productCount; i++) {
        if (strstr(products[i].productName, searchName) != NULL) {
            found = 1;
            printf("| %-5d | %-10s | %-25s | %-10d | %-10d |\n", i + 1, products[i].productId, products[i].productName, products[i].quantity, products[i].price);
        }
    }
    printf("=========================================================================================================\n");
    if (!found) {
        printf("Khong tim thay san pham nao co ten chua \"%s\".\n", searchName);
    }
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}

void sortProductsByPrice(product products[], int productCount) {
    if (productCount == 0) {
        printf("\n\t*** Danh sach san pham ***\n");
        printf("==========================================\n");
        printf("\t\tDanh sach rong\n");
        printf("\n--- Nhan phim bat ky de quay lai ---\n");
        getchar();
        printf("==========================================\n");
        return;
    }
    int indices[productCount];
    for (int i = 0; i < productCount; i++) {
        indices[i] = i;
    }
    int choice;
    printf("\n\t*** Sap xep san pham theo gia ***\n");
    printf("Chon thu tu sap xep:\n");
    printf("1. Sap xep tang dan theo gia\n");
    printf("2. Sap xep giam dan theo gia\n");
    printf("Nhap lua chon (1 hoac 2): ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            for (int i = 0; i < productCount - 1; i++) {
                for (int j = i + 1; j < productCount; j++) {
                    if (products[indices[i]].price > products[indices[j]].price) {
                        int temp = indices[i];
                        indices[i] = indices[j];
                        indices[j] = temp;
                    }
                }
            }
            printf("Danh sach san pham da duoc sap xep theo gia (tang dan).\n");
            break;
        case 2:
            for (int i = 0; i < productCount - 1; i++) {
                for (int j = i + 1; j < productCount; j++) {
                    if (products[indices[i]].price < products[indices[j]].price) {
                        int temp = indices[i];
                        indices[i] = indices[j];
                        indices[j] = temp;
                    }
                }
            }
            printf("Danh sach san pham da duoc sap xep theo gia (giam dan).\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
            return;
    }
    printf("\n\t*** Danh sach san pham sau khi sap xep ***\n");
    printf("=========================================================================================================\n");
    printf("| %-5s | %-10s | %-25s | %-10s | %-10s |\n", "STT", "ProductId", "ProductName", "Quantity", "Price");
    printf("=========================================================================================================\n");
    for (int i = 0; i < productCount; i++) {
        int idx = indices[i];
        printf("| %-5d | %-10s | %-25s | %-10d | %-10d |\n", i + 1, products[idx].productId, products[idx].productName, products[idx].quantity, products[idx].price);
    }
    printf("=========================================================================================================\n");

    getchar();
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}

void saveProductsToFile(product *products, int productCount) {
    FILE *file = fopen("products.dat", "w");
    if (file == NULL) {
        printf("Loi khi mo file de ghi du lieu!\n");
        return;
    }
    fwrite(&productCount, sizeof(int), 1, file);
    for (int i = 0; i < productCount; i++) {
        fwrite(&products[i], sizeof(product), 1, file);
    }
    fclose(file);
    printf("Du lieu san pham da duoc luu vao file.\n");
}

void filterProductsByCategory(product products[], int productCount,category categories[], int categoryCount) {
    int choice;
    getchar();
    printf("\n\t*** Loc san pham theo ***\n");
    printf("1. Loc theo danh muc\n");
    printf("2. Loc theo gia tien\n");
    printf("Chon 1 hoac 2: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1) {
        char categoryId[10];
        int found = 0;
        printf("Nhap ID danh muc: ");
        fgets(categoryId, 100, stdin);
        categoryId[strcspn(categoryId, "\n")] = '\0';
        int categoryExist = 0;
        for (int i = 0; i < categoryCount; i++) {
            if (strcmp(categories[i].CategoryId, categoryId) == 0) {
                categoryExist = 1;
                break;
            }
        }
        if (!categoryExist) {
            printf("ID danh muc khong ton tai.\n");
            getchar();
            printf("\n--- Nhan phim bat ky de quay lai ---\n");
            getchar();
            return;
        }
        printf("Danh sach san pham trong danh muc %s:\n", categoryId);
        int foundInCategory = 0;
        printf("| %-5s | %-10s | %-25s | %-10s | %-10s |\n", "STT", "ProductId", "ProductName", "Quantity", "Price");
        for (int i = 0; i < productCount; i++) {
            if (strcmp(products[i].categoryId, categoryId) == 0) {
                printf("| %-5d | %-10s | %-25s | %-10d | %-10d |\n", i + 1, products[i].productId, products[i].productName, products[i].quantity, products[i].price);
                foundInCategory = 1;
            }
        }
        if (!foundInCategory) {
            printf("Khong co san pham trong danh muc nay.\n");
        }
    }
    else if (choice == 2) {
        int minPrice, maxPrice;
        printf("Nhap gia bat dau: ");
        scanf("%d", &minPrice);
        printf("Nhap gia ket thuc: ");
        scanf("%d", &maxPrice);
        getchar();

        if (minPrice > maxPrice) {
            printf("Khoang gia khong hop le. Gia bat dau phai nho hon gia ket thuc.\n");
            getchar();
            printf("\n--- Nhan phim bat ky de quay lai ---\n");
            getchar();
            return;
        }
        printf("Danh sach san pham trong khoang gia %d - %d:\n", minPrice, maxPrice);
        int foundInPriceRange = 0;
        printf("| %-5s | %-10s | %-25s | %-10s | %-10s |\n", "STT", "ProductId", "ProductName", "Quantity", "Price");
        for (int i = 0; i < productCount; i++) {
            if (products[i].price >= minPrice && products[i].price <= maxPrice) {
                printf("| %-5d | %-10s | %-25s | %-10d | %-10d |\n", i + 1, products[i].productId, products[i].productName, products[i].quantity, products[i].price);
                foundInPriceRange = 1;
            }
        }

        if (!foundInPriceRange) {
            printf("Khong co san pham trong khoang gia nay.\n");
        }
    } else {
        printf("Lua chon khong hop le.\n");
    }
    printf("\n--- Nhan phim bat ky de quay lai ---\n");
    getchar();
}


void loadProductsFromFile(product *products, int *productCount) {
    FILE *file = fopen("products.dat", "r");
    if (file == NULL) {
        printf("Khong the mo file de doc du lieu!\n");
        return;
    }
    fread(productCount, sizeof(int), 1, file);
    for (int i = 0; i < *productCount; i++) {
        fread(&products[i], sizeof(product), 1, file);
    }
    fclose(file);
    printf("Du lieu san pham da duoc tai tu file.\n");
}

void displayLoginMenu() {
    printf("\nXac thuc admin:\n");
    printf("1. Dang nhap\n");
}
