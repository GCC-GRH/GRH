#include<stdio.h>
#define ganit main
#define batao printf
#define behja_mei_ghusao scanf
#define number int
#define andhera void


andhera ganit(){
number a,b;
number result;
batao("\n Appka number bataye : ");
behja_mei_ghusao("%d",&a);
batao("\n Appka dusra number bataye : ");
behja_mei_ghusao("%d",&b);
result = (a+=1,b+=1,a+b);
batao("\n Fhal : %d",result);

}