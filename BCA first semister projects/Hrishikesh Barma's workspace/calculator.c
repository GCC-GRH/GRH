#include<stdio.h>
int main(){
    int x,y;
    char op;
   printf("Enter the operator'+,-,*,/':\n");
   scanf("%c",&op);
   printf("Enter any number :\n");
   scanf("%d %d",&x,&y);
   switch(op){
    case '+':printf("%d",x+y);
    break;
    case '-':printf("%d",x-y);
    break;
    case '*':printf("%d",x*y);
    break;
    case '/':if(y!=0){
        printf("result=%d",x/y);
    }else{
        printf("Error!division by zero");
    }
    break;
    default:printf("Invalid operator applied");
   }
   return 0;
}