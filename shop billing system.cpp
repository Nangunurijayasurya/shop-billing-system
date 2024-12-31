
#include <stdio.h>

#define MAX_ITEMS 100

typedef struct
 {
    char name[50];
    float price;
    int quantity;
} Item;


float calculateCost(Item item)
 {
    return item.price*item.quantity;

}

int main() 
{
    Item items[MAX_ITEMS];
    int numItems=0;
    float totalBill=0;

    int choice;

    do {
    	printf("\n*************SUPRE MARKET************\n");
        printf("\n========== Shop Billing System ==========\n");
		printf("1. Add Item\n");
        printf("2. Calculate Bill\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) 
		{
            case 1: 
			{
                if (numItems<MAX_ITEMS)
				 {
                    Item newItem;

                   
	        printf("Enter item	 name: ");
                    scanf("%s",newItem.name);
                    printf("Enter item price: ");
                    scanf("%f",&newItem.price);
                    printf("Enter item quantity: ");
                    scanf("%d",&newItem.quantity);

                    items[numItems++]=newItem;

                    printf("Item added successfully\n");
                } 

	else
	 {
                    printf("Maximum number of items reached\n");
                }
                
                break;
            }
            case 2:
           {
                if (numItems>0)
				 {
                    totalBill=0;

                    printf("\n========== Bill Details ==========\n");
                    printf("Item\tPrice\tQuantity\tCost\n");

                    for (int i=0;i<numItems;i++)
					 {
                        float itemCost=calculateCost(items[i]);
                        totalBill+=itemCost;

                     printf("%s\t%.2f\t%d\t\t%.2f\n",items[i].name,items[i].price,
						 items[i].quantity,itemCost);
                    }

                    printf("\nTotal Bill:%.2f\n",totalBill);
                } 
				else 
				{
                    printf("No items found\n");
                }
                break;
            }
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } 
	while (choice != 3);

    return 0;
}

