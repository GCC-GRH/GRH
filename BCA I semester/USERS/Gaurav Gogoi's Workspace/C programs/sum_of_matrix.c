#include<stdio.h>
void main(){
    int i,j;
    int matrix1[3][3]={{1,2,1},{2,1,2},{6,2,1}};
    int matrix2[3][3]={{3,2,1},{2,1,3},{8,1,2}};
    int res_matrix[3][3];
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            res_matrix[i][j]=matrix1[i][j] + matrix2[i][j];
        }
    }
    printf("Resultant matrix value: \n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ",res_matrix[i][j]);
        }
        printf("\n");
    }
}