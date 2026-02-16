#include<stdio.h>

void main(){
    int sec,hour,min,second;
    printf("\n Please enter your seconds: ");
    scanf("%d",&sec);
    hour=sec/3600;
    min=hour%60;
    second=min%60;
    printf("\n HH:MM:SS ==> %d:%d:%d",hour,min,second);
}