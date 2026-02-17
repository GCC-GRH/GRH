#include<stdio.h>
void main(){
    printf("Welcome to Commandlator! The minimal version of calculator used to perform calculatons.\n Version 0.0.1 \n");
    int number, number_two;
    char option=0;
    printf("Enter your number:\n");
    scanf("%d",&number);
    printf("Enter your second number: ");
    scanf("%d",&number_two);
    while(option==0){
    printf("\n Which operation would you like to perform? Enter + - / * or Mod operator:\n");
    scanf(" %c",&option);
    switch(option){
        case '+' : printf("\n The summation of the given operands %d and %d is %d",number,number_two,(number+number_two));
        option=1;
        break;

        case '-' : printf("\n The difference of the given operands %d and %d is %d",number,number_two,(number-number_two));
        option=1;
        break;

        case '/' : printf("\n The Division of the given operands %d and %d is %d",number,number_two,(number/number_two));
        option=1;
        break;

        case '*' : printf("\n The Multiplication of the given operands %d and %d is %d",number,number_two,(number*number_two));
        option=1;
        break;

        case 'm' : printf("\n The Remainder of the given operands %d and %d is %d",number,number_two,(number%number_two));
        option=1;
        break;

        default : printf("\n Invalid option! Please Re-enter your operator \n");
        option=0;
        break;
    

    }
}
}