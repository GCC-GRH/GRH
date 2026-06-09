#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class graph{
    int vertices;
    list <int> *l;
    list <pair<int,int>> *weight;










    void dfs_stackcall(int u,bool visited[]){
        cout<<u<<" ";
        visited[u] = true;
        for(int i : l[u]){
        if(!visited[i]){
        dfs_stackcall(i,visited);
        }
    }
    }

    bool cycle_dfs_call(int u,bool visited[],int parent[]){
    visited[u] = true;
    parent[u] = u;
    for(int i : l[u]){
        if(!visited[i]){
            parent[i] = u;
            if(cycle_dfs_call(i,visited,parent)) return true;
        }else if(parent[u] != i){
            cout<<"Cycle detected between edge ("<<u<<","<<i<<")"<<endl; 
            return true;
        }
    }
    return false;
}
    public:
    graph(int v){
        vertices = v;
        l = new list<int>[vertices];
        weight = new list <pair<int,int>>[vertices];
    }

    void addWedge(int u, int v, int w){
        l[v].push_back(u);
        weight[v].push_back({u, w});
        l[u].push_back(v);
        weight[u].push_back({v,w});
    }

    void addEdge(int u, int v){
        
        l[v].push_back(u);
        l[u].push_back(v);
    
    }

    void printg(){
        for(int i = 0;i < vertices; i++){
            cout<<i<<" : ";
            if(!weight[i].empty()){
                for(auto& pair : weight[i]){
                    cout<<"("<<pair.first <<","<<pair.second<<") ";
                }

            }else{
            
            for(int j : l[i]){
                cout<<j<<" ";
            }
        }
            cout<<endl;
        }
    }

    void bfs(){
        bool *visited = new bool[vertices];
        for(int i=0;i<vertices;i++){
            visited[i] = false;
        }
        queue <int> q;
        for(int i = 0; i<vertices; i++){
        if(visited[i]) continue;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            for(int neigh : l[u]){
                if(!visited[neigh]){
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }
    }
    delete[] visited;
    }
    void dfs(){ // DFS wrapper function
        bool* visited = new bool[vertices];
        for(int i = 0; i<vertices;i++){
            visited[i] = false;
        }
        for(int source = 0; source<vertices;source++){
            if(visited[source]) continue;
            dfs_stackcall(source,visited);
        }
        delete[] visited;
    }

       void cycle(){ // Graph Cycle checker wrapper function
        bool* visited = new bool[vertices];
        for(int i = 0; i<vertices;i++){
            visited[i] = false;
        }
        int* parent = new int[vertices];
            for(int i = 0; i<vertices; i++){
            parent[i] = -1;  // Initialize to -1
        }
        for(int source = 0; source<vertices;source++){
            if(visited[source]) continue;
            if(cycle_dfs_call(source,visited,parent)){
                delete[] visited;
                delete[] parent;
                return;
            }

        }
        delete[] visited;
        delete[] parent;
        cout<<"No cycle detected within the graph"<<endl;
    }

    void primst(){
        bool* mst_visited = new bool[vertices];
        for(int i = 0; i<vertices; i++){
            mst_visited[i] = false;
        };
        priority_queue < pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >pq;
        int mstcost = 0;
        pq.push({0,0});
        while(pq.size() > 0){
            pair<int,int> p = pq.top();
            int wt = p.second;
            int u = p.first;
            pq.pop();

            if(!mst_visited[u]){
                mst_visited[u] = true;
                mstcost +=wt;
                for(pair <int,int> i : weight[u]){
                    int v = i.first;
                    int w = i.second;
                    if(mst_visited[v]) continue;

                    pq.push({v,w});
                }
            }
        }
        cout<<endl<<"The minimum spanning tree is bearing COST : "<<mstcost;
        delete[] mst_visited;
        return;
    }
    
    ~graph(){ // avoiding memory leak
        delete[] l;
        delete[] weight;
    };

};



int main(){
    graph g(4);
    //Unweighted graph edges
    // g.addEdge(0,1);
    // g.addEdge(0,2);
    // g.addEdge(0,3);
    // g.addEdge(1,2);
    // g.addEdge(3,4);

    // Weighted graph edges
    g.addWedge(0, 1, 10); // u, v , wt
    g.addWedge(1, 0, 10);
    g.addWedge(0, 3, 30);
    g.addWedge(3, 0, 30);
    g.addWedge(0, 2, 15);
    g.addWedge(2, 0, 15);
    g.addWedge(1, 3, 40);
    g.addWedge(3, 1, 40);
    g.addWedge(2, 3, 50);
    g.addWedge(3, 2, 50);
    g.printg();
    // g.bfs();
    // g.dfs();
    // g.cycle();
    g.primst();
}
