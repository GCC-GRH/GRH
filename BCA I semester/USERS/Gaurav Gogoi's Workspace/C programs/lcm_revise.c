#include<stdio.h>
void main(){
    int i=1,flag=0;
    int table1,table2;
    int lcm,hcf;
    printf("\n Please enter table1 : ");
    scanf("%d",&table1);
    printf("\n Please enter table2 :");
    scanf("%d",&table2);
    while(flag!=1){
        if(i%table1==0 && i%table2==0){
            flag++;
            lcm=i;
            hcf=(table1*table2/lcm);
            printf("LCM of table %d and table %d is %d\nHCF is %d",table1,table2,lcm,hcf);
        }else{
            i++;
        }

    }
}