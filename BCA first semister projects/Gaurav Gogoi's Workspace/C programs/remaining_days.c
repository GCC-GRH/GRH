#include<stdio.h>
int main(){
    int days, remaining_months, remaining_days;
    printf("\n This program prints the remaining months and associated days");
    printf("\n Enter your days: ");
    scanf("%d",&days);
    remaining_months=days/30;
    remaining_days=days%30;
    printf("\n The number of months left is %d and remaining days left %d ", remaining_months, remaining_days);
    return 0;
}