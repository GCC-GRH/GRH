#include<iostream>

class vector{
    public:
    int* arr;
    int size = 0;
    int capacity = 1;

    vector(){
        arr = new int[capacity];
    }

    void push(int a){
        if(size == capacity){
            capacity*=2;
            int* temp = new int[capacity];
            for(int i = 0; i < size; i++){
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;

        }
        arr[size] = a;
        size++;

    }

    void pop(){
        if(size > 0){
            size--;
        }
    }

    int getsize(){
        return size;
    }

    int front(){
        return arr[0];
    }

    int back(){
        return arr[(size-1)];
    }

    int getcapacity(){
        return capacity;
    }
    
    int operator[](int index){
        return arr[index];
    }
};

int main(){
    vector v1;
    v1.push(1);
    v1.push(2);
    v1.push(3);
    v1.push(4);
    v1.push(5);
    for(int i = 0; i<v1.getsize();i++){
        std::cout<<v1[i] <<std::endl;
    }

}