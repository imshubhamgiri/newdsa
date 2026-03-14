#include<iostream>
#include<list>
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

    void PrintList(){
        for(int i=0 ; i<V; i++ ){
            cout<<i<<" : ";
            for(int neigh: ad[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
        cout<<"Print Done";
    }
};

int main(){
  Graph G(5);
  G.addEdge(0,1);
  G.addEdge(1,2);
  G.addEdge(1,3);
  G.addEdge(2,3);
  G.addEdge(2,4);

  G.PrintList();

}