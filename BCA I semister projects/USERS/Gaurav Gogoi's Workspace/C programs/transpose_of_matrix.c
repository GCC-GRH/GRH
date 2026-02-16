#include<stdio.h>
void main(){
    int n=3;
    int arr[3][3];
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
    // Transpose of a Matrix
    printf("\nTranspose Of a Matrix\n");
for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
        printf("%d ", arr[j][i]);
    }
    printf("\n");
}


}
