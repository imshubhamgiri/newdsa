#include<iostream>
#include<list>
#include<vector>
#include<queue>
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
        queue<pair<int, int>>q;
        q.push({src, -1});
        vist[src] = true;
        while(q.size()>0){
            int front = q.front().first;
            par = q.front().second; 
            list<int> neighbour = ad[front];
            q.pop();
            for(int v: neighbour){
                if(!vist[v]){
                    q.push({v , front});
                    vist[v] = true;
                }else if(v!= par){
                    return true;
                }
            }
        }
            return false;
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
  G.addEdge(2,3);
  G.addEdge(2,4);

  vector<bool> vist(5,false);
  cout<<G.cycle()<<endl;

}