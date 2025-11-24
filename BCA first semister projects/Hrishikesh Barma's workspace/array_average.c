#include<stdio.h>
int main(){
    int mark[10]={90,85,78,90,89,82,87,90,91,95};
    int i,sum=0;
    float avg;
    for(i=0;i<=9;i++){
        sum+=mark[i];
    }
    avg=(float)sum/10;
    printf("average:%f",avg);
    return 0;
}