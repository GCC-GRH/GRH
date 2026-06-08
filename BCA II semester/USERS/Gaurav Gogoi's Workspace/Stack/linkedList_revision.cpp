#include<iostream>
using namespace std;
class node{
    public:

    int data;
    node* ptr;

    node(int a){
        data = a;
        ptr = NULL;

    };

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
            newNode->ptr=head;
            head = newNode;
        }

    };

    void pushEnd(int a){
        node* newNode = new node(a);
        if(tail == NULL){
            tail = newNode;
        }else{
            tail->ptr = newNode;
            tail = newNode;
        }

    };

    void popf(){
        node* temp;
        temp = head;
        head = head->ptr;
        temp->ptr = NULL;
        delete temp;

    };

    void popE(){
        node* temp=head;
        while(temp->ptr != tail){
            temp = temp->ptr;
        }
        temp ->ptr= NULL;
        delete tail;
        tail = temp;
        delete temp;

    };

    void insert(int val, int pos){
        if(pos<0){
            cout<<"Invalid position!"<<endl;
            return;
        }
        if(pos==0){
            pushFront(val);
            return;
        }
        node* temp = head;
        if(temp == NULL){
            cout<<"Empty linked list! Please enter elements first";
            return;
        }

        for(int i = 0;i<pos-1;i++){
            temp=temp->ptr;
        }

        node* newNode = new node(val);
        newNode->ptr = temp->ptr;
        temp->ptr = newNode; 



        
    }
    void printl(){
        node* temp = head;
        while(temp->ptr != NULL){
            cout<<temp->data<<"\t";
            temp = temp->ptr;
        }

    };



};


int main(){
    linkedlist a;
    cout<<"Push front operation "<<endl;
    a.pushFront(3);
    a.pushFront(1);
    a.pushFront(5);
    a.pushFront(8);
    a.pushFront(9);
    a.pushFront(2);
    a.printl();
    cout<<endl;
    

    a.popE();
    a.popf();
    a.printl();

}