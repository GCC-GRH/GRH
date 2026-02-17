#include <stdio.h>
void main(){
    printf("This program detects the Ruppes and paisa value of a given Ruppes value \n");
    int rup;
    int paisa;
    float value;
    printf("Please enter your ruppes value: \n");
    scanf("%f",&value);
    rup=value;
    paisa=(value-rup)*100;
    printf("The values for rupee is %d and paisa is %d", rup, paisa);


}