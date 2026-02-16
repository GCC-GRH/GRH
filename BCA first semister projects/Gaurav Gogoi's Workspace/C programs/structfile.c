#include<stdio.h>
void main(){
    int flag=0;
    struct student 
    {
        char name[20];
        int age;
        int rollno;
    } stud = {
        "Gaurav",
        20,
        48
    };
    FILE* fp=fopen("structure_data.bin","wb");
    if(fp!=NULL){
        flag=fwrite(&stud,sizeof(struct student),1,fp);
        if(flag!=0){
            printf("\n Successfully written");
        }else{
            printf("\n Error writing structure to the document");
        }

    }else{
        printf("\n Error opening or creating binary file");
    }
}