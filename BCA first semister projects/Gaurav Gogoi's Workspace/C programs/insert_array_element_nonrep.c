#include<stdio.h>
void main(){
    int numbers[10],element,n,pos;
    printf("Please enter the number of spaces to be reserved in the array : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&numbers[i]);
    printf("\n The numbers stored within the array are : ");
    for(int i=0;i<n;i++)
        printf("%d ",numbers[i]);
}
printf("\n Please enter the element you want to insert within the array : ");
scanf("%d",&element);
printf("\n Please enter the position : ");
scanf("%d",&pos);
for(int i=pos+1;i<n;i++){
    
}
