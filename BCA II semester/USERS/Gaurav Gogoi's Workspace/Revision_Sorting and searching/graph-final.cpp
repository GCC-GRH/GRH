#include<iostream>
#include<list>
#include<queue>
#include<algorithm>
#include<set>
using namespace std;

class sortedQueue {
    std::multiset<pair<int,int>> s;
public:
    void push(pair <int,int> val) {
        s.insert(val);
    }

    void pop() {
        if (s.empty()) {
            cout << "empty\n";
            return;
        }
        s.erase(s.begin());
    }

    pair<int,int> seek() const {
        if (s.empty()) {
            cout << "Empty, cannot\n";
            return {-1,-1};
        }
        return *s.begin();
    }

    bool isEmpty() const {
        return s.empty();
    }

    int size(){
        return s.size();
    }
};

class graph{
    list <int> *l;
    list <pair<int,int>> *weigh = NULL;
    int vertices;
    int build_state = -1;

    void dfs_stackcall(int source, bool visited[]){
        cout<<source<<" ";
        visited[source] = true;
        for(int i : l[source]){
            if(!visited[i]){
                dfs_stackcall(i, visited);
            }
        }
    }


    void cycle_stackcall(int source, bool visited[], int parent[]){
        visited[source] = true;
        for(int i : l[source]){
            if(!visited[i]){
                parent[i] = source;
                visited[i] = true;
                cycle_stackcall(i,visited, parent);
            }else{
                if(i != parent[source]){
                    cout<<"Cycle detected in the graph!"<<endl;
                    return;
                }
            }
        }
    }

    public:
    graph(int v){
        vertices = v;
        l = new list<int>[vertices];
    }

    void addedge(int u, int v){
        if(build_state == 1){
            cout<<"Cannot add edge in an Weighted graph"<<endl;
            return;
        }
        build_state = 0;
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void addwedge(int u, int v, int w){
        if(build_state == 0){
            cout<<"Cannot add edge in an unweighted graph"<<endl;
            return;
        }
        build_state = 1;
        if(weigh == NULL) weigh = new list <pair<int,int>>[vertices];
        weigh[u].push_back({w,v});
        weigh[v].push_back({w,u});
    }


    void bfs(){
        bool *visited = new bool[vertices];
        for(int i = 0; i<vertices; i++) visited[i] = false;
        queue<int> q;
        for(int i = 0; i<vertices;i++){
        if(visited[i]) continue;
        q.push(i);
        visited[i] = true;
        while(!q.empty()){
            int dat = q.front();
            q.pop();
            cout<<dat<<" ";
            for(int j : l[dat]){
            if(!visited[j]){
                q.push(j);
                visited[j] = true;
            }
        }
        }
    }
        delete[] visited;
    }

    void dfs(){
        bool *visited = new bool[vertices];
        for(int i = 0; i<vertices; i++) visited[i] = false;
        for(int i = 0; i<vertices; i++){
            if(visited[i] == true) continue;
            dfs_stackcall(i, visited);
        }
        delete[] visited;
    }

    void cycle(){
        bool *visited = new bool[vertices];
        int *parent = new int[vertices];
        for(int i = 0; i<vertices; i++) visited[i] = false;
        for(int i = 0; i<vertices; i++) parent[i] = -1;
        for(int i = 0; i<vertices; i++){
            if(visited[i]) continue;
            cycle_stackcall(i, visited, parent);
        }

        delete[] visited;
        delete[] parent;
    }


    void printg(){
        for(int i = 0; i<vertices; i++){
            cout<<i<<" : ";
            if(build_state == 0){
            for(int j : l[i]){
                cout<<j<<" ";
            }
            }else if(build_state == 1){
                for(pair<int,int> j : weigh[i] ){
                    cout<<"( "<<j.first<<","<<j.second<<" )";
                }
            }
        
            cout<<endl;
        }
    }

    void primst(){
        int minCost;
        bool *visited = new bool[vertices];
        for(int i = 0; i<vertices; i++) visited[i] = false;
        sortedQueue q;
        q.push({0,0});
        minCost = 0;
        while(q.size() > 0){
            pair<int,int> dat = q.seek();
            int wt = dat.first;
            int u = dat.second;
            q.pop();

            if(!visited[u]){
                visited[u] = true;
                minCost += wt;
                for(pair<int,int> i : weigh[u]){
                    int v = i.second;
                    int w = i.first;
                    if(visited[v]) continue;
                    q.push({w,v});
                }

            }
        }

        cout<<endl<<"The minimum spanning tree is bearing minCost of "<<minCost;
        delete[] visited;

    }
};



