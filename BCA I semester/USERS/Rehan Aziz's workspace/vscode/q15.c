// Q15> Write a C program to print the sum of the first 10 natural numbers using a loop.

#include <stdio.h>

int main() {
    int i, sum = 0;

    for(i = 1; i <= 10; i++) {
        sum = sum + i;
    }

    printf("Sum of the first 10 natural numbers = %d\n", sum);

    return 0;
}

