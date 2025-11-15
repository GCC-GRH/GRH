#include<stdio.h>
struct std{
    char name[50];
    int modelNo;

};
void main(){
    struct std c1={"honda",76};
    printf("%s,%d",c1.name,c1.modelNo);

    
}