#include<iostream>
using namespace std;
class stack{
    int arr[50];
    int elements = -1;
    public:
    void push(int num){
        elements++;
        arr[elements] = num;
    }

    void pop(){
        if(elements==-1){
            cout<<"Empty stack, cannot pop!"<<endl;
        }
        elements--;
    }

    int seek(){ 
        return arr[elements];
    }

    void display(){
        while(isEmpty() != true){
            cout<<seek()<<endl;
            pop();
        }
    }

    bool isEmpty(){
        return elements == -1;
    }
};

int main(){
    stack s;
    s.push(30);
    s.push(20);
    s.push(10);
    s.push(78);
    s.display();
}
