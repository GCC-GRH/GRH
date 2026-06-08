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
        }

        void pushback(int val){
            node* newNode = new node(val);
            if(tail!=NULL){
                tail->next = newNode;
                tail = newNode;
            }else{
                head = tail = newNode;
            }
        }

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
        }


        void prints(){
            node* temp = head;
            while(temp!= NULL){
                cout<<temp->data<<"\t";
                temp = temp->next;
            }
            cout<<" < FIFO operation from here"<<endl;
        }

        int fetchh(){
            return tail->data;
        }
    };


    class stack{
        linkedlist s;
        public:
        void spush(int val){
            s.pushback(val);
        }

        void spop(){
            s.popback();
        }

        void printstack(){
            s.prints();
        }

        bool isEmpty(){
            return s.fetchh() == NULL;
        }
    };


    int main(){
        stack s1;
        s1.spush(7);
        s1.spush(7);
        s1.spush(7);
        s1.spush(7);
        s1.spush(7);

        s1.printstack();
        s1.spop();
        s1.printstack();
    }