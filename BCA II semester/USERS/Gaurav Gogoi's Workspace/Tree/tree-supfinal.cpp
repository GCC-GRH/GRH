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
        right=nullptr;
    }
};

class tree{
    tnode* root;
    int idx = -1;
    int buildstate = -1;
    
    tnode* buildTree_wrapper(int indices[]){
        idx++;
        buildstate = 0;
        if(indices[idx]== -1) return nullptr;
        tnode* newNode = new tnode(indices[idx]);
        newNode->left = buildTree_wrapper(indices);
        newNode->right = buildTree_wrapper(indices);
        root = newNode;
        return root;

    }

    void preorder_wrapper(tnode* n){
        if(n==nullptr){
            cout<<"-1"<<" ";
            return;
        }
        cout<<n->data<<" ";
        preorder_wrapper(n->left);
        preorder_wrapper(n->right);
    }


    void postorder_wrapper(tnode* n){
        if(n==nullptr){
            cout<<"-1"<<" ";
            return;
        }
        
        postorder_wrapper(n->left);
        postorder_wrapper(n->right);
        cout<<n->data<<" ";
    }

    void inorder_wrapper(tnode* n){
        if(n==nullptr){
            if(buildstate == 1){
                return;

            }else if(buildstate == 0){
            cout<<"-1"<<" ";
            return;
            }
        }
        
        inorder_wrapper(n->left);
        cout<<n->data<<" ";
        inorder_wrapper(n->right);
        
    }


    void levelorder_wrapper(){
        queue <tnode*> data;
        tnode* front;
        data.push(root);
        while(!data.empty()){
            front = data.front();
            data.pop();
            cout<<front->data<<" ";
            if(front->left != nullptr) data.push(front->left);
            if(front->right != nullptr) data.push(front->right);
        }
    }


    tnode* insert(tnode* n, int val){
        if(n==nullptr) return new tnode(val);
        if(n->data > val){
        n->left = insert(n->left, val);
        }else{
        n->right = insert(n->right, val);
        }

        return n;
    }





    public:
    void buildtree(int vertices[]){
        
        if(buildstate == 1){
            cout<<"Tree already built, please delete first!";
            return;
        }

        root = buildTree_wrapper(vertices);
    }

    void inorder(){
        if(root == nullptr){
            cout<<"Cannot traverse an empty tree!"<<endl;
            return;
        }
        inorder_wrapper(root);
    }

    void postorder(){
        if(root == nullptr){
            cout<<"Cannot traverse an empty tree!"<<endl;
            return;
        }
        postorder_wrapper(root);
    }

    void preorder(){
        if(root == nullptr){
            cout<<"Cannot traverse an empty tree!"<<endl;
            return;
        }
        preorder_wrapper(root);
    }

    void deleteTreehelper(tnode* n){
        if(n == nullptr) return;
        if(n->left != nullptr) deleteTreehelper(n->left);
        if(n->right != nullptr) deleteTreehelper(n->right);
        delete n;

    }

    void deletetree(){
        if(root == nullptr){
            cout<<"Cannot delete an emppty tree!"<<endl;
            return;
        }
        deleteTreehelper(root);
        buildstate = -1;
        idx = -1;
        root = nullptr;
    }

    void levelOrder(){
        if(root == nullptr){
            cout<<"Cannot traverse an empty tree!"<<endl;
            return;
        }
        levelorder_wrapper();
    }

    void buildBST(int vertices[], int size){
        if(buildstate == 0){
            cout<<"Tree already built, please delete first!";
            return;
        }
        buildstate = 1;

        for(int i=0; i<size;i++){
            if(vertices[i] == -1) continue;
            root = insert(root, vertices[i]);
        }
    }



};



int main(){
    int BinaryTree[] = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    int bst[] = {3, 1, 4, 2, 5};
    int size = sizeof(BinaryTree)/sizeof(BinaryTree[0]);
    int sizebst = sizeof(bst)/sizeof(bst[0]);
    tree t1;
    t1.buildtree(BinaryTree);
    t1.preorder();
    cout<<endl;
    t1.deletetree();
    t1.buildBST(bst,sizebst);
    cout<<endl;
    t1.inorder();
}