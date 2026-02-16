// Q 13> Write a C program to print the first 10 natural numbers using a for loop.

#include<stdio.h>
#include<conio.h>

void main() {
    int i;
    printf("The first 10 natural numbers are:\n");

    for(i = 1; i <= 10; i++) {
        printf("%d ", i);
    }

    getch();
}

