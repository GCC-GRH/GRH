#include<stdio.h>
void main(){
    printf("\n This program fascillates uses of conditional statement break which allows a user or dev to state multiple conditions to with multiple results");
    int day;
    printf("\n Please enter your day : ");
    scanf("%d",&day);
    switch(day){
        case 1 : printf("\n Monday");
        break;
        
        case 2 : printf("\n thusday");
        break;

        case 3 : printf("\n Wednesday");
        break;

        case 4 : printf("\n Thursday");
        break;

        case 5 : printf("\n Friday");
        break;

        case 6 : printf("\n Saturday");
        break;

        case 7 : printf("\n Sunday");
        break;

        default : printf("\n Invalid Day");
        break;


    }








}