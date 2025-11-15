#include<stdio.h>
void main(){
    int numbers[10],element,n;
    printf("\n Please enter array size to be reserved ==> ");
    scanf("%d",&n);
    printf("\n Please initialise the element pos : ");
    for(int i=0;i<n;i++){
        printf("Position %d ==> ",i);
        scanf("%d",&numbers);
    }
    printf("\n Array elements before insertion and deletion : ");
    for(int i=0;i<n;i++)
        printf("%d ",i);

        // To delete an element value within an array
        int pos;
        printf("\n Please enter the value you want to search and delete within the array : ");
        scanf("%d",&element);
        for(int i=0;i<n;i++){
            if(element==numbers[i])
                pos=i;
                break;
        }
        if(pos!=0){
            for(int i=pos;i<n;i++)
                numbers[i]=numbers[i+1];
            n--;
        }else{
            printf("\n The element is not found in the array ");
        }
        printf("\n Array after deletation : ");
        for(int i=0;i<n;i++)
            printf("%d ",i);



    }
