#include<stdio.h>
int twoSum(int arr[], int size, int target); // Function prototype or definition
void main(){
    int arr[10]; //Array declaration
    int n,arrSize,targetVal; //Array Space iterator
    int i; // Register based memory allocation
    printf("Please enter array size \n==>");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        printf("%d\t",arr[i]);
    };
    arrSize=n;
    printf("\nPlease enter your target sum value : ");
    scanf("%d",&targetVal);
    printf("End of program. Function return code : %d",twoSum(arr,arrSize,targetVal));
}

int twoSum(int arr[],int size, int target){
    // Two summation logic
    
    int i,j;
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if((arr[i]+arr[j])==target){
                printf("\n Indices found at [%d,%d]\n",i,j);
            }
        
        }
    }
    return 0;
}

#include<std