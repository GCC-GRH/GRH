#include<stdio.h>
void main(){
    int a=5,b=7,c=2;
    if(a>b){
        if(a>c){
            printf("The value of a variable is greater");
        }else{
            printf("\n The value of c variable is greater");
        }
    }else{
        if(b>c){
            printf("\n The value of b is greater then c");
        }else{
            printf("\n The value of c is greater then b");
        }
    }
}