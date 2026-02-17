#include<stdio.h>
void main(){
    long i, k;
    printf("\n Enter first integers: ");
    scanf("%ld",&i);
    printf("\n Enter second integers: ");
    scanf("%ld",&k);
    printf("\n Before swapping the values , value of a is %d and b is %d",i, k);
    i=i^k;
    k=i^k;
    i=i^k;

    printf("\n Values after swapped, for i is %ld and k is %ld", i, k);

}