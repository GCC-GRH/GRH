#include<stdio.h>
void main(){
    int n=3;
    int arr[3][3];
    int sum=0;
    printf("Please enter matrix elements :\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    // General matrix
    printf("General Matrix\n");
    for(int i=0;i<n;i++,printf("\n")){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                sum+=arr[i][j];
            }
        }
    }
    printf("\n The sum of diagonal elements of a Matrix is %d",sum);
}