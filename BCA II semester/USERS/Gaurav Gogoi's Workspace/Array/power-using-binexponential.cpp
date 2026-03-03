#include<iostream>
using namespace std;
double mypow(double x,int n){
    long binform=n;
    double ans=1;

    while(binform > 0){
        if(binform%2==1){
            ans*=x;
        }
        x*=x;
        binform/=2;
    }
    return ans;
}

int main(){
    double base = 3;
    int power = 5;
    cout<<mypow(base,5);

}