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

    bool hasCycle(int src , int par , vector<bool>& vist){
        vist[src] = true;
        list<int> neighbour = ad[src];
        for(int v: neighbour){
            if(!vist[v]){
              if(  hasCycle(v , src , vist)){
                return true;
            }
        }else if(v!= par){
          return true;
        }
        }
       return false;
    }

    bool dfs(int u ,vector<bool>& vist , int& parent){
        vist[u] = true;
        // cout<<u<<" ";

        for(int v: ad[u]){
            if(!vist[v]){
                parent = u;
              if(dfs(v , vist , parent)) {  // Remove 'return'
            return true;
               }
            }else if(v!=parent){
                return true;
            }
        }
        return false;
    }

    void d(){
        int src =0;
    vector<bool> vist(5,false); 
    int parent = -1;
    if(dfs(src,vist ,parent )){
        cout<<"Cycle exist"<<endl;
    }else{
        cout<<"No Cycle exist"<<endl; 
    }
    }

    bool cycle(){
        vector<bool> vist(V,false); 
        for(int i=0; i<V ; i++){
            if(!vist[i]){

                if(hasCycle(i , -1 , vist )){
                    return true;
                }
            }
        }
        return false;
        //This loop is used in case graph has some isolated Nodes which isn't connected to any node 
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
  cout<<G.cycle()<<endl;

}