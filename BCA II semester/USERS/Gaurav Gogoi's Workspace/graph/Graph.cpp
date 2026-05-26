#include<iostream>
#include<list>
using namespace std;

class graph{
    int vertices;
    list <int> *l; // A linked list in which every data node is a pointer
    public:
    graph(int v){
        vertices = v;
        l = new list<int>[vertices];
    }

    void addEdge(int v, int u){
        l[u].push_back(v);
        l[v].push_back(u);
    };
    void printgraph(){
        for(int i = 0; i<vertices; i++){
            cout<< i <<" : ";
            for(int neigh : l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.printgraph();
}