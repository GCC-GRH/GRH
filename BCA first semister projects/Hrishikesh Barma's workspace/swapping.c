#include<stdio.h>
int main(){
    int a,b,temp;
    printf("enter any two number:\n");
    scanf("%d %d",&a,&b);
    printf("before swapping :a=%d b=%d\n",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("after the swapping :a=%d b=%d\n",a,b);
    return 0;
}