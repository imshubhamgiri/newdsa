#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;


class Graph{
    public:
    int V;
    list<pair<int,int>> *ad;
    Graph(int V){
        this->V = V;
        ad = new list<pair<int,int>>[V];
    }
    void addEdge(int v,int u,int w){
        ad[v].push_back({u,w});
        ad[u].push_back({v,w});     
    }

    
    int Prim(){
    vector<bool>inmst(V ,false);
    priority_queue<pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq;
    pq.push({0,0});
    int mstCost = 0;

    while(pq.size()>0){
        pair<int,int> p = pq.top();  //can use auto p instead of pair<int,int> p
        int w = p.first;
        int u = p.second;
        pq.pop();

        if(!inmst[u]){
            inmst[u] = true;
            mstCost += w;    
            for(pair<int,int> x: ad[u]){
                int v = x.first;
                int w = x.second;
                if(!inmst[v])
                 pq.push({w,v});
                
            }
        }
    }   
    return mstCost;
}


};

int main(){
    Graph G(4);
    G.addEdge(0,1,10);
    G.addEdge(0,2,15);
    G.addEdge(0,3,30);
    G.addEdge(2,3,50);
    G.addEdge(1,3,40);

    cout<<G.Prim()<<endl;

}