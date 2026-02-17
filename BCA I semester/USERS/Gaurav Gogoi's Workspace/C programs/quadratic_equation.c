#include<stdio.h>
#include<math.h>
void main(){
    int a,b,c,res,dis;            //ax2 + bx + c = 0 Taking the coeficients
    printf("Please enter value of coefficient a from your quadratic equation\n==>");
    scanf("%d",&a);
    printf("Please enter value of coefficient b from your quadratic equation\n==>");
    scanf("%d",&b);
    printf("Please enter value of constant c from your quadratic equation\n==>");
    scanf("%d",&c);
    dis=b*b - 4*a*c; // d = b*b - 4ac formula
    if(dis>0){
        res=(-b+sqrt(dis))/2*a; 
        printf("The positive root x is %d\n",res);
        res=(-b-sqrt(dis))/2*a;
        printf("The negative root x is %d\n",res);
    }

    
    
    }