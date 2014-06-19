#include<bits/stdc++.h>

using namespace std;

int graph[60][60];
int rgraph[60][60];

int ford(int s,int t)
{
    for(int i=0;i<52;i++)
        for(int j=0;j<52;j++)
            rgraph[i][j]=graph[i][j];

    int max_flow = 0;

    bool path_exists = true;

    while(path_exists)
    {
        queue<int> q;
        vector<int> par(55,-1);
        vector<int> visited(55,0);
        q.push(0);
        visited[0]=1;
        while(!q.empty())
        {
            int cur = q.front();q.pop();
            if(cur==t)
                break;
            for(int i=0;i<52;i++)
            {
                if(visited[i]==false and rgraph[cur][i] > 0)
                {
                    q.push(i);
                    visited[i]=1;
                    par[i]=cur;
                }
            }
        }
        if(!visited[t])
        {
            path_exists=false;
            break;
        }
        int path_flow = INT_MAX;
        for(int v = t; v!=s ; v=par[v])
        {
            path_flow = min(path_flow,rgraph[par[v]][v]);
        }
        for(int v = t; v!=s ; v=par[v])
        {
            rgraph[par[v]][v] -= path_flow;
            rgraph[v][par[v]] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}
int nodeid(char ch)
{
    if(ch>='a' and ch<='z')
        return ch-'a'+26;
    return ch-'A';
}
int main()
{
    int e;
    cin>>e;
    char sr,ds;
    int flow;
    for(int i=0;i<e;i++)
    {
        cin>>sr>>ds>>flow;
        graph[nodeid(sr)][nodeid(ds)]+=flow;
    }
    cout<<ford(nodeid('A'),nodeid('Z'))<<"\n";
    return 0;
}
