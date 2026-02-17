#include<stdio.h>
void main(){
    int num[10],n,c=0;
    int temp[10];
    printf("\n How many indices would you like to enter?\n==>");
    scanf("%d",&n);
    printf("\n Please enter the values");
    for(int i=0;i<n;i++){
        printf("\n ==> ");
        scanf("%d",&num[i]);

    }
    for (int i = 0; i < n; i++)
    {
        printf("\n Array in position %dth is %d",i,num[i]);
    }
    for(int i = n-1;i>=0;i--){
        temp[c]=num[i];
        c++;
    }
    c=0;
    for(int i=0;i<n;i++){
        num[i]=temp[c];
        c++;
    }
    for(c=0;c<n;c++){
        printf("\n Reversed array elements is %d",num[c]);
    }
    
}