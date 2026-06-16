#include<iostream>
#include<queue>
using namespace std;
class tnode{
    public:
    int data;
    tnode* left;
    tnode* right;
    tnode(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class tree{
    tnode* root = nullptr;
    int idx = -1;
    int bst_idx = -1;
    int build_state = -1;
    queue <tnode*> q;
    public:
    tnode* buildtree(int indices[]){
        idx++;
        build_state = 0;
        if(indices[idx] == -1) return nullptr;
        tnode* newNode = new tnode(indices[idx]);
        newNode->left = buildtree(indices);
        newNode->right = buildtree(indices);
        root = newNode;
        return root;
    }

    private:
    void preOrder_wrapper(tnode* n){
        if(n == nullptr){
            cout<<"-1"<<" ";
            return;
    }
    cout<<n->data<<" ";
    preOrder_wrapper(n->left);
    preOrder_wrapper(n->right);
    }

    void inOrder_wrapper(tnode* n){
        if(n == nullptr){
            if(build_state == 0) cout<<"-1"<<" ";
            if(build_state == 1) return;
            return;
    }
    
    inOrder_wrapper(n->left);
    cout<<n->data<<" ";
    inOrder_wrapper(n->right);
    }

    void postOrder_wrapper(tnode* n){
        if(n == nullptr){
            cout<<"-1"<<" ";
            return;
    }
    
    postOrder_wrapper(n->left);
    postOrder_wrapper(n->right);
    cout<<n->data<<" ";
    }

    void levelOrder_wrapper(){
        while(!q.empty()){
        tnode* dat = q.front();
        q.pop();
        cout<<dat->data;
        if(dat->left != nullptr) q.push(dat->left);
        if(dat->right != nullptr) q.push(dat->right);
        }
        
    }

    tnode* pushbst(int val, tnode* root){
        if(root==nullptr) return new tnode(val);
        if(val < root->data){
            root->left = pushbst(val, root->left);
        }else{
            root->right = pushbst(val, root->right);
        }
        return root;
    }

    public:
    void preOrder(){
        if(root == nullptr){
            cout<<"Empty tree! Cannot traverse. "<<endl;
            return;
        }
        preOrder_wrapper(root);
    }
    
    void inOrder(){
        if(root == nullptr){
            cout<<"Empty tree! Cannot traverse. "<<endl;
            return;
        }
        inOrder_wrapper(root);
    }

    void postOrder(){
        if(root == nullptr){
            cout<<"Empty tree! Cannot traverse. "<<endl;
            return;
        }
        postOrder_wrapper(root);
    }

    void levelorder(){
        if(root == nullptr){
            cout<<"Empty tree! Cannot traverse."<<endl;
            return;
        }
        q.push(root);
        levelOrder_wrapper();
    }

    void buildbst(int arr[], int size){
        root = nullptr;
        build_state = 1;
        for(int i = 0; i<size; i++){
            if (arr[i] == -1) continue;
            root = pushbst(arr[i], root);
        }
        

    }
 

};


int main(){
    int BinaryTree[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int size = sizeof(BinaryTree) / sizeof(BinaryTree[0]);
    tree t1;
    t1.buildtree(BinaryTree);
    t1.preOrder();
    cout<<endl;
    t1.inOrder(); 
    cout<<endl;
    t1.postOrder();
    cout<<endl;
    t1.levelorder();
    cout<<endl;
    t1.buildbst(BinaryTree,size);
    t1.inOrder();
} 