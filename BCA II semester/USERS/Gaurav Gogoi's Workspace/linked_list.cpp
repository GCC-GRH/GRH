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
        void push_front(int val){
          Node* newNode = new Node(val);
          if(head==NULL){
            head=newNode;
          }else{
            newNode->next=head;
            head=newNode;
          }
          
        };
        void printl(){
          Node* viewer=head;
          while (viewer!=NULL)
          { 
            cout<<viewer->data<<" -> ";
            viewer=viewer->next;
          }
          if(viewer==NULL){
            cout<<"NULL"<<endl;
          }
         
        };
          
        };

int main(){
int val,n;
List ll;
cout<<"How many data items would you like to reserve in Linked list?\n==>";
cin>>n;
for(int i=n;i>=0;i--){
cout<<"Enter value for Data item "<<i<<": "<<endl;
cin>>val;
ll.push_front(val);
}
ll.printl();
}


