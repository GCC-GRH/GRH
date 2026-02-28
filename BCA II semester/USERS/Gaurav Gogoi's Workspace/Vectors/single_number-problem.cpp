#include<iostream>
#include<vector>
using namespace std;

class solution{
    int xor_sum;
    public:
    void distinctVector(vector<int>& vec){
        xor_sum=0;
        for(int i : vec){
            xor_sum=xor_sum^i;
        }
        cout<<xor_sum<<endl;
    };

};

int main(){
    solution sol;
    vector <int> vec = {4,1,2,1};
    for(int i : vec){
        cout<<i;
    }
    cout<<endl;
    sol.distinctVector(vec);
    
}