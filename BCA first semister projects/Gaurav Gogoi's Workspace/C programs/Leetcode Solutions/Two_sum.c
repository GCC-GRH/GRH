#include<stdio.h>
void main(){
    int arr[10]; //Array declaration
    int n,arrSize,targetVal; //Array Space iterator
    register int i; // Register based memory allocation
    printf("Please enter array size \n==>");
    scanf("%d",&n);
    for(i=0;i<n;i++,scanf("%d",&arr[i]));
    for(i=0;i<n;i++,printf("%d\t",arr[i]));
    printf("Please enter your target sum value : ");
    scanf("%d",&targetVal);
    printf("End of program. Function return code : %d",twoSum(arr,arrSize,targetVal));
}

int twoSum(int arr[],int size, int target){
    // Two summation logic
};