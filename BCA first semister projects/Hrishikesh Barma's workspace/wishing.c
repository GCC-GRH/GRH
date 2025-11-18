#include<stdio.h>
void good_morning();
void good_evening();
void good_night();
int main(){
    int a,b,c;
    good_morning();
    good_evening();
    good_night();
    return 0;
}
void good_morning(){
    printf("ohaiyo gusaimasu \n");
}
void good_evening(){
    printf("konbanwa \n");
}
void good_night(){
    printf("oyasumi nasai");
}