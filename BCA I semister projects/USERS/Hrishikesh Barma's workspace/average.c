#include<stdio.h>
int main(){
    int marks[10]={50,75,67,60,45,69,70,73,67,89};
    int i,sum=0;
    float avg;
    for(i=0;i<=9;i++){
        sum+=marks[i];
    }
    avg=(float)sum/10;
    printf("average:%f",avg);
    return 0;
}