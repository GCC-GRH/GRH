#include<stdio.h>
void main(){
    int i=1,table1,table2,lcm,hcf,s,found=0;
    printf("\n Please enter first number: ");
    scanf("%d",&table1);
    printf("\n Please enter second: ");
    scanf("%d",&table2);
    while(found==0){
        if(i%table1==0 && i%table2==0){
            found=1;
            lcm=i;
            hcf=(table1*table2)/lcm;
        }
    i++;
    }
   printf("\n LCM is %d",lcm);
   printf("\n HCF is %d",hcf);

}