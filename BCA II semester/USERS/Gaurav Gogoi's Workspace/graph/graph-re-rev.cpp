#include<iostream>
#include<list>
using namespace std;
class graph{
    list <int> *l;
    int vertices;
    int build_state;
    private:
    void dfs_stackcall(int source,bool visited[]){
        if(!visited[source]){
            cout<<source<<" ";
            visited[source] = true;
            for(int i : l[source]){
                dfs_stackcall(i, visited);
            }
        }
    }


    bool cycle_stackcall(int source, bool visited[], int parent[]){
            cout<<source<<" ";
            visited[source] = true;
            for(int i : l[source]){
                if(!visited[i]){
                parent[i] = source;
                if(cycle_stackcall(i, visited, parent)) return true;
                }else{
                    if(i != parent[source]) return true;
                }
            }
        return false;
    }









    public:
    graph(int size){
        vertices = size - 1;
        l = new list<int>[size];
    }

    void addedge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printg(){
        for(int u = 0; u<= vertices;u++){
            cout<<u<<" : ";
            for(int v : l[u]){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }

    void dfs(){
        bool *visited = new bool[vertices + 1];
        for(int i = 0; i<=vertices; i++) visited[i] = false;
        for(int i = 0; i<= vertices; i++){
        if(visited[i]) return;
        dfs_stackcall(i,visited);
        }

    }

    void cycle(){
        bool* visited = new bool[vertices + 1];
        int* parent = new int[vertices + 1];
        for(int i = 0; i<= vertices;i++) visited[i] = false;
        for(int i = 0; i<=vertices; i++){
            parent[i] = -1;
            if(visited[i]) continue;
            if(cycle_stackcall(i,visited,parent)){
                cout<<"Cycle detected within the graph!!"<<endl;
            }

        }
    }


};


int main(){
    graph g(5);
     g.addedge(0,1);
     g.addedge(0,2);
     g.addedge(0,3);
     g.addedge(1,2);
     g.addedge(3,4);
     g.printg();
}