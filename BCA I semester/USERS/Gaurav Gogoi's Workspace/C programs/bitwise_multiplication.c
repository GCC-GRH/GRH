#include<stdio.h>
void main(){
    long num,tempnum;
    printf("\n Enter your given number: ");
    scanf("%ld",&num);
    tempnum=num;
    num=num<<2;
    printf("\n %ld x 4 = %ld", tempnum, num);
}

/*num = 3;         // binary: 0000 0011
num << 2 = 12;   // binary: 0000 1100




What does << do?
The expression num << 2 shifts all the bits of num to the left by 2 positions.

Shifting left by 1 position (num << 1) multiplies the number by 2

So, shifting left by 2 positions (num << 2) multiplies the number by 4

*/