#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <int> prices = {7,1,5,3,6,4};
    int bestbuy=prices[0];
    int maxp=0;
    int bestsell;
    for(int i=1;i<prices.size();i++){
        if(prices[i]<bestbuy){
            bestbuy=prices[i];
        }else{
            if(maxp < prices[i]-bestbuy){
                maxp=prices[i]-bestbuy;
                bestsell=prices[i];
            }

        }

    }
    cout<<"The best buy is "<<bestbuy<<" and best sell is "<<bestsell<<endl<<"Max profit: "<<maxp;
}

// Linear time-complexity : O(n)