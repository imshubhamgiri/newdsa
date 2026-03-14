#include<iostream>
#include<queue>
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

    void Bfs(){
        vector<bool>vist(V,false);
        queue<int>Q;
        Q.push(0);
        vist[0] = true;

        while(Q.size()>0){
            int u = Q.front();
            cout<<u<<" ";
            Q.pop();
            for(int v: ad[u]){
                if(!vist[v]){
                    vist[v]= true; 
                    Q.push(v);
                }
            }
        }
        cout<<endl; 
    }
 
};

int main(){
  Graph G(5);
  G.addEdge(0,1);
  G.addEdge(1,2);
  G.addEdge(1,3);
  G.addEdge(2,3);
  G.addEdge(2,4);

  G.Bfs();
   
}