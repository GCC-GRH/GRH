#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector <char> vec={'G','A','U','R','A','V'};
    // For-each loop is a vector and array specific loop which is used for traversing data items within a vector data struture.
    for(char i: vec){ //In for-each loop, the iterator I iterates through vector data items. 
        cout<<i;
        cout<<" " <<endl;
    }
}