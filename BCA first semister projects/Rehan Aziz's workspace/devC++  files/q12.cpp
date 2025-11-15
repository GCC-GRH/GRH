// Q12> 1.	Write a C program to calculate the factorial of a number using a loop.

#include <stdio.h>
#include <conio.h>

int main() {
    int n, i;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        fact = fact * i;
    }

    printf("Factorial of %d = %lld", n, fact);

    getch();    
    return 0;
}

