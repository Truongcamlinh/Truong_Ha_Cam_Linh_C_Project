#include <stdio.h>
#include "function.h"

int main()
{
	category categories[100];
	int categoryCount=0;
	int choice;
	do
	{
		displayMainMenu();
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				categaryManagement(categories, &categoryCount);
				break;
		}
	}while(choice !=0);
}
