#include<stdio.h>
int main(){
    printf("This program is used for making a stair type pattern with * \n"); // Source code by Gaurav gogoi
    int i,j;
    for(i=1;i<=5;i++){
        for (j=1; j <= i; j++)
        {
            printf("*");
        }
        
        
        
        printf("\n");
    }
    return 0;
}