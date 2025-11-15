#include<stdio.h>
void main(){
    int n,i,cnt=0;
    printf("Please enter the value of N to print N prime numbers: ");
    scanf("%d",&n);
    for(int k=1;k<=n;k++){
        cnt=0;
    for(i=1;i<=k;i++){
    if(k%i==0){
        cnt++;
        
    }
    }
    if(cnt==2){
        printf("\n%d",k);
    }
   }
}

    
