#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;

class Graph{

    int V;
    list<int> *ad;

    public:
    Graph(int V){
    this->V = V;
    ad = new list<int>[V];
    }

    void addList(int v , int u){
        ad[u].push_back(v);
    }

    vector<int> topoSort(){
        vector<int>indegree(V,0);
        for(int i=0; i<V; i++){
            for(int v: ad[i]){
                indegree[v]++;
            }
        }
        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for(int v: ad[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return topo;
    }

};

int main(){
    Graph g(6);
    g.addList(3,1);
    g.addList(4,1);
    g.addList(4,0);
    g.addList(2,3);
    g.addList(5,0);
    g.addList(5,2);

    vector<int> result = g.topoSort();
    for(int v: result){
        cout<<v<<" ";
    }
    cout<<""<<endl;
    return 0;
}
