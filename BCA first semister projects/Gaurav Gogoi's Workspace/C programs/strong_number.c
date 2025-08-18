#include<stdio.h>
void main(){
    int temp,numb,i,factorial=1,sum=0,r;
    printf("Enter a number:");
    scanf("%d",&numb);
    temp=numb;
    while(numb!=0){
        factorial=1;
        r=numb%10;
        i=1;
        while(i<=r){
            factorial*=i;
            i++;
        }
        sum+=factorial;
        numb/=10;
        
    }
    if(temp==sum){
        printf("\n %d is a strong number",temp);

    }else{
        printf("\n %d is not a strong number",temp);
    }
}