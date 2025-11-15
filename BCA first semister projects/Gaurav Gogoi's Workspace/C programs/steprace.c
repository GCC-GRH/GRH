#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void singlePlayer();
void multiPlayer();
void settings();
void player(int steps,int player);
char gameplay(char *diff, char *obs, int players, int step, int random_num,int hit,int maxp);
int random();
void main(){
    srand(time(NULL)); // Seed the random number generator ONCE
    //State variables and options
    int option_state=0,selection,inval=9;
    

    // Mainloop of the Game
    while(option_state==0){
    system("cls"); 
    printf("\n               Steprace                  " // Game intro screen
        "\n+------------------------------------------+"
        "\n|           1. Single Player               |"
        "\n|           2. MultiPlayer                 |"
        "\n|           3. Settings                    |"
        "\n|           4. Quit Game                   |"
        "\n+------------------------------------------+\n"
    );
    (inval==0) ? printf("Invalid option Selected\n\n") : printf("Choose a selection using Numpad keys :\n"); 
    printf("==> ");
    scanf("%d",&selection);
    switch (selection)
    {
    case 1 :
        singlePlayer();
        break;
    case 2 :
        multiPlayer();
        break;
    case 3 :
        settings();
        break;
    
    case 4 :
        option_state=1;
        break;
    
    default:
        printf("\n Invalid selection");
        inval=0;
        break;
    }
    
}
    
    
    
}


// Definition of game functions
// SinglePlayer logic
void singlePlayer(){
    system("cls");
    char *diff="False",*obs="False";
    int sel;
    int step=0;
    char roll;
    int random_value;
    int random_obstacle;
    time_t time_start;
    time_t time_end;
    double best_time=0;
    int hit;
    refresh:
    printf("\n       Steprace - SinglePlayer            " // single Player logic
        "\n+------------------------------------------+"
        "\n|  1. Difficulity                    %s |"
        "\n|  2. Enable obstacles               %s |"
        "\n|  3. Return to main screen                |"
        "\n+------------------------------------------+"
        "\n|       Select 4 to Start the game         |"
        "\n+------------------------------------------+\n",
        diff,obs
    );
    scanf("%d",&sel);
    switch (sel)
    {
    case 1 :
        if(diff=="False")
            diff="True ";
        else 
            diff="False";
        system("cls");
        goto refresh;
        break;
    case 2 : 
        if(obs=="False")
            obs="True ";
        else
            obs="False";
        system("cls");
        goto refresh;
        break;
    case 4 : // Start game logic
            time_start=time(NULL);
            while (step<50)
            {   
              
                if (step==0)
                    system("cls");
                printf("\n Press 0 to Roll dice \n ==> ");
                scanf(" %c",&roll);

                // Die manipulation logic
                if(roll=='0'){
                    random_value=random();
                    
                    if(obs=="True "){               // Obstacle logic when enabled
                        random_obstacle=random();

                        if(random_value==random_obstacle){
                            step-=random_value;
                            hit=1;
                        }else{
                            step+=random_value;
                            hit=0;
                            
                        }
                    }else{
                        step+=random_value;
                    }
                
                    gameplay(diff,obs,1,step,random_value,hit,1);
                }else{
                    system("cls");
                    printf("\n Invalid input");
                }
                
            }
                //Single player win logic
                time_end=time(NULL);
                double elapsed=difftime(time_end,time_start);
                //read last game win time
                FILE *fp=fopen("steprace_time.txt","r");
                fscanf(fp,"%lf",&best_time);
                
                if((best_time==0) || (best_time>elapsed)){
                    fclose(fp);
                printf("\n Player has won the game in %.0f seconds.\n===========================================",elapsed);
                
                
                //Save the elapsed time of the winning game
                    FILE *fp=fopen("steprace_time.txt","w");
                    if(fp!=NULL){
                        fprintf(fp,"%.0f\n",elapsed);
                        fclose(fp);
                    }else{
                        printf("\n Error saving new score");
                    }
                }else{
                    system("cls");
                    printf("Player has lose the game.\n"
                           "========================"
                        "\nLast record : %.0fs\nCurrent score : %.0fs\nEnter any number to continue:\n==>",best_time,elapsed);
                }
                printf("\n");
                system("pause");
            
            break;
            
    
    default:
        break;
    }
}

