#include<stdio.h>
void main(){
    int strlength=0;
    char val[100];
    char replace_val;
    char to_replace;
    int temp;
    printf("Please enter a string : \n==> ");
    gets(val);
    while(val[strlength]!='\0') strlength++;
    printf("\n Length : %d",strlength);
    printf("\nEnter a character to replace\n");
    scanf(" %c",&replace_val);
    printf("\nTarget character\n");
    scanf(" %c",&to_replace);
    temp=strlength;
    for(int i=0;i<strlength;i++)
    {
        if(val[i]==to_replace){
            val[i]=replace_val;
        }
        
    }
    puts(val);
    
    
}