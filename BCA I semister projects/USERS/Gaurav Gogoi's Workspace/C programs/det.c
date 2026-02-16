#include<stdio.h>
void main(){
    int det[3][3]={{3,2,6},
                   {5,2,5},
                   {7,3,1}};
    int res= (det[0][0]*((det[1][1]*det[2][2])-(det[1][2]*det[2][1]))) - (det[0][1]*((det[1][0]*det[2][2])-(det[1][2]*det[2][0]))) + (det[0][2]*((det[1][0]*det[2][1])-(det[1][1]*det[2][0])));
    printf("\n Det of the given matrix is %d",res);
}