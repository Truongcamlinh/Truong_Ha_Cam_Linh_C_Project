#include <stdbool.h>

struct Date
{
	int month, day, year;
};
typedef struct Date date;

struct Category
{
	char CategoryId[10];
	char CategoryName[10];
};
typedef struct Category category;

struct Product
{
	char productId[10];
	char categoryId[10];
	char productName[10];
	int quantity;
	int price;
};
typedef struct Product product;

