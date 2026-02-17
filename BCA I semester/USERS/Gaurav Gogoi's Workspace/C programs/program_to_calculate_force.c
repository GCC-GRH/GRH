#include<stdio.h>
int main(){
    printf("This program calculates force acting on a body");
    int force, mass, acceleration;
    int option=0;
    printf("\n Please enter mass of the object: ");
    scanf("%d",&mass);
    printf("\n Would you consider the default value for earths gravity? (9.8m/s). Enter 1 for yes or press any key");
    scanf("%d",&option);
    if(option==1){
        force=mass*9.8;
        printf("\n The magnitude of force for mass of %d is %d",mass,force);
    }else{
        printf("\n Please specify your acceleration rate: ");
        scanf("%d",&acceleration);
        printf("\n The magnitude of force for mass of %d is %d",mass,force);
        
    }
    return 0;
}