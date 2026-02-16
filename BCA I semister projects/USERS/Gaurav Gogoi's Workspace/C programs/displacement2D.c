#include<stdio.h>
#include<math.h>
void main(){
    float x1,x2,y1,y2,result;
    printf("Please enter the inital and final point of X AND Y coordinate respectively :\n==>");
    scanf("%f %f",&x1,&y1);
    printf("Please enter the inital and final point of X2 and Y2 coordinate respectively :\n==>");
    scanf("%f %f",&x2,&y2);
    result=sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    printf("The result is %f",result);
}