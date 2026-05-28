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
    };
};

class tree{
    public:
    tnode* root = nullptr;
    tnode* buildTree(int nodes[]){
        build_state = 0;
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
            if(build_state == 0){
            cout<<"-1"<<"\t";
            }
            return;
        }
        cout<<n->data<<"\t";
        preOrder((n->left));
        preOrder((n->right));

    };

    void postOrder(tnode* n){
        if(n == nullptr){
            if(build_state == 0){
            cout<<"-1"<<"\t";
            }
            return;
        }
    
        postOrder((n->left));
        postOrder((n->right));
        cout<<n->data<<"\t";

    };

        void inOrder(tnode* n){
        if(n == nullptr){
            if(build_state == 0){
            cout<<"-1"<<"\t";
            }
            return;
        }
    
        inOrder((n->left));
        cout<<n->data<<"\t";
        inOrder((n->right));
        

    };

    void levelOrder(tnode* n){
        queue <tnode*> indices;
        if(n == nullptr){
            return;
        }
        indices.push(n);
        while(indices.size() > 0){
        tnode* nd = indices.front();
        indices.pop();
        cout<<nd->data<<"\t";
        if(nd->left != nullptr){
            indices.push(nd->left);
        };
        if(nd->right != nullptr){
            indices.push(nd->right);
        };
    }
    };


    tnode* insert(tnode* root, int value){
        if(root == nullptr){
            return new tnode(value);
        }
        if(value < root->data){
            root->left = insert(root->left,value);
        }else{
            root->right = insert(root->right,value);
        }
        return root;
    };

    void buildBst(int arr[], int size){
        build_state = 1;
        for(int i = 0; i < size; i++){
            root = insert(root, arr[i]);
        }
    };
    bool search(tnode* root, int key){
        if(root == nullptr){
            cout<<endl;
            cout<<"Element not found in any nodes. Exiting Binary Search!"<<endl;
            return false;
        }
        if(root->data == key){
            cout<<"Element found!"<<endl;
            return true;
        }
        if(key < root->data){
           return search(root->left, key);
        }else{
            return search(root->right, key);
        }
    }

    tnode* pop(tnode* root, int key){
          if(root == nullptr){
            cout<<endl;
            cout<<"Element not found in any nodes. Cannot delete!"<<endl;
            
        }
        if(root->data == key){
            cout<<"Element found! Deleted"<<endl;
            tnode* temp = root;
            root = root->right;
            delete temp;
            return root;
            
            
        }
        if(key < root->data){
           root-> left = pop(root->left, key);
        }else{
           root-> right =  pop(root->right, key);
        } 
    }
};

int main(){
    int vertices[] = {3,2,1,5,6,4};
    int size = sizeof(vertices)/sizeof(vertices[0]);
    tree t1;

    // Building methods
       // t1.buildTree(vertices);       
       t1.buildBst(vertices,size);

    // Traversing methods
       // t1.preOrder(t1.root);
       // t1.postOrder(t1.root);
       // t1.inOrder(t1.root);
       // t1.levelOrder(t1.root);

    // Searching techniques
    // t1.search(t1.root,6);

    // Deleting a node
     t1.root = t1.pop(t1.root,2);
     t1.inOrder(t1.root);
}

