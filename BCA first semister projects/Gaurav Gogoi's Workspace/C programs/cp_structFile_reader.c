#include<stdio.h>
struct read_stud
{
    char name[50];
    int roll;
    int class;
};
void main(){
    struct read_stud stud1;
    int flag=0; // Flags for error handling
    FILE *fp;
    fp=fopen("structure_data.dat","rb");
    if(fp==NULL){
        printf("\n Error fetching file contents");
    }else{
        flag=fread(&stud1,sizeof(stud1),1,fp);
        if(flag!=0){
            printf("\n\nNAME : %s\nRoll: %d\nClass: %d\n\n",stud1.name,stud1.roll,stud1.class);
        }else{
            printf("\n Error fetching structure data into the targetted structure variable.");
        }
    }
    
}