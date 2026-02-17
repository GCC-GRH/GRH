#include<stdio.h>
int main() {
    float basic_salary; //This is the basic salary recived by an employee upon his duty within his organisation.
    float da; //Dearness allowance (DA) is an additional payment to employees, calculated as a percentage of their basic salary.
    float hra; // HRA refers to the house rent allowance provided by the organisation of an employeed person for house rental expenses.
    float ta; //Travel allowance refers to the allowance provided by the organisation of an emplopyeed person for travel expenses.
    float gross_salary; // Gross salary refers to the total salary recived by an employeed individual with all the perks and incentives of a his organisation
    char name[20];
    
    printf("Please enter your name : \n");
    scanf("%s",name);

    printf("Please enter your basic salary: \n");
    scanf("%f",&basic_salary);
    printf("\n The information entered is : \n NAME: %s \n SALARY: %f \n Evaluating gross salary :",name, basic_salary);
    da=(basic_salary*5)/100;
    hra=(basic_salary*2)/100;
    ta=(basic_salary*5)/100;
    gross_salary=basic_salary+da+ta+hra;
    printf("\n DA: %0.f \n HRA: %0.f \n TA: %0.f \n Gross Salary is %0.f", da, hra, ta, gross_salary);

    return 0;
    
}