// Q14> Write a C program to print the multiplication table of a number using a for loop.

#include <stdio.h>
#include <conio.h>
void main() {
    int n, i;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    getch();
}

