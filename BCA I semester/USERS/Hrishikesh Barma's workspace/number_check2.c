#include<stdio.h>
int main(){
    int a; 
    printf("enter any number:");
    scanf("%d",&a);
   if(a==0){
    printf("The given number is zero");
   }else if(a>0){
    printf("The given number is positive");
   }else{
    printf("The given number is negative");
   } 
   return 0;
}