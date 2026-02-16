#include<stdio.h>
void main(){
    int value, option, meter,centimeter, millimeter;
    printf("\n Choose a conversion scale : 1. kilometer to meter \n 2. kilometer to millimeter \n Choose any number to convert into CM scale");
    scanf("%d",&option);
    if(option==1){
    printf("\n Please enter your value in KM");
    scanf("%d",&value);
   
    meter = value*1000;
    printf("\n The value %dKM is %dmeter",value,meter);
}else{
    if(value==2){
        printf("\n Please enter your value : ");
        scanf("%d",&value);
        millimeter=value*1000000;
        printf("\n The value %dKM is %d millimeter ",millimeter);
    }
    
    else{
    printf("\n Please enter your value in KM");
    scanf("%d",&value);
   
    centimeter = value*100000;
    printf("\n The value %dKM is %d Centimeter",centimeter);

    }
    
    
    
   
}
    
}