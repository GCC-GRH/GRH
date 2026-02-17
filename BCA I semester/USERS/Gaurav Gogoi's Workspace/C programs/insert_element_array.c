#include<stdio.h>
void main(){
    int numbers[10];
    int n,num,index;
    printf("\n Please enter the number of array spaces to be reserved ==>");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter value for %dth indice ==>",i);
        scanf("%d",&numbers[i]);
    }
    printf("\n Array elements in the memory : ");
    for(int i=0;i<n;i++){
        printf("%d ",numbers[i]);
    }
    printf("\n Please enter a number to insert \n==>");
    scanf("%d",&num);
    printf("\n Select postion of Index : ");
    scanf("%d",&index);
    numbers[index]=num;
    printf("\n Array elements in the memory : ");
    for(int i=0;i<n;i++){
        printf("%d ",numbers[i]);
    }


}