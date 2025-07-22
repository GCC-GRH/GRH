#include <stdio.h>

int main() {
    int x, y, z, max;

    printf("\nPlease enter your value x: ");
    scanf("%d", &x);

    printf("\nPlease enter your value y: ");
    scanf("%d", &y);

    printf("\nPlease enter your value z: ");
    scanf("%d", &z);

    max = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);

    printf("\nMax value ==> %d\n", max);

    return 0;
}
