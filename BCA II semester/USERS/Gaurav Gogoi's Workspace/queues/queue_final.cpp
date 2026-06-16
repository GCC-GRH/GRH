#include<iostream>
using namespace std;
class queue{
    int size;
    int *arr;
    int elements;
    int front;
    public:
    queue(int val){
        arr = new int[val];
        elements = -1;
        front = -1;
        size = val;
    }

    void push(int val){
        if(front == -1){
            front = 0;
        }
        if(isfull()){
            cout<<"Queue overflow, cannot push!"<<endl;
            return;
        }
        elements++;
        arr[elements] = val;
    }


    bool isfull(){
        return (elements+1) == size;
    }
};


int main(){
    queue q(50);
    q.push(65);
}