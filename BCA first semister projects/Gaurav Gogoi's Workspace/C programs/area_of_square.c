#include<stdio.h>
int main(){
    int length, area;
    printf("This program evaluates the given lengths and provides the area of square \n");
    printf("Please enter the length of side of a square :");
    scanf("%d",&length);
    area=length*length;
    printf("\n The area of square for the given length is %d ", area);
    return 0;
}