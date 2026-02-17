#include<stdio.h>
void main(){
    int array[10],n,count=0;
    printf("\n Please enter the number of values you want");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\n Array[%d]==> ",i);
        scanf("%d",&array[i]);
        count++;
    }
    printf("+----------------------------------------------------+\n",
           "| Normal order  | Ascending order | Descending Order |\n",
           "+----------------------------------------------------+\n");

}