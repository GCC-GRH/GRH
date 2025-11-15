#include<stdio.h>
struct A{
int x;
}
int main(){
    struct A a;
    a.x=11;
    printf("%d",&a.x);
    return 0;
}


