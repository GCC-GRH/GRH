#include<iostream>
using namespace std;

class queue{
    int *arr;
    int idx = -1;
    int capacity = 1;
    int front = 0;
    public:
    queue(){
        arr = new int[capacity];
    }

    void push(int val){
        if(isfull()){
            capacity*=2;
            int *temp = new int[capacity];
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
        if(isempty()){
            cout<<"Cannot pop an empty queue"<<endl;
            return;
        }
        front++;
    }

    int seek(){
        if(isempty()){
            cout<<"Empty queue!"<<endl;
            return -1;
        }
        return arr[front];
    }

    bool isfull(){
        if(idx+1 == capacity) return true;
        return false;
    }

    bool isempty(){
        if(idx + 1 == front) return true;
        return false;
    }

    void display(){
        if(isempty()){
            cout<<"Empty queue!"<<endl;
            return;
        }
        for(int i = front; i<=idx; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    ~queue(){
        delete[] arr;
    }
};


int main(){
    queue q1;
    q1.push(5);
    q1.push(2);
    q1.push(3);
    q1.push(1);
    q1.push(4);
    q1.display();
}