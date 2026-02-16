#include<stdio.h>
#include<conio.h>
void main(){
    int n,i,sum=0;
    float avg=0.0;
    clrscr();
    printf("\n Choose a natural number: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        sum=sum+i;
        avg=sum/n;
        }
    printf("\n The sum of the given natural number=%d",sum);
    printf("\n The average of given natural numbers: %f",avg);
    getch();
}