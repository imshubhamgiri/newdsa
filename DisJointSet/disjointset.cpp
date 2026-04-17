#include <iostream>
#include <vector>
using namespace std;

class Disjointset
{
    vector<int> parent, rank , size;

public:
    Disjointset(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUp(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = findUp(parent[u]);
    }

    void UnionByRank(int u, int v)
    {
        int ulp_u = findUp(u);
        int ulp_v = findUp(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void UnionBySize(int u, int v){
        int ulp_u = findUp(u);
        int ulp_v = findUp(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    Disjointset ds(7);
    ds.UnionBySize(1, 2);
    ds.UnionBySize(2, 3);
    ds.UnionBySize(4, 5);
    ds.UnionBySize(6, 7);
    ds.UnionBySize(5, 6);

        //check if 3 and 7 are in the same set before union
    if (ds.findUp(3) == ds.findUp(7))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }

    ds.UnionBySize(3, 7);  // Union the two sets containing 3 and 7

    if (ds.findUp(3) == ds.findUp(7))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }

    // cout << ds.findUp(4) << endl;
}
