#include<stdio.h>
void main(){
    int temp;
    int arr[10]={21,22,31,55,24,98,33,53,11,76};
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
        if(arr[i]<arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    }
    printf("\n Array in ascending order is \n");
    for(int i=0;i<10;i++){
        printf("%d\t",arr[i]);
    }
}