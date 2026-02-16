#include<stdio.h>
#include<string.h>
struct student{
    int rollno;
    char name[20];
    int age;
};

void main(){
    struct student studs[3];
    strcpy(studs[0].name,"Gaurav");
    studs[0].age=20;
    studs[0].rollno=48;

    strcpy(studs[1].name,"Rehan");
    studs[1].age=19;
    studs[1].rollno=19;

    strcpy(studs[2].name,"Hrishikesh");
    studs[2].age=18;
    studs[2].rollno=18;
    printf("\n Displaying results before sorting by name");
    for(int i=0;i<3;i++){
        printf("\n Name: %s\nAge:%d\nRollno:%d\n",studs[i].name,studs[i].age,studs[i].rollno);

    }

    //sorting using bubbleSort technique

    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            
        }
    }

    
}