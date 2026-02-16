#include<stdio.h>
void numLoop(int a){
    
    if(a<=100){
        printf("%d\n",a);
        numLoop(a+1);
    }
};


void main(){
    int i=0;
    numLoop(i);
}