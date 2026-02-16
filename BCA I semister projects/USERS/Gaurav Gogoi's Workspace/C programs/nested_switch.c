#include<stdio.h>
void main(){
    int a,b,c;
    printf("\n Please choose a selection: \n 1. Pens \n 2. Biscuits \n");
    scanf("%d",&a);
    switch(a){
        case 1: printf("\n Please choose your pen : \n 1. Reynolds. \n 2. Golden matrix. \n 3. Octane \n");
        scanf("%d",&b);
        switch(b){
            case 1 : printf("\n You selected Reynolds pen");
            break;  
            case 2 : printf("\n You selected Golden matrix pen");
            break;
            case 3 : printf("\n You selected Octane pen");
            break;
            default : printf("\n Invalid Selection");
            break;
        }
        break;
        case 2 : printf("\n Please choose your biscuit: \n 1. Marie Gold. \n 2. Tiger biscuit. \n 3.Ruskit.\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1 : printf("\n You selected Marie gold.");
        break;
        case 2 : printf("\n You selected Tiger biscuit.");
        break;
        case 3 : printf("\n You selected Ruskit.");
        break;
        
        default: printf("\n Invalid Selection");
        break;
        }
        break;
    }
}