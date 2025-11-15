#include<stdio.h>
struct distance{
    int feet;
    float inches;
};

struct distance d1; //Global structure variable
void main(){
    struct distance d2; // local structure variable
    
    d1.feet=20;
    d1.inches=30;
    d2.feet=30;
    d2.inches=23.2;
    printf("%d\n%f\n%d\n%f",d1.feet,d1.inches,d2.feet,d2.inches);
    

}