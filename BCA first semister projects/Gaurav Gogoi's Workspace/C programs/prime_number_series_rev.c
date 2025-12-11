#include<stdio.h>
void main(){
    int n,j,cnt=0;
    printf("\n Please enter the value of N \n==>");
    scanf("%d",&n);
    for(j=1;j<=n;j++,(n%j==0) ? cnt++ : cnt--);
    (cnt--,cnt==2) ? printf("\nIt is prime",j) : printf("\n it is not");
    
    
    
}