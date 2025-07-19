#include <stdio.h>
void main(){
    int a[1];
    printf("\n Space reserved : %dth \n",sizeof(a)/sizeof(a[0]));
    printf(" The size of variable a is %d \n",sizeof(a));
    printf("In bits %d bits",sizeof(a)*8);
}