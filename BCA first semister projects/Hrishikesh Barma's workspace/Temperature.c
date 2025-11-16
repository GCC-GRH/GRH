#include<stdio.h>
int main(){
    float C,F;
    printf("Enter the celsius:\n");
    scanf("%f",&C);
    F=(C*9/5)+32;
    printf("The fahrenheit of given celsius is:%f",F);
    return 0;
}