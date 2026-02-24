#include<iostream>
using namespace std;

class Node {
    public:
      int data;
      Node* next;
      
      Node(int val){
        data=val;
        next=NULL;
      }
};

class List{
  
    Node* head;
    Node* tail;
    
      public:
        List(){
        head = tail = NULL;
        } 
        
        
        void push_head(int val){
          Node* newNode = new Node(val);
          if(head==NULL){
            head=tail=newNode;
          }else{
            newNode->next=head;
            head=newNode;
          }
          
        };
        
        
        
        void push_tail(int val){
          Node* newNode = new Node(val);
          if(head==NULL){
            head=tail=newNode;
          }else{
            tail->next=newNode;
            tail=newNode;
          }
        };
       
       
       
        void pop_front(){
          if(head==NULL){
            cout<<"Empty linked list. Please insert Data items first!"<<endl;
          }else{
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
          }
        };

        void pop_back(){
          if(tail==NULL){
            cout<<"Empty linked list. Please insert Data items first!"<<endl;
          }else{
            Node* temp=head;
            while(temp->next!=tail){
              temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail=temp;
            delete temp;
          }
        };
        
        
        
        
        void printl(){
          int i=0;
          Node* viewer=head;
          cout<<"The Linked List structure in memory :"<<endl;
          while (viewer!=NULL)
          { 
            cout << "+------------+\n";
            cout << "|     " << viewer->data << "      |";
            cout << "\n+-----" << i << "------+\n";
            cout <<"      |\n";
            cout<<"      V\n";

            viewer = viewer->next;
            i++;

          }
          if(viewer==NULL){
            cout<<"NULL"<<endl;
          }
         
        };

          
        };

int main(){
int val,n,opt=0;
int head_flag=0;
List ll;
cout<<"How many data items would you like to reserve in Linked list?\n==>";
cin>>n;
for(int i=n;i>=0;i--){
cout<<"Enter value for Data item "<<i<<": "<<endl;
cin>>val;
if(head_flag==0){
  
  ll.push_head(val);
  head_flag=1;
}else{
cout<<"Choose Linked list operation:"<<endl<<"0. Push head\n1. Push tail"<<"==>"<<endl;
cin>>opt;

(opt==0)? ll.push_head(val) : ll.push_tail(val);
}
}
ll.printl();
}


