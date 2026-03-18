#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* ptr;
        node(int val){
        data = val;
        ptr = NULL;
        }


};

class linkedlist{
    node* head;
    node* tail;
    public:
    linkedlist(){
        head=tail=NULL;
    }

    void push_front(int val){
        node* newNode = new node(val); 
        if(head==NULL){
        head = tail = newNode;
        }else{
            newNode->ptr = head;
            head=newNode;
        }
    };

    void pop_front(){
        if(head !=NULL){
        node* temp;
        temp = head;
        head = head->ptr;
        temp->ptr = NULL;
        delete temp;
        }else{
            cout<<"Empty linked list!"<<endl;
        }
    }

    int top(){
        return head->data;
    }

    int size(){
        int cnt = 0;
        node* temp = head;
        if(temp==NULL){
            return cnt;
        }else{
            while(temp != NULL){
                temp = temp->ptr;
                cnt++;
            }
            return cnt;
        }
    }
};

class stack{
    linkedlist ll;
    public: 
        void push(int val){
            ll.push_front(val);
        };

        void pop(){
            ll.pop_front();
        };

        int top(){
            return ll.top();
        }

        bool empty(){
            return ll.size() == 0;
        }
};

int main(){
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while(!s.empty()){
        cout << s.top() <<" ";
        s.pop();
    }
    cout<<endl;
}