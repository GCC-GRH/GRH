#include<Stdio.h>
void main(){
    int a,b,max;
    printf("\n Please enter the first number : ");
    scanf("%d",&a);
    printf("\n Please enter the Second number : ");
    scanf("%d",&b);
    max=(a>b) ? a : b;
    printf("\n Maximum value is %d",max);
    
}