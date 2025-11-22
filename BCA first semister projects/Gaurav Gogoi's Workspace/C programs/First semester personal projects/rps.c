#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void play();
void main(){
    
    system("cls");
    int choice,exit_flag=0,incrt=0;
    while(exit_flag!=1){
        srand(time(NULL));
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
    
    int comp,player;
    comp=player=0;
    int pick_opt,pick_comp;
    int incrt=0;
    system("cls");
    printf("Choose : \n----------------------\n 0. Rock \n 1. Paper \n 2. Scissior\n Use num-keys to select your choice: ");
    scanf("%d",&pick_opt);
    pick_comp=rand()%2;
    if(pick_opt==pick_comp){
        printf("\n The game is a draw\n");

    }else{
        if(pick_opt == 0 && pick_comp != 1){
            player++;
            printf("\n Player has picked a rock and your dummy computer tried to cut it with a scissor...Pathetic :/");
        }else if(pick_opt==0 && pick_comp==1){
            comp++;
            printf("\n Player has picked a rock but computer saved himself with a paper, what a nasty move!");
        }
        if(pick_opt==1 && pick_comp==0){
            player++;
            printf("\n Player has picked paper to save himself from the rock his computer threw.. ");
        }else if(pick_opt==1 && pick_comp==2){
            comp++;
            printf("\n Player has picked a paper but computer outsmarted his move with a scissor, daymn!");
        }
        if(pick_opt==2 && pick_comp==0){
            comp++;
            printf("\n Player tried to use a scissor against the rock his computer threw...Ai take over is real when ur this of a brain dead ;) ");
        }else if(pick_opt==2 && pick_comp==1){
            player++;
            printf("\n Player made a smart move by tearing the computer's paper move with his sharp scissors, nice baby");
        }
        (comp>player) ? printf("\nComputer won the game\n") : printf("\nPlayer has won the game\n");
        
        
    }
    system("pause");

}
