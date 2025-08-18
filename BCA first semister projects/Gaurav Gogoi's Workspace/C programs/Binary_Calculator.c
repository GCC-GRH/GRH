#include<stdio.h>
#include<stdlib.h>
int bin(int value,int base);
int dec(int value,int base);
int oct(int value,int base);
int hex(int value,int base);
void main(){
    int value,option,val_base,result,exit_state=0;
    char hexa[100];
    re_execute:
    system("cls");
    printf("\n+-----------------------------------------+\n"
            "|  Binlator - v1.0.0                      |\n"
            "|  Developer: Gaurav Gogoi, BCA sec: A    |\n"
            "|  Warning: Hexadecimal Input needs a fix |\n"
            "+-----------------------------------------+\n");
    reprompt:
    printf("\n Choose a system for the given value: \n 1. Binary \n 2. Decimal \n 3. Octal \n 4. Hexadecimal \n 5. Exit program \n==>  ");
    scanf(" %d",&val_base);
  
    
    
    switch(val_base){
        case 1 : val_base=2;
        break;
        case 2 : val_base=10;
        break;
        case 3 : val_base=8;
        break;
        case 4 : val_base=16;
        break;
        case 5 : goto exit_program;
        break;
        default :   printf("\n Incorrect System, Restarting the prompt!");

                    goto reprompt;
        break;
    }
    system("cls");
    printf("\n Enter your value ==>  ");
    if(val_base!=16){
        scanf(" %d",&value);
    }else{

        scanf(" %X",&value);
    }
    
   
    
    
    system("cls");
    target_system:
    printf("\n Please select a target number system for conversion ==> \n 0. To know about Developer. \n 1. Binary \n 2. Decimal \n 3. Octal \n 4. Hexadecimal \n==>  ");
    scanf(" %d",&option);
    switch(option){
        case 0 : printf("Developer name: Gaurav Gogoi");
        break;
        case 1 : result=bin(value, val_base);
                 printf("\n The output is %d \n",result);
        break;
        case 2 : result=dec(value, val_base);
                 printf("\n The output is %d \n",result);
        break;
        case 3 : result=oct(value, val_base);
                 printf("\n The output is %d \n",result);
        break;
        case 4 : result=hex(value, val_base);
        break;
        default : printf("\n Invalid option! Restarting the prompt..");
                  goto target_system;
        break;

    }

    printf("Want to exit or restart the program? \n Choose 1 to exit else continue : ");
    scanf("%d",&exit_state);
    if(exit_state!=1){ 
        exit_state=1;
        goto re_execute; 
    }else{
        exit_program: 
        system("cls");
        printf("\n+---------------------------------+ \n"
                  "|  Program quitted successfully!  |\n"
                  "+---------------------------------+\n");
    }


}

// Binary Function defintions
int bin(int value, int base) {
    int result=0,bin_val=0;
    int num,remainder,position=1;
    if(base==10){
        
   num=value;
    while(num!=0){
        remainder=num%2;
        bin_val+=remainder*position;
        position*=10;
        num/=2;

    }
    result=bin_val;
    }
    if(base==2){
        printf("\n Binary function : Couldn't convert a base-2 system to itself \n");
    }
    if(base==8){
        int decimal_val;
        decimal_val=dec(value,base);
        result=bin(decimal_val,10);

    }
    if(base==16){
        int decimal_val=dec(value,base);
        result=bin(decimal_val,10);
    }
    return result;
}

// Decimal function definitions
int dec(int value, int base) {
    int r,val,res=0,bas=1,decimal_val=0;
    if(base!=10 && base!=16){
    val=value;
    while(val!=0){
        r=val%10;
        res+=r*bas;
        bas*=base;
        val/=10;
    }
    }else{
        
        if(base==16){
            sprintf(res,"%d",value);
    }else{
        printf("\n Decimal function : Couldn't convert a base-10 system to itself \n");
    }
        
    }   
    return res;
}

//Octal function definitions
int oct(int value, int base) {
    int i=0,res[100],return_octal=0;
    int bas=1;
    int temp=value;
    int decimal_val=0,r=0;
    int decimalBuffer[50];
    if(base==10){
    
    while(temp!=0){
        res[i]=temp%8;
        temp/=8;
        i++;
        
    }
    i--;
    while(i>=0){
            return_octal=(return_octal*bas)+res[i];
            bas=10;
            i--;
        }
    }
    if(base==2){
        while(temp!=0){
        r=temp%10;
        decimal_val+=r*bas;
        bas*=base;
        temp/=10;
    }
    temp=decimal_val;
    return_octal=oct(temp,10);
    }
    if(base==8){
        printf("\n Octal function : Couldn't convert a base-8 system to itself \n");
        
    }
    if(base==16){
        temp=value;
        sprintf(decimalBuffer,"%d",temp);
        return_octal=oct(decimalBuffer,10);
    }
    return return_octal;
}

// Hexadecimal function definitions
int hex(int value, int base){
    int temp,r,bas,decimal_val=0,ret;
    if(base==10){
        printf("\n Hexadecimal function : The output is %X \n",value);
    }
    if((base==2) || (base==8)){

        temp=value;
        bas=1;
        while(temp!=0){
        r=temp%10;
        decimal_val+=r*bas;
        bas*=base;
        temp/=10;
    }
    ret=hex(decimal_val,10);

}
    if(base==16){
        printf("Hexadecimal function : Couldn't convert a base-16 system to itself");
    }
   
    return 0;
}