#include<stdio.h>
   struct student 
    {
        char name[20];
        int age;
        int rollno;
    };
void main(){
    int flag=0;
    struct student data_extracted;
    FILE* fp=fopen("structure_data.bin","rb");
    if(fp!=NULL){
        flag=fread(&data_extracted, sizeof(struct student),1,fp);
        if(flag!=0){
            printf("\n Successfully fetched data, reading..");
            printf("\nName:%s\nAge:%d\nRollno:%d\n",data_extracted.name,data_extracted.age,data_extracted.rollno);
        }else{
            printf("\n Error fetching data");
        }
    }else{
        printf("\n Error reading binary file");
    }
}