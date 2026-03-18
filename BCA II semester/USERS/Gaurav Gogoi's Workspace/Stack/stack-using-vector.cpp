#include<iostream>
#include<vector>
using namespace std;
class stack {
    vector <int> v;

    public:
        void push(int val){     // used for pushing elements within the vector array
            v.push_back(val);
        };

        void pop(){     // used for deleting the last element within the vector 
            v.pop_back();
        };
        int top(){
            return v[v.size()-1];
        };

        bool empty(){
            return v.size()==0;
        }

};

int main(){
    stack m;
    m.push(30);
    m.push(20);
    m.push(10);
    while(!m.empty()){
        cout<<m.top()<<" ";
        m.pop();
    };
}