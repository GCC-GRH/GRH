#include<stdio.h> 
#include<conio.h>
/* The use of getche(); is used for the same purpose as in scanf(), however it uses the method of variable initialization for storing the value entered. This function prevents the user from altering any entered value as the 
entered value is directly executed*/
int main()
{
    char a,b;
    int i=0;
    clrscr();
while(i==0){
    printf("Enter the first character : \n");
    a=getche();
    printf("\n Enter the first character : \n");
    b=getche();
    printf("\n The first character is %c and second is %c", a,b);
   
    printf("\n\n Do you wish to re-execute this program? Enter 0 to restart else 1 to close : ");
    scanf("%d",&i);
    
    
   
}
getch();
return 0;

}