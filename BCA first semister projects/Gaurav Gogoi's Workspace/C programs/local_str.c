#include<stdio.h>
void main(){
    struct datas
    {
        char name[50];
        int age;
    };
    struct datas d1;
    
    
    printf("Please enter your name : ");
    scanf("%s",&d1.name);
    printf("\nPlease enter your age : ");
    scanf("%d",&d1.age);
    printf("\n Your name is ");
    puts(d1.name);
    printf(" and your age is %d",d1.age);
    
}