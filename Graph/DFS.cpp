#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph{
  int V;
  list<int> *ad;
  public:
    Graph(int V){
        this->V = V;
        ad=new list<int>[V];
    }
    void addEdge(int v,int u){
        ad[v].push_back(u);
        ad[u].push_back(v);
    }

    void dfs(int u ,vector<bool>& vist){
        vist[u] = true;
        cout<<u<<" ";

        for(int v: ad[u]){
            if(!vist[v]){
                dfs(v , vist);
            }
        }
    }

    void d(){
        int src =0;
    vector<bool> vist(5,false); 
    dfs(src,vist);
    }
};

int main(){
  Graph G(5);
  G.addEdge(0,1);
  G.addEdge(1,2);
  G.addEdge(1,3);
//   G.addEdge(2,3);
  G.addEdge(2,4);

  vector<bool> vist(5,false);

  G.d();
  cout<<endl;



}