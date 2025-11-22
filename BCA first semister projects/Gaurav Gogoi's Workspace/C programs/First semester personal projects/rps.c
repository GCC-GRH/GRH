#include<stdio.h>
#include<stdlib.h>
void play();
void main(){
    system("cls");
    int choice,exit_flag=0,incrt=0;
    while(exit_flag!=1){
        if(incrt>0){
            system("cls");
            printf("\n Incorrect selection \n");
            
        }else{
            system("cls");
        }

   printf("+-------------------------------+"
           "\n|     Rock Paper Scissor        |"
           "\n+-------------------------------+"
           "\n| 1. Play Game (Bot)            |"
           "\n| 2. Exit                       |"
           "\n+-------------------------------+");
printf("\n Please enter your selection using Number keys:\n==> ");
scanf("%d",&choice);
switch(choice){
    case 1 :
        play();
    break;
    case 2 : exit_flag++;
    break;
    default: 
            incrt++;
    break;
}
}
}

void play(){
    
}
