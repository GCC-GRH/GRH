// Q13> 

#include <stdio.h>
#include <conio.h>

void main() {
    int n, i;
    long long fact = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(i = 1; i <= n; i++) {
        fact = fact * i;
    }

    printf("Factorial of %d = %lld", n, fact);

    getch();   // should work in Dev-C++ (some versions)
    return 0;
}

