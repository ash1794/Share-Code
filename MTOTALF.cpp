#include<bits/stdc++.h>

using namespace std;

int graph[60][60];
int rgraph[60][60];

const bool debug = false;
int ford(int maxv,int s,int t)
{
    for(int i=1;i<maxv;i++)
        for(int j=1;j<maxv;j++)
            rgraph[i][j]=graph[i][j];

    int max_flow = 0;

    bool path_exists = true;

    while(path_exists)
    {
        

        queue<int> q;
        vector<int> par(60,-1);
        vector<int> visited(60,0);
        q.push(s);
        visited[s]=1;
        while(!q.empty())
        {
            int cur = q.front();q.pop();

            if(debug)cout<<cur<<" ";
            if(cur==t)
                break;
            for(int i=0;i<maxv;i++)
            {
                if(visited[i]==false and rgraph[cur][i] > 0)
                {
                    q.push(i);
                    visited[i]=1;
                    par[i]=cur;
                }
            }
        }
        if(debug)cout<<"\n";
        if(!visited[t])
        {
            path_exists=false;
            break;
        }
        int path_flow = INT_MAX;
        for(int v = t; v!=s ; v=par[v])
        {
            if(debug)cout<<v<<" ";
            path_flow = min(path_flow,rgraph[par[v]][v]);
        }
        if(debug)cout<<": "<<path_flow<<" ";
        for(int v = t; v!=s ; v=par[v])
        {
            rgraph[par[v]][v] -= path_flow;
            rgraph[v][par[v]] += path_flow;
        }
        if(debug)cout<<", Max_Flow = "<<max_flow<<"\n";
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    //cout<<nodeid('Z')<<" "<<nodeid('a')<<" "<<nodeid('z')<<"\n";
    int e;
    cin>>e;
    char sr,ds;
    int flow;
    int nodeid = 1;
    map<char,int> nodemap;
    for(int i=0;i<e;i++)
    {
        cin>>sr>>ds>>flow;
        if(!nodemap[sr])
            nodemap[sr]=nodeid++;
        if(!nodemap[ds])
            nodemap[ds]=nodeid++;

        graph[nodemap[sr]][nodemap[ds]]=flow;
    }
    cout<<ford(nodeid,nodemap['A'],nodemap['Z'])<<"\n";
    return 0;
}