#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){ // Tree constructor
        data = val;
        left = NULL;
        right = NULL;
    }
};
static int idx = -1;
node* buildtree(int arr[]){
    idx++;
    if(arr[idx]==-1){ 
        return nullptr;
    }
    node* root = new node(arr[idx]);
    root->left = buildtree(arr); //left
    root->right = buildtree(arr); // right

    return root;
};

void preOrder(node* n){
    if(n == nullptr){
        cout<<"-1"<<"\t";
        return;
    }else{
        cout<<n->data;
        cout<<"\t";
        preOrder(n->left); // Left traversing of data elements
        preOrder(n->right); // Right traversing of data elements
    }
};
void inorder(node* n){
    if(n==nullptr){
        return;
    }else{
        inorder(n->left);
        cout<<n->data<<"\t";
        inorder(n->right);
    }
};

void postorder(node* n){
    if(n==nullptr){
        return;
    }else{
        postorder(n->left);
        postorder(n->right);
        cout<<n->data<<"\t";
    }
}

void levelOrder(node* root){
    vector <int> ans;
    if(root==NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        
        vector<int> level;
        for(int i = 0; i<size; i++){
            node* n = q.front();
            q.pop();
            if(n->left != NULL) q.push(n->left);
            if(n->right != NULL) q.push(n->right);
            level.push_back(n->data);
        }
        ans.push_back(level);
    }

}

int main(){
    int BinaryTree[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node* root = buildtree(BinaryTree);
    preOrder(root);
    cout<<endl;
    inorder(root); 
    cout<<endl;
    postorder(root);
} 