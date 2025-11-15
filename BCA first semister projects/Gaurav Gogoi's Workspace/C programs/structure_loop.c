#include<stdio.h>
struct student{
    int rollNo;
    char name[20];
};
void main(){
    struct student s[10];
    int n;
    printf("\n How many students?\n==>");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nStudent #%d: Name and Rollno \n==>",i);
        scanf("%s %d",&s[i].name,&s[i].rollNo);
    }
    for(int i=0;i<n;i++){
        printf("Student#%d\nName: %s Rollno: %d\n\n",i,s[i].name,s[i].rollNo);
    }
}