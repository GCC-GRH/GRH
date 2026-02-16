#include<stdio.h>
struct student{
    char name[50];
    int roll_number;
    int age;
    double total_marks;
};
void main(){
    int n,i;
    printf("\n Please enter the number of students : ");
    scanf("%d",&n);
    struct student stud[n];
    for(i=0;i<n;i++){ // 
        printf("\nPlease enter roll number for student %d  ",i+1);
        scanf("%d",&stud[i].roll_number);
        printf("\nPlease enter name for student %d  ",i+1);
        scanf("%s",&stud[i].name);
        printf("\nPlease enter age for student %d  ",i+1);
        scanf("%d",&stud[i].age);
        printf("\nPlease enter total marks for student %d  ",i+1);
        scanf("%lf",&stud[i].total_marks);
}
// fetching student data from the structure members.

for(i=0;i<n;i++){
printf("\nThe roll.no for student %d is %d",i+1,stud[i].roll_number);
printf("\nThe name for student %d is %s",i+1,stud[i].name);
printf("\nThe Age for student %d is %d",i+1,stud[i].age);
printf("\nThe Total mark for student %d is %lf\n\n\n",i+1,stud[i].total_marks);
}




}