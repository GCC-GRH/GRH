#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Please enter the year :"<<endl;
    cin>>num;
    if(num%400==0 || num%100!=0 && num%4==0){
        cout<<"It is a leap year!";
    }else{
        cout<<"Not a leap year!";
    }
}