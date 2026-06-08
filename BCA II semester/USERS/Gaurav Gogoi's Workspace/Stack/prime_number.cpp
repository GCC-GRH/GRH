#include<iostream>
using namespace std;
int main(){
    int num;
    int count = 0;
    cout<<"Please enter a number to determine its a prime or not:"<<endl;
    cin>>num;
    for(int i=1;i<=num;i++){
        if(num%i==0){
            count++;
        }
    }
    if(count==2){
        cout<<"It is a prime number!";
    }else{
        cout<<"It is not a prime number!";
    }
}