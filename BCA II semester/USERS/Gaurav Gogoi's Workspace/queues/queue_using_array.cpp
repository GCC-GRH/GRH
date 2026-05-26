#include<iostream>
using namespace std;
class queue{
    int arr[50];
    int elements = -1;
    public:
    void push(int num){
        elements++;
        arr[elements] = num;
    }

    void pop(){
        if(elements==-1){
            cout<<"Empty queue, cannot pop!"<<endl;
        }
        for(int i = 0; i<=elements; i++){
            arr[i] = arr[i+1];
        }
        elements--;
    }

    int seek(){ 
        return arr[elements];
    }

    void display(){
        for(int i = 0;i <= elements; i++){
            cout<<arr[i]<<"\t";
        }
    }

    bool isEmpty(){
        return elements == -1;
    }
};

int main(){
    queue s;
    s.push(30);
    s.push(20);
    s.push(10);
    s.push(78);
    s.pop();
    s.display();
}