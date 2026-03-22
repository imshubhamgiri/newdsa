#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<list>
using namespace std;

class Edge{
    public:
    int V;
    int wt;
    Edge(int V , int wt){
        this->V = V;
        this->wt = wt;
    }
};

void BellmanFord(int src , vector<vector<Edge>>& g , int V){
    vector<int> dist(V , INT_MAX);
    dist[src] = 0;

    for(int i = 0 ; i < V-1 ; i++){
        for(int u = 0 ; u < V ; u++){
            for(Edge e : g[u]){
                int v = e.V;
                int wt = e.wt;

                if(dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    for(int i = 0 ; i < V-1 ; i++){
        cout << "Distance from source " << src << " to vertex " << i << " is: " << dist[i] << endl;
    }

}


int main(){
    int V = 6;
    vector<vector<Edge>> ad(V);
    ad[0].push_back(Edge(1,2));
    ad[0].push_back(Edge(2,4));
    ad[1].push_back(Edge(4,-1));
    ad[1].push_back(Edge(2,-4));

    ad[2].push_back(Edge(3,2));

    ad[3].push_back(Edge(4,4));;


    BellmanFord(0, ad, V);
}