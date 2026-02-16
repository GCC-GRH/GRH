#include<stdio.h>
void main(){
    int array[50]={1,2,3,4,5,6,7,8,9,10,0,0,1,2,3,4,5,22,33,1};
    int even_count=0,odd_count=0,zero_count=0;
    for(int i=0;i<20;i++){
        if(array[i]%2==0){
            even_count++;
        }
        if(array[i]%2!=0){
            odd_count++;
        }
        if(array[i]==0){
            zero_count++;
        }
    }
    printf("Element counts ==>\n Even elements : %d \n Odd elements : %d \n Zero element : %d",even_count,odd_count,zero_count);
    
}