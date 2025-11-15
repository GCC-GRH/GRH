#include<stdio.h>
void main(){
    int price,quantity,total_price;
    printf("Please enter the price of the product : ");
    scanf("%d",&price);
    printf("\nPlease number of quantity: ");
    scanf("%d",&quantity);
    total_price=price*quantity;
    printf("Total price :: %d",total_price);
    if(quantity>50){
        total_price=total_price*(100-10)/100;
        printf("\nDiscounted price by 10%% :: %d",total_price);
    }else{
        total_price=total_price*(100-5)/100;
        printf("Discounted price by 10%% :: %d",total_price);
    }
}