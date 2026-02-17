#include<stdio.h>
#define MAX 100
void main(){
    int count=0,n,arr[MAX],element;
    printf("\n Please enter the number of elements you want to reserve in array\n==> ");
    scanf("%d",&n);
    printf("\n Please enter elements");
    for(int i=0;i<n;i++){
        printf("\n ==>");
        scanf("%d",&arr[i]);
    }
    printf("\n Please enter the element you'd like to search and it's occurance\n==>");
    scanf("%d",&element);
    for(int i=0;i<n;i++){
        if(arr[i]==element){
            count++;
        }
    }
    if(count!=0){
        printf("\n Element found at the follow indices : ");
        for(int i=0;i<n;i++){
            if(arr[i]==element){
                printf(" %d",i);
            }
        }
    }
    


}