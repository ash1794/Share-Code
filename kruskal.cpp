/*This program demonstrates the prowess of the Standard Template Library in C++. If looked carefully, here C++ resembles Java in efficient usage of classes. The Kruskal algorithm, implemented below, finds the minimum spanning tree. A minimum spanning tree is one which connects all the vertices with minimum edge cost. 
The algorithm takes place in 3 steps:
1. The edges are sorted in the order of weights.
2. Each edge is processed to check if the vertices are already in the tree.
3. The edge costs included are added to return the minimum cost.
*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<utility>
#include<string>
#define MAX 10001
#define edge pair<int,int>
using namespace std;
vector< pair< int, edge> > Graph,MST;
int n,e,p,parent[MAX];
void init(int n)
{
    for(int i=0;i<n;i++)
        parent[i]=i;
    Graph.clear();
    MST.clear();    
}
int findSet(int x,int *parent)
{
    if(x!=parent[x])
        parent[x]=findSet(parent[x],parent);
    return parent[x];
}
void kruskal()
{
    sort(Graph.begin(),Graph.end());
    long long tot=0;
    for(int i=0;i<e;i++)
    {
        int pu=findSet(Graph[i].second.first,parent);
        int pv=findSet(Graph[i].second.second,parent);
        if(pu!=pv)
        {
            tot+=Graph[i].first;
            MST.push_back(Graph[i]);
            parent[pu]=parent[pv];
        }
    }
    printf("%lld\n",tot);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>e;
        init(n);
        int u,v,w;
        for(int i=0;i<e;i++)
        {
            cin>>u>>v>>w;
            Graph.push_back(pair<int, edge>(w,edge(u,v)));
        }
        kruskal();
        
        for(int i=0;i<(int)MST.size();i++)
          cout<<MST[i].second.first<<" "<<MST[i].second.second<<" "<<MST[i].first<<endl;
    }
    return 0;
}
// //sai16vicky