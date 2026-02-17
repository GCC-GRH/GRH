#include<stdio.h>
int main(){
    int length, height, evaluate;
    printf("\n This program is used for evaluating the value of area of rectangle");
    printf("\n Enter the value of Length: ");
    scanf("%d", &length);
    printf("\n Enter the value of height: ");
    scanf("%d",&height);
    evaluate=length*height;
    printf("\n The area of rectangle is %d",evaluate);

    return 0;
}