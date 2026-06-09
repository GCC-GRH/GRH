#include<iostream>
using namespace std;

class cstack{
    int* arr;
    int idx = -1;
    int s;
    int elm = 0;
    public:
    cstack(int size){
        arr = new int[size];
        s = size;
    }

    void push(int val){
        if(isfull()){
            idx = (idx + 1) % s;
            arr[idx] = val;
            return;
        }
        elm++;
        idx++;
        arr[idx] = val;
    }

    void pop(){
    if(isempty()){
        cout<<"Cannot pop and empty stack"<<endl;
        return;
    }
    elm--;
    idx = (idx - 1 + s) % s;
}

int seek(){
    if(isempty()){
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
    return elm == 0;
}

void track(){
    cout<<elm<< " out of " <<s<<" elements are stored" <<endl;

}

bool isfull(){
    if(isempty()) return false;

    if(elm == s){
        return true;
    }
    return false;
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
    s.track();

    
}