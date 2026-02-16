#include<stdio.h>
void main(){
    int number[5],temp;
    printf("\n Please enter the values : ");
    for(int i=0;i<5;i++){
        scanf("%d",&number[i]);
    }
    for(int i=0;i<5;i++){
        for(int j=i+1;j<5;j++){
            if(number[i]<number[j]){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }

    }
    printf("\n Array elements in ascending orders are : ");
    for(int i=0;i<5;i++)
        printf("%d ",number[i]);
}