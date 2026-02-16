#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int roman(char x);
void main(){
    char roman_val[100];
    int total_indices;
    int val1,val2;
    int result=0;
    system("cls");
    printf("\n Please enter your value in ROMAN\n==>");
    scanf("%S",&roman_val);
    total_indices=strlen(roman_val)-1;

    for (int i=0;i<=total_indices;i++){
        val1=roman(toupper(roman_val[i]));
        if((i+1)<=total_indices){
            val2=roman(toupper(roman_val[i+1]));
            
            if(val1>val2){
                result+=val1+val2;
            }else{
                    if(val1<val2){
                    result+=val2-val1;
                    }else{
                                    result+=val1;

                    }
                }
            }else{
            result+=val1;
        
        }

    }

    printf("\n Result is %d",result);
}
int roman(char x){
    switch (x)
    {
    case 'I': return 1; 
    break;
    case 'V': return 5; 
    break;
    case 'X': return 10; 
    break;
    case 'L': return 50; 
    break;
    case 'C': return 100; 
    break;
    case 'D': return 500; 
    break;
    case 'M': return 1000; 
    break;
    
    default: return 0;
    break;
    }
}