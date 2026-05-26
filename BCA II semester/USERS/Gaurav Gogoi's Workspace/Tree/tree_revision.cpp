#include<iostream>
#include<queue>
using namespace std;
static int idx = -1;
class tnode{
    public:
    int data;
    tnode* left;
    tnode* right;
    tnode(int val){
        data = val;
        left = NULL;
        right = NULL;
    };
};

class tree{
    public:
    tnode* root = NULL;
    tnode* buildTree(int nodes[]){
        idx++;
        if(nodes[idx] == -1){
            return nullptr;
        }
    tnode* newNode = new tnode(nodes[idx]);
    newNode->left = buildTree(nodes);
    newNode->right = buildTree(nodes);
    root = newNode;
    return newNode;
    };
    void preOrder(tnode* n){
        if(n == nullptr){
            cout<<"-1"<<"\t";
            return;
        }
        cout<<n->data<<"\t";
        preOrder((n->left));
        preOrder((n->right));

    };

    void postOrder(tnode* n){
        if(n == nullptr){
            cout<<"-1"<<"\t";
            return;
        }
    
        postOrder((n->left));
        postOrder((n->right));
        cout<<n->data<<"\t";

    };

        void inOrder(tnode* n){
        if(n == nullptr){
            cout<<"-1"<<"\t";
            return;
        }
    
        inOrder((n->left));
        cout<<n->data<<"\t";
        inOrder((n->right));
        

    };
};

int main(){
    int vertices[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    tree t1;
    t1.buildTree(vertices);
    // t1.preOrder(t1.root);
    // t1.postOrder(t1.root);
    t1.inOrder(t1.root);

}

