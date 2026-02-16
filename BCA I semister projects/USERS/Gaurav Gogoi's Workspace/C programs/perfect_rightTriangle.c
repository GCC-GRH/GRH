#include<stdio.h>
void main(){
    float a,b,c,x,y,z;
    printf("\n Please enter side 1 of your triangle: ");
    scanf("%f",&a);
    printf("\n Please enter side 2 of your triangle: ");
    scanf("%f",&b);
    printf("\n Please enter side 3 of your triangle: ");
    scanf("%f",&c);
    //By using Pythagoras theorem Z=x+y
    x=a*a;
    y=b*b;
    z=c*c;
    if(z==(x+y)){
        printf("\n It is a perfect right Triangle");
    }else{
        printf("\n It is not a perfect right Triangle");
    }
    if(y==(x+z)){
        printf("\n It is a perfect right Triangle");
    }else{
        printf("\n It is not a perfect right Triangle");
    }
    if(x==(z+y)){
        printf("\n It is a perfect right Triangle");
    }else{
        printf("\n It is not a perfect right Triangle");
    }
}