#include<stdio.h>
#include<ctype.h> //Use of ctype functions to perform some evaluations on character parameters
void main(){
    char c;
    printf("\n Please enter your character: ");
    scanf("%c",&c);
    if(isupper(c)){
        printf("\n It is a upper-case character");
    }else{
        if(islower(c)){
        printf("\n It is a lower-case character");
    }else{
        if(isdigit(c)){
            printf("\n It is a digit character");
        }else{
            printf("\n It is a special character");
        }
    }
}
}