#include<stdio.h>
struct student
{
    char name[50];
    int roll;
    int class;
};

void main(){
    int flag=0;
    struct student stud = {"Gaurav",48,10};
    FILE *fp;
    fp=fopen("structure_data.dat","wb");
    if(fp==NULL){
        printf("\n There is an error fetching/creating the file contents");
    }else{
        flag=fwrite(&stud,sizeof(struct student),1,fp);
        if(flag!=0){
            printf("\n The structure file has successfully been created");
        }else{
            printf("\n Error creating structure binary");
        }
    }
    fclose(fp);
    
}