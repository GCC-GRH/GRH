#include<stdio.h>
void main(){
    int n,cnt=0;
    printf("\n Please enter the value of N to print n number of prime numbers: \n==>");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=1;j<=i;j++){
            if(i%j==0){
                cnt++;
            }

        }
    if(cnt==2){
        printf("%d\n",i);
    }
    
    }
}