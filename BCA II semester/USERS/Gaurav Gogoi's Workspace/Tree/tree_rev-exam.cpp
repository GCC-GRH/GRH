#include<iostream>
#include<queue>
using namespace std;
static int idx = -1;
static int build_state;
class tnode{
    public:
    int data;
    tnode* left;
    tnode* right;
    tnode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class tree{
    public:
    tnode* root = nullptr;
    tnode* prev = nullptr;
    tnode* buildtree(int indices[]){
        build_state = 0;
        idx++;
        if(indices[idx] == -1){
             return nullptr;
        }
        tnode* newNode = new tnode(indices[idx]);
        newNode-> left = buildtree(indices);
        newNode-> right = buildtree(indices);
        root = newNode;
        return root;
    }

   
    void preorder(tnode* n){
        if(n==nullptr){
            cout<<"-1"<<" ";
            return;
        }

        cout<<n->data<<" ";
        preorder((n->left));
        preorder((n->right));
        }

    void postorder(tnode* n){
        if(n == nullptr){
            cout<<"-1"<<" ";
            return;
        }
        postorder(n->left);
        postorder(n->right);
        cout<<n->data<<" ";
    }

    void inorder(tnode* n){
        if(n == nullptr){
            if(build_state == 0){
                cout<<"-1"<<" ";
            }
            
            return;
        }
        inorder(n->left);
        cout<<n->data<<" ";
        inorder(n->right);
    }

    void levelOrder(tnode* n){
        queue <tnode*> q;
        q.push(root);
        while(!q.empty()){
            tnode* dat = q.front();
            cout<<dat->data<<" ";
            q.pop();

            if(dat->left != nullptr) q.push(dat->left);
            if(dat->right != nullptr)q.push(dat->right);

        }
    }
    tnode* insertbst(tnode* root, int val){
        if(root == nullptr) return new tnode(val);
        if(val < root->data){
            root->left = insertbst(root->left,val);
        }else{
            root->right = insertbst(root->right,val);

        }
        return root;
    }
    
    void searchBst(tnode* root, int target){
        
        if(root == nullptr){
            cout<<"Element not found"<<endl;
            return;
        };

        if(target == root->data){
            cout<<"Element found"<<endl;
            return;
        }

        if(target < root->data){
            searchBst(root->left,target);
        }else{
            searchBst(root->right, target);
        }
    }


    void buildbst(int arr[], int size ){
        build_state = 1;
        for(int i = 0; i<size; i++){
            root = insertbst(root, arr[i]);
        }
        
    }

    private:
      tnode* deleteBstn(tnode* root, int target){
        
        if(root == nullptr){
            return nullptr;
        }

        if(target < root->data){
            root->left = deleteBstn(root->left,target);
        }else if(target > root->data){
            root->right = deleteBstn(root->right,target);
        }

        if(target == root->data){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }else if(root -> left == nullptr){
                tnode * temp = root->right;
                delete root;
                return temp;
            }else if(root->right ==nullptr){
                tnode * temp = root->left;
                delete root;
                return temp;
            }else{
                // two child case
            }

        
            
        }
        return root;
}

    public:
    void popBst(int target){  // function wrapper for deletebstn
        if(root == nullptr){
            cout<<"Attempting to delete an empty tree"<<endl;
        }
        root = deleteBstn(root, target);
    }



};


int main(){
    int vertices[] = {3,2,1,5,6,4};
    int size = sizeof(vertices)/sizeof(vertices[0]);
    tree t1;
    t1.buildbst(vertices,size);
    t1.inorder(t1.root);
    t1.searchBst(t1.root,6);
    cout<<endl;

}