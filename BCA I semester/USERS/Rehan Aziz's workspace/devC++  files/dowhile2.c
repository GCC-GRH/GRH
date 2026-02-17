#include<stdio.h>
void main(){
	int num, index=0;
	printf("\n ENTER A NUMBER: ");
	scanf("%d", &num);
	do{
		printf("\n %d",index+1);
		index=index+1;
	}while(index<num);
	getch();
}
