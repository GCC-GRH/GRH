#include<stdio.h>
int main(){
    char ch;
    printf("Enter any character:\n");
    scanf("%c",&ch);
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U'){
        printf("The given character is vowel\n",ch);
    }else
    {
        printf("The given character is consonant\n",ch);
    }
  return 0;
}