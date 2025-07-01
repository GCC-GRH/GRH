#include<stdio.h>
int main()
{
    //This program fascillates summation of N numbers specified by a user each time the loop executes wrt to loop through scanf function. This program uses the concept of for-loop.
    int i,N,var,sum=0;
    printf("\n Please Enter the value N :");
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        printf("\n Please enter the %d number to sum: ",i);
        scanf("%d",&var);
        sum=sum+var;

    }
    printf("\n The summation is %d", sum);
    return 0;
} 