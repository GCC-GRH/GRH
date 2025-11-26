#include<stdio.h>
#include<string.h>
int main(){
    char op[100];
    int i,length,count=0;
    printf("Enter the character :");
    gets(op);
    length=strlen(op);
    for(i=0;i<length;i++){
        if(op[i]!= op[length-i-1]){
            count=1;
            break;
        }
    }
    if(count==0){
        printf("It is a Palindrome\n");
    }else{
        printf("It is not palindrome\n");
    }
  return 0;
}