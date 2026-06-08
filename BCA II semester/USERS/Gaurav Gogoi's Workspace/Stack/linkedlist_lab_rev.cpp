#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    };
};

class linkedlist{
    node* head;
    node* tail;
    public:
    linkedlist(){
    head = tail = NULL;
    };

    void pushf(int a){
        node* newnode = new node(a);
        if(head == NULL){
            head = tail = newnode;
        }else{
            newnode->next = head;
            head = newnode;
        }
    }

    void pushb(int a){
        node* newnode = new node(a);
        if(tail == NULL){
            tail = head = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void popf(){
        if(head == NULL){
            cout<<"Cannot delete an empty linked list!"<<endl;
            return;
        }else{
            node* temp;
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void popb(){
        if(tail == NULL){
            cout<<"Cannot delete an empty linked list!"<<endl;
        }else{
            node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }
    }

    void printl(){
        node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        
    }

    void insert(int val, int pos){
        node* temp = head;
        for(int i = 0; i<pos - 1;i++){     // 2 3 5 2 5
            temp = temp->next;
        }
        node* newnode = new node(val);
        newnode->next = temp->next;
        temp->next = newnode;

    }

    void reverse(){ 
    linkedlist temp;
    while(head != NULL){
        int val = head->data;
        popf();
        temp.pushf(val);
    }

    head = temp.head;
    tail = temp.tail;
};

};


int main(){
    linkedlist a;
    a.pushf(1);
    a.pushf(2);
    a.pushf(3);
    a.pushf(4);
    a.pushf(5);
    a.pushf(6);
    a.reverse();
    a.printl();
}