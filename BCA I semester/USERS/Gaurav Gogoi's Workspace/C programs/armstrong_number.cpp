#include<iostream>
using namespace std;
int main(){
    int number;
    cout<<"Please enter a number:"<<endl;
    cin>>number;
    int temp = number;
    int digit_count = 0;
    while(temp!=0)
    {
        digit_count++;
        temp/=10;
    }
    temp = number;
    int r;
    int s=1;
    int sum=0;
    while(temp!=0){
        s=1;
        r=temp%10;
        for(int i = 0; i<digit_count; i++){
            s*=r;
        }
        sum+=s;
        temp/=10;
        
    }
    if(sum == number){
        cout<<"It is a armstrong number";
    }else{
        cout<<"Not a armstrong number";
    }
    }