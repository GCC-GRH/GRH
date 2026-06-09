#include<iostream>
using namespace std;
class dnode{
    public:
    int data;
    dnode* next;
    dnode* prev;
    dnode(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class dlinkedlist{
    dnode* head;
    dnode* tail;
    public:
    dlinkedlist(){
        head = tail = NULL;
    }


    void push_front(int val){
        dnode* newNode = new dnode(val);
        if(head == NULL){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val){
        dnode* newNode = new dnode(val);
        if(tail == NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head == NULL){
            cout<<"Cannot delete an empty double linked"<<endl;
        }else if(head == tail){
            delete head;
            head = tail = NULL;

        }else{
            dnode* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void pop_back(){
       if(tail == NULL){
        cout<<"Cannot delete an empty linked list"<<endl;
       }else if(head == tail){
            delete tail; 
            head = tail = NULL;
       }else{
            dnode* temp;
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
       }
    }

    void insert(int pos, int element){
        if(head == tail || pos == 0){
            push_back(element);
            return;
        }

        if(head == NULL){
            cout<<"Cannot insert element in an empty linked list"<<endl;
            return;
        }
        
        
            dnode* temp = head;
            for(int i = 0; i<pos; i++){
               temp=temp->next;
            }
                dnode* newNode = new dnode(element);
                newNode->next = temp->next;
                newNode->prev = temp;
                if(temp->next) temp->next->prev = newNode;
                temp->next = newNode;
                if(newNode->next == NULL) tail = newNode;

        }

    void printdll(){
        dnode* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp -> next;
        }
        cout<<endl;
    }
};

int main(){
    dlinkedlist l;
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
    l.push_front(4);
    l.printdll();


}
