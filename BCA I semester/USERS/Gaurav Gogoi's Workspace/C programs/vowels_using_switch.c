#include<stdio.h>
void main(){
    char ch;
    printf("\n Please enter your character: ");
    scanf("%c",&ch);
    switch(ch)
    {
        case 'a':
        case 'i': 
        case 'u': 
        case 'e':
        case 'o':
                printf("\n You have entered a vowel character ");
        break;
    
        default:
        printf("\n You have entered a consonant, special characters or likely a digit");
         break;
    }
}