#include<iostream>
#include<list>
#include<set>
#include<stdexcept>
#include<queue>
using namespace std;

class graph{
    list <int> *l = nullptr;
    int vertices;
    list <pair<int,int>> *weigh = nullptr;
    int build_state = -1;

    void dfs_stackcall(int source, bool visited[]){
        cout<<source<<" ";
        visited[source] = true;
        if(build_state == 0){
            for(int i : l[source]){
                if(visited[i]) continue;
                dfs_stackcall(i,visited);
            }
        }else{
            for(pair<int,int> i : weigh[source]){
                if(visited[i.first]) continue;
                dfs_stackcall(i.first, visited);
            }
        }
    }

    public:
    graph(int size){
        if(size <= 0){
            throw invalid_argument("Graph size must be greater then 0. Failed to deploy graph object!");
        }
        vertices = size;
    }

    void addedge(int u, int v){
        if(build_state == 1){
            cout<<"Cannot add unweighted edge in a weighted graph! Please delete existing graph."<<endl;
            return;
        }
        if(u > vertices - 1 || v > vertices - 1){
            cout<<"Out of bound values entered {Greater then declared vertices in memory}, please modify!"<<endl;
            return;
        }

         if(u < 0 || v < 0){
            cout<<"Out of bound values entered {Negative range!}, please modify!"<<endl;
            return;
        }
        if(l == nullptr){
            l = new list<int>[vertices];
            build_state = 0;
        }
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void addwedge(int u, int v, int w){
        if(build_state == 0){
            cout<<"Cannot add weighted edge in a unweighted graph! Please delete existing graph."<<endl;
            return;
        }
        if(u > vertices - 1 || v > vertices - 1){
            cout<<"Out of bound values entered {Greater then declared vertices in memory}, please modify!"<<endl;
            return;
        }
        if(u < 0 || v < 0){
            cout<<"Out of bound values entered {Negative range!}, please modify!"<<endl;
            return;
        }
        if(weigh == nullptr){
            weigh = new list<pair<int,int>>[vertices];
            build_state = 1;
        }
        weigh[u].push_back({v,w});
        weigh[v].push_back({u,w});
    }


    void printg(){
        if(build_state == -1){
            cout<<"Cannot print an empty graph! Please add vertices first!"<<endl;
            return;
        }
        for(int i = 0; i<vertices; i++){
            cout<<i<<" : ";
            if(build_state == 0){
                for(int v : l[i]){
                    cout<<v<<" ";
                }
            }else if(build_state == 1){
                for(pair<int,int> v : weigh[i]){
                    cout<<"( "<<v.first<<","<<v.second<<")";
                }
            }
            cout<<endl;
        }
    }

    void pop(){
        if(build_state == 0){
            delete[] l;
            l = nullptr;
            build_state = -1;
        }else if(build_state == 1){
            delete[] weigh;
            weigh = nullptr;
            build_state = -1;
        }else{
            cout<<"Cannot delete an empty graph!"<<endl;
        }
    }

    void bfs(){
        if(build_state == -1){
            
            cout<<"Cannot perform BFS traversal on an empty graph!"<<endl;    
            return;
        }
       
        int data;
        queue <int> q;
        bool *visited = new bool[vertices];
        for(int i = 0; i<vertices; i++) visited[i] = false;
        for(int i = 0; i<vertices; i++){
        if(visited[i]) continue;
        q.push(i);
        visited[i] = true;
        while (!q.empty())
        {   data = q.front();
            q.pop();
            cout<<data<<" ";
            if(build_state == 0){
            for(int i : l[data]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }else{
            if(build_state == 1){
                for(pair<int,int> i : weigh[data]){
                    if(!visited[i.first]){
                        q.push(i.first);
                        visited[i.first] = true;
                    }
                }
            }
        }
        }
    }
        
        delete[] visited;
    }

    void dfs(){
        if(build_state == -1){
            cout<<"Cannot perform DFS traversal in an empty graph. Please enter edges first!"<<endl;
            return;
        }
        bool *visited = new bool[vertices];
        for(int i = 0; i<vertices; i++) visited[i] = false;
        for (int i = 0; i < vertices; i++)
        {
            if(visited[i]) continue;
            dfs_stackcall(i, visited);
        }

        delete[] visited;
        
    }






    ~graph(){
        if(build_state == 0) delete[] l;
        if(build_state == 1) delete[] weigh;
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