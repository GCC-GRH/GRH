#include<stdio.h>
#include<math.h>
void main(){
int i,j,value,temp,type,result[32], conversion_type;
int binaryNumber[32];
printf("\n Choose your value type : \n 1. Binary Numbers \n 2. Decimal Numbers \n 3. Octal Numbers \n 4. Hexadecimal Numbers \n Use the number keys to choose a valid Number System ==>" );
scanf("%d",&type);
switch(type){
    case 1 : printf ("\n Please enter your Binary Value : ");
             scanf("%d",&value);
             
    break;       
    
    
    case 2 : printf ("\n Please enter your Decimal Value : ");
             scanf("%d",&value);
             
             
    break;          
    
    case 3 : printf ("\n Please enter your Octal Value : ");
             scanf("%d",&value);
             
             
    break;  
    
   
    case 4 : printf ("\n Please enter your hexadecimal Value : ");
             scanf("%d",&value);
             
             
    break;      
    }
    printf(" \n Convert to which value type ==> \n 1. Binary Numbers \n 2. Decimal Numbers \n 3. Octal Numbers \n 4. Hexadecimal Numbers \n Use the number keys to choose a valid Number System ==>");
             scanf("%d",&conversion_type);
             temp=value;
             while(conversion_type==type){
             printf("\n Cannot convert to the same type. Choose a Different system for conversion : ");
             scanf("%d",&conversion_type);
             temp=value;
             }
    switch(conversion_type){
    case 1 : 
            i=0;
            while(temp>0){
                binaryNumber[i]=temp%2;
                temp/=2;
                i++;
            }
           
             printf("\n The value in Binary is : ");
             for(j=i-1;j>=0;j--){
                printf("%d",binaryNumber[j]);
             }
    
    
    break;
    
    case 2 : 
    
    
    
    break;   
    
    case 3 : 
    break;
    
    case 4 :
    break;
    }
    }