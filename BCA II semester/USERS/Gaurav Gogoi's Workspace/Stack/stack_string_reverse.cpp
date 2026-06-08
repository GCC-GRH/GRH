#include<iostream>
#include<cstring>
using namespace std;
class node{
    public:
    char data[50];
    node* next;
    node(char data_value[]){
        memcpy(data,data_value,sizeof(data_value));
        next = NULL;
    }
};

class linkedlist{
    node* head;
    node* tail;
    public:
    linkedlist(){
        tail = head = NULL;
    }

    void pushb(char a[]){
        node* newnode = new node(a);
        if(tail == NULL){
            tail = head = newnode;
        }else{
            tail->next = newnode;
            tail = newnode;
        }

    };

     void popback(){
            if(tail==NULL){
                cout<<"No data item to pop"<<endl;
            }else{
                node* temp = head;
                while(temp->next!=tail){
                    temp = temp->next;
                }
                temp->next = NULL;
                delete tail;
                tail = temp;     
            }
        };

        void prints(){
            node* temp = head;
            while(temp!= NULL){
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<" < FIFO operation from here"<<endl;
        };


    };

    class stack{
        linkedlist s;
        public:
        void spush(char val[]){
            s.pushb(val);
        }

        void spop(){
            s.popback();
        }

        void printstack(){
            s.prints();
        }
    };