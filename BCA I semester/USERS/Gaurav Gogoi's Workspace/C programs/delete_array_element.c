#include<stdio.h>
void main(){
    int element[10],n,del;
    printf("\n Please enter the number of elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\n==>");
        scanf(" %d",&element[i]);
    }
    printf("\n The elements stored within the array is : ");
    for(int i=0;i<n;i++){
        printf("%d ",element[i]);
    }
    printf("\n Please enter the value you want to delete : ");
    scanf("%d",&del);
    for(int i=0;i<n;i++){
        if(del==element[i]){
            for(int j=i;j<n;j++)
                element[j]=element[j+1];
        }
    }
    n--;
    printf("\n The array elements are : ");
    for(int i=0;i<n;i++)
        printf("%d ",element[i]);
    
}