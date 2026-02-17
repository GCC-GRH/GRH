#include<stdio.h>
void main(){
    FILE* fp=fopen("username.txt","w");
    (fp==NULL) ? printf("Invalid access to the file") : printf("File successfully created"); // ? : are ternary conditional operators used for simplified if else conditions undersingle line.
}