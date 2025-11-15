#include<stdio.h>
void main(){
    int num[10];
    int n,i=0;
    printf("\n Enter your array size : ");
    scanf("%d",&n);
    while(i<n){
        printf("\nEnter Value for position %dth: ",i);
        scanf("%d",&num[i]);
        i++;
    }
    i=0;
    printf("\n The even numbers from the array is ==> ");

    while(i<n){
        if(num[i]%2==0){
            printf(" %d",num[i]);
            
        }
        i++;
        }
        i=0;
        printf("\n The odd numbers from the array is ==> ");
        while(i<n){
            if(num[i]%2!=0){
                printf(" %d",num[i]);
            }
            i++;
        }
}