#include<iostream>
using namespace std;

class cstack{
    int* arr;
    int idx = -1;
    int s;
    public:
    cstack(int size){
        arr = new int[size];
        s = size;
    }

    void push(int val){
        if(idx+1 == s){
            idx = 0;
            arr[idx] = val;
            return;
        }

        idx++;
        arr[idx] = val;
    }

    void pop(){
    if(idx == -1){
        cout<<"Cannot pop and empty stack"<<endl;
        return;
    }

    idx--;
}

int seek(){
    if(idx == -1){
        cout<<"Empty stack!"<<endl;
        return -1;
    }
    return arr[idx];
}

void printstk(){
    for(int i = 0; i<=idx; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

bool isempty(){
    return idx == -1;
}

};

int main(){
    cstack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);


    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.printstk();

    
}