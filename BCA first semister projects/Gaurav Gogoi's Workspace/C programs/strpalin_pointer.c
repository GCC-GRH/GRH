#include<stdio.h>
void ispalin(char *string){
    int count=0;
    int i,j,flag=0;
    while(string[count]!='\0'){
        count++;
    }
for(i=0,j=count-1;i<count;i++,j--){
    if(string[i]!=string[j]){
        flag=1;
    }

}
(flag!=1) ? printf("\nIt is a palindrome") : printf("\n It is not a palindrome");
}
void main(){
    char str[20];
    printf("\n Please enter your string value: ");
    gets(str);
    ispalin(str);
}