// Multiplayer Logic
void multiPlayer(){
    system("cls");
    char *diff="False",*obs="False";
    char sel;
    int players=2;
    int step1=0;
    int step2=0;
    char roll;
    int random_value;
    int random_obstacle;
    int hit;
    int i;
    refresh_multiplayer_screen:
    printf("\n       Steprace - MultiPlayer            " // Game intro screen
        "\n+------------------------------------------+"
        "\n|  1. Difficulity                    %s |"
        "\n|  2. Enable obstacles               %s |"
        "\n|  3. Players                        - %d + |"
        "\n|  4. Return to main screen                |"
        "\n|  5. Start Game                           |"
        "\n+------------------------------------------+"
        "\n|  Use - + to increase or decrease player  |"
        "\n+------------------------------------------+\n",
        diff,obs,players
    );
    scanf(" %c",&sel);
    switch (sel)
    {
    case '1' :
        if(diff=="False")
            diff="True ";
        else 
            diff="False";
        system("cls");
        goto refresh_multiplayer_screen;
        break;
    case '2' : 
        if(obs=="False")
            obs="True ";
        else
            obs="False";
            system("cls");
        goto refresh_multiplayer_screen;
        break;
    case '+' :
            system("cls");
        if(players<3)
            players++;
        else
            printf("\n     Maximum Player limit reached");
        goto refresh_multiplayer_screen;
        break;
    case '-' : 
            system("cls");
        if(players>2)
            players--;
        else
            printf("\n     Minimum 2 Players for multiplayer");
        goto refresh_multiplayer_screen;
        break;
        case '4' : break;
        case '5' : 
                while (step1<50 || step2<50)
                {   
                for(i=1;i<=players;i++){
                if(step1 == 0 && step2== 0)
                    system("cls");
                printf("\nPlayer %d, Press 0 to Roll dice \n ==> ",i);
                scanf(" %c",&roll);

                // Die manipulation logic
                if(roll=='0'){
                    random_value=random();
                    
                    if(obs=="True "){               // Obstacle logic when enabled
                        random_obstacle=random();

                        if(random_value==random_obstacle){
                           if(i==1)
                            step1-=random_value; 
                        else 
                            step2-=random_value;
                            hit=1;
                        }else{
                            if(i==2)
                                step1+=random_value; 
                            else 
                                step2+=random_value;
                            hit=0;
                            
                        }
                    }else{
                        if(i==1)
                            step1+=random_value; 
                        else 
                            step2+=random_value;
                    }
                    if(i==1)
                        gameplay(diff,obs,i,step1,random_value,hit,players);
                    else
                        gameplay(diff,obs,i,step2,random_value,hit,players);
                    
                }
            }
        }  
        break;
    
    default:
        multiPlayer();
        break;
    }  
} 
void settings(){
    char sel;
    char exit_state='0';
    while(exit_state!='1'){
    FILE *fp=fopen("steprace_time.txt","r");
    double score;
    system("cls");
    if(fp!=NULL){
        fscanf(fp,"%lf",&score);
    }else{
        printf("\n No previous records available \n");
    }
    
    fclose(fp);
    

      printf("+------------------------------------------+"
           "\n|  1. Last Score                           |"
           "\n|  2. Delete last score                    |"
           "\n|  3. Back to Main menu                    |"
           "\n+------------------------------------------+\n Select options\n==> "
    );
    sel=getchar();
    scanf("%c",&sel);
    if(sel=='1'){
        (score>0) ? printf("\n Your last highest score is %.0fs \n",score) : printf("\n No score available to fetch \n");
        system("pause");


    }else if(sel=='2'){
        fp=fopen("steprace_time.txt","w");
        if(fp!=NULL)
            fclose(fp); //deleted
            printf("\n Score deleted successfully! \n");
            system("pause");

        

    }else if(sel=='3'){
        exit_state='1';
    }
}
    
}



int random(){
    return (rand() % 6) + 1;
}


void player(int steps,int player){
    char a='-';
    int n=steps;
    for(int i=1;i<=n;i++){
        printf("%c",a);
    }
    printf("Player|>");
}


char gameplay(char *diff, char *obs,int players, int step, int random_num, int hit, int maxp){
    char *diff_state=diff;
    char *obs_state=obs;
    int player_num=players;
    int steps=step;
    int steps2=step;
    int hit_obs=hit;
    int i;
    system("cls");
    

    
    printf("Player %d has got %d when rolled, moving steps\n",player_num,random_num);
    printf("Track:\n"
        "+---------------------------+\n");
   (player_num==1) ? printf("| Player %d Step taken: %d/50 |\n",player_num,steps) : printf("| Player %d Step taken: %d/50 |\n",player_num,steps2);
    printf("+---------------------------+\n"
        "| Difficulity : %s       |\n"
        "| Obstacle : %s          |\n"
        "| Players : %d               |\n"
        "+--------------------------+\n"
       ,diff_state,obs_state,player_num);
    for(i=1;i<=maxp;i++){
    printf("\n+--------------------------------------------------------F>\n");
    if(i==1)
        player(steps,i);
    else
        player(steps2,i);
    printf("\n+--------------------------------------------------------F>\n");
    }
    if(hit==1)
        printf("\n\nYou got hit with an obstacle and decided to move back!\n");
    

}
