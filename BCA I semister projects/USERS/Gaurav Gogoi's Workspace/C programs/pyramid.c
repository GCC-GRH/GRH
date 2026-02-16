/*
     *
    * *
   * * *
  * * * * 
 * * * * *

*/
#include<stdio.h>
void main(){
int input;
printf("\n Please enter the number of rows : ");
scanf("%d",&input);

    for(int i=1;i<=input;i++){
        
        for(int j=input;j>i;j--){
            printf(" ");

        }
        
        for(int k=1;k<=i;k++){
            printf("* ");
        }
        
        
        
        
        printf("\n");
    }
}