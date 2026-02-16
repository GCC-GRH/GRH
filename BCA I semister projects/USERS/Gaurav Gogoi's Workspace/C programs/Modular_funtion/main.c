#include<stdio.h>
#include<stdlib.h>
#include<mod.h>
void main(){
    int return_value;
    return_value=increment();
    return_value=increment();
    return_value=increment();
    printf(" The returned value from the modular funtion is %d",return_value);
}