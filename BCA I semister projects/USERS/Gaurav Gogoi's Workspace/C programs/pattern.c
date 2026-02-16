// This program fascilates printing of the following pattern automatically using for loop
/*                                  ******
                                    *****
                                    ****
                                    ***
                                    **
                                    *
   
*/
#include<stdio.h>
void main(){
for(int j=6;j>=1;j--){
    for(int i=1;i<=j;i++){
        printf("*");
    }
printf("\n");
}
}