#include<stdio.h>
int main(){
    int num[2][2];
    int i,j;
    printf("Enter the 4 element of the 2*2 matrix:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",&num[i][j]);
        }
    }
    printf("The 2*2 matrix is:\n");
    for(i=0;i<2;i++,printf("\n")){
        for(j=0;j<2;j++){
            printf("%d",num[i][j]);
        }
        printf("\n",i);
    }
    return 0;
}