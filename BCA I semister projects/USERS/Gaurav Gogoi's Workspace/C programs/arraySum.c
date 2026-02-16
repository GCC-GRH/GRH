#include<stdio.h>
void main(){
    int number[10];
    int n,option=0;
    int j=0;
    int sum=0;
    printf("How many numbers would you like to insert in the array? \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\n Please enter the number for the %dth position of array ==> ",i);
        scanf("%d",&number[i]);
    }
    printf("\n Would you like to print the sum of the array numbers? Enter 1 for yes, 0 for NO \n");
    scanf("%d",&option);
    if(option==1){
        
        while (j<n){
            sum+=number[j];
            j++;
        }
        printf("Summation is %d",sum);
    }else{
        printf("\n End of loop");
    }

}