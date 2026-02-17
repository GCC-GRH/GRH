#include<stdio.h>
int main()
{
    int i, N, sum=0;
    printf("\n This program prints the summation of series of N numbers");
    printf("\n Please enter the value of N to sum in series: ");
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        sum=sum+i;

    }
    printf("\n The value of summation of series of given N number is %d",sum);
    return 0;

}