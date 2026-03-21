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

void dijkstra(vector<vector<Edge>>& g, int V, int src) {
vector<int> dist(V, INT_MAX);
dist[src] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pd;
  pd.push({0, src});

  while(!pd.empty()) {
    int u = pd.top().second;
    // int d = pd.top().first;
    pd.pop();

    // if (d > dist[u]) continue;

    for ( Edge e : g[u]) {
      int v = e.V;
      int wt = e.wt;

      if (dist[u] + wt < dist[v]) {
        dist[v] = dist[u] + wt;
        pd.push({dist[v], v});
      }
    }
  }

  for(int i = 0; i < V; i++) {
    cout << "Distance from source " << src << " to vertex " << i << " is: " << dist[i] << endl;
  }
  cout<<endl; 

}

int main(){
    int V = 6;
    vector<vector<Edge>> ad(V);
    ad[0].push_back(Edge(1,2));
    ad[0].push_back(Edge(2,4));
    ad[1].push_back(Edge(2,1));
    ad[1].push_back(Edge(3,7));

    ad[2].push_back(Edge(4,3));

    ad[3].push_back(Edge(5,1));

    ad[4].push_back(Edge(3,2));
    ad[4].push_back(Edge(5,5));


}