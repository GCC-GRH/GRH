#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }

};

class linkedlist {
    node* head;
    node* tail;

    public:
    linkedlist(){
        head = tail = NULL;
    };
    void push_front(int val){
        if(head == NULL){
            node* newNode = new node(val);
            head = tail  = newNode;
        }else{
            node* newNode = new node(val);
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        if(tail == NULL){
            node* newNode = new node(val);
            head = tail = newNode;
        }else{
            node* newNode = new node(val);
            tail->next = newNode;
            tail = tail->next;
        }
    }


    void insert(int pos, int val){
        node* temp = head;
        for(int i = 0; i<pos; i++){
            if(temp->next != NULL){
                temp = temp->next; 
            }
        }
      node* newNode = new node(val);
      newNode->next = temp->next;
      temp->next = newNode; 

    }

    void printl(){
        node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<endl;
    }

    void pop_front(){
        if(head == NULL){
            cout<<"Cannot delete element from an empty linked list"<<endl;
        }else{
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void pop_back(){
        if(head == NULL){
            cout<<"Cannot delete element from an empty linked list"<<endl;
        }else{
            node* temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
        }
    }
    // Circular Linked list building 
    void cir_push_front(int val){
        node* newNode = new node(val);
        if(head == NULL){
            tail = head = newNode;
            tail->next = head;
        }else{
            newNode->next = head;
            head = newNode;
            tail->next = newNode;
        }
    }


};



int main(){
    linkedlist l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.insert(1,5);
    l.pop_back();
    l.pop_back();
    l.printl();

}