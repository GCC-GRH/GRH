#include<stdio.h>
void main(){
    int lcm,found,table1,table2;
    printf("Please enter the table one : ");
    scanf("%d",&table1);
    printf("\nPlease enter the table two : ");
    scanf("%d",&table2);
    int i=1;
    while(found==0){
        if(i%table1==0 && i%table2==0){
            found++;
            lcm=i;
        }
        i++;
    }
    printf("\n The LCM of Table %d and %d is %d",table1,table2,lcm);
    printf("\n The HCF is : %d",(table1*table2)/lcm);
}