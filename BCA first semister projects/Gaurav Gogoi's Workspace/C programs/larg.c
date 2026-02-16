#include<stdio.h>
void main(){
    int a;
    printf("\n Please enter a number: ");
    scanf("%d",&a);
    if(a==0){
        printf("\n It is zero valued integer");
    }else if(a>0){
        printf("\n It is a positive valued integer");
        }else{
            printf("\n It is a negative valued integer");
        }
}