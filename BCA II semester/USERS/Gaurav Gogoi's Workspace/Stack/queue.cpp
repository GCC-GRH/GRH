#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int a){
        data = a;
        next = NULL;
    }
};

class linkedlist{
    node* head;
    node* tail;
    public:
    linkedlist(){
    head = tail = NULL;
    }

    void pushFront(int a){
        node* newNode = new node(a);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next=head;
            head = newNode;
        }

    };

    void popf(){
        node* temp;
        temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

    };

   
    void qprint(){
        node* temp = head;
        cout<<"-> FIFO operation from here > "<<"\t";
        while(temp != NULL){
            cout<<temp->data;
            temp = temp->next;
            cout<<"\t";
        }

    };

    int top(){
        return head->data;
    }



};

class queue{
    linkedlist q;
    public:
    void push(int a){
        q.pushFront(a);
    }
    void pop(){
        q.popf();
    }
    void seek(){
        q.qprint();
    }

    bool isEmpty(){
        return q.top() == NULL;
    }
};


int main(){
    queue a;
    a.push(7);
    a.push(1);
    a.push(8);
    a.push(9);
    a.push(5);
    a.pop();
    a.seek();
}