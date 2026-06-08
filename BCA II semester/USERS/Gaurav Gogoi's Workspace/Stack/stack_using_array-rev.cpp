#include<iostream>
using namespace std;
class stack{
    int capacity = 1;
    int *arr = new int[capacity];
    int idx = -1;
    public:
void push(int val){
    
    if(capacity == (idx+1) ){
    capacity*=2;
    int* temp = new int[capacity];
    for(int i = 0; i<=idx; i++){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
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

    ~stack(){
        delete[] arr;
    }

};


int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.printstk();

    
}