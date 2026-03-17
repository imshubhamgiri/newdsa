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
        ad[v].push_back(u);  // for directed graph
    }

    bool dfs(int u ,vector<bool>& vist,vector<bool>& recStack){
         recStack[u] = true;
        vist[u] = true;

        for(int v: ad[u]){
            if(!vist[v]){
                if(dfs(v , vist,recStack)){
                    return true;
                }
            }
            else if(recStack[v]){
                return true;
            }
        }
        recStack[u] = false;
        return false;
    }

    bool isCyclic(){
        vector<bool> vist(V,false); 
        vector<bool> recStack(V,false);
        for(int i=0;i<V;i++){
            if(!vist[i]){
                if(dfs(i,vist,recStack)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
  Graph G(5);
  G.addEdge(1,0);
  G.addEdge(0,2);
    G.addEdge(2,3);
    G.addEdge(3,0);
  cout << G.isCyclic() << endl;
    return 0;
}