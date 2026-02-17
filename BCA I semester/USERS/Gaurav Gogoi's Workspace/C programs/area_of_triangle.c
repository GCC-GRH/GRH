#include<stdio.h>
int main(){
    printf("\n This program evaluates the area of right angled triangle on the basis of length and breadth");
    printf("\n Enter the length : ");
    int length, breadth, evaluate;
    scanf("%d",&length);
    printf("\n Enter the breadth : ");
    scanf("%d",&breadth);
    evaluate=0.5*length*breadth;
    printf("\n The area of the given right angled triangle is : %d",evaluate);

    return 0;
}