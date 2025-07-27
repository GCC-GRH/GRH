#include<stdio.h>
void main(){
    char ch;
    printf("\n Please enter your character : ");
    scanf("%c",&ch);
    if(ch =='a' || ch =='i' || ch =='u' || ch =='e' || ch=='o' ){ //Japanese vowel format
        printf("\n It is a variable ");
    }else{
        printf("\n It is not a variable ");
    }
}