#include <stdio.h>
#include "function.h" 

void displayMainMenu() {
        printf("\n\t*** Store Management ***\n");
    	printf("=========================================\n");
        printf("1. Quan ly danh muc\n");
        printf("2. Quan ly san pham\n");
        printf("0. Thoat\n");
        printf("=========================================\n");
        printf("Chon mot tuy chon: ");
}
void categaryManagement(category categories[], int *categoryCount) {
	int choice;
	do{
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
        printf("| %-3d | %-75s |\n", 7, "Kiem tra du lieu nhap cho danh muc");
        printf("| %-3d | %-75s |\n", 8, "Luu tru du lieu");
        printf("| %-3d | %-75s |\n", 0, "Thoat");
        printf("=========================================================================================================\n");
        printf("Chon mot tuy chon: ");
        scanf("%d", &choice);
    	
    	switch (choice)
    	{
    		case 1:
    			displayCategoryList(categories, *categoryCount);
    			break;
    		case 2:
    			addCategory(categories, categoryCount);
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
    printf("| %-10s | %-25s |\n", "CategoryId", "CategoryName");
    printf("=========================================================================================================\n");
    int i; 
    for (i = 0; i < categoryCount; ++i) {
        printf("| %-10s | %-25s |\n", categories[i].CategoryId, categories[i].CategoryName);
    }
    printf("=========================================================================================================\n");
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
        int found;

        printf("\nThem danh muc so %d\n", *categoryCount + 1);
        do {
            found = 0;
            printf("Nhap CategoryId: ");
            scanf("%s", newCategory.CategoryId);
            getchar(); 
            int j;
            for (j = 0; j < *categoryCount; j++) {
                if (strcmp(categories[j].CategoryId, newCategory.CategoryId) == 0) {
                    printf("Loi: CategoryId '%s' da ton tai. Vui long nhap ID khac.\n", newCategory.CategoryId);
                    found = 1;
                    break;
                }
            }
        } while (found);
        printf("Nhap CategoryName: ");
        scanf("%s", newCategory.CategoryName);
        getchar();
        categories[*categoryCount] = newCategory;
        (*categoryCount)++; 
        printf("Them danh muc thanh cong!\n");
    }
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
