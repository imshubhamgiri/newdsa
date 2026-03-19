#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

class topological
{
 int V;
  list<int> *ad;
  public:
    topological(int V){
        this->V = V;
        ad=new list<int>[V];
    }
    void addEdge(int v,int u){
        ad[v].push_back(u);  // Directed graph
    }

void topo(int src , vector<bool>&vist ,stack<int>&s){
    if(vist[src]){
        return;
    }
   vist[src] = true;
   list<int> neight = ad[src];
   for(int v: neight){
    if(!vist[v]){
        topo(v , vist , s);
    }
   } s.push(src);
}

void t(){
    vector<bool> vist(V,false);
    stack<int>s;
     for(int i=0; i<V; i++){
        topo(i , vist ,s);
    }
    while(s.size()>0){
        cout<<s.top()<<" ";
        s.pop();
}

}

};

int main(){
  topological G(6);
  G.addEdge(5,2);
  G.addEdge(5,0);
  G.addEdge(4,0);
  G.addEdge(4,1);
  G.addEdge(2,3);
  G.addEdge(3,1);

  G.t();

  return 0;
 
}
