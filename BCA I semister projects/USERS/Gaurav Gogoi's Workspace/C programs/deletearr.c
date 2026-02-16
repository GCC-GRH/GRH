#include<stdio.h>
void main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int choice_index;
    printf("Please enter an array element index to delete : ");
    scanf("%d",&choice_index);
    for(int i=0;i<10;i++){
        if(arr[i]==choice_index){
            for(int k=i;k<choice_index;k++){
                arr[k]=arr[k+1];
            }
            break;
        }
    }
    for(int i=0;i<9;i++){
        printf("%d\n",arr[i]);
    }

}