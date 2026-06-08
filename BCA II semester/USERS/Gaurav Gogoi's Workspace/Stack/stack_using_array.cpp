#include<iostream>
using namespace std;
class stack{
    int arr[50];
<<<<<<< Updated upstream
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
=======
    int elements;
    public:
        stack(){
            elements = -1;
        }
    void pushback(int val){
        if(elements < 49){
        arr[elements+1] = val;
        elements++;
    }
    };

    void popback(){
        if(elements >= 0){
            elements--;
        }

    }

    int fetchtop(){
        if (elements>=0)
        {
            return arr[elements];
        }
        return -1;
    }

    bool isempty(){
       return elements==-1;
    }

    void prints(){
        for(int i = elements; i>=0;i--){
            cout<<arr[i]<<endl;
        }
    }
};


int main(){
    stack a;
    a.pushback(8);
    a.pushback(10);
    a.pushback(75);
    cout<<"The stack elements are : "<<endl;
    a.prints();
    cout<<endl;
    if(a.isempty() == true){
        cout<<"Empty stack"<<endl;
    }else{
         cout<<"The top element is "<<a.fetchtop()<<endl;
    }
}
>>>>>>> Stashed changes
