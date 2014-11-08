#include<bits/stdc++.h>

using namespace std;

vector<int> adj_list[110];
int visited[110];
void dfs(int node)
{
    visited[node]=1;
    for(int i=0;i<adj_list[node].size();i++)
    {
        dfs(adj_list[node][i]);
    }
}

int visited[55][55];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int dfs(int x,int y)
{
    visited[newx][newy] = -1;
    int ret = 0;
    for(int i=0;i<4;i++)
    {
        int newx = x+dx[i];
        int newy = y+dy[i];
        if(newx<0 or newy<0 or newx>=n or newy>=n)
            continue;
        if(graph[newx][newy]=='X')
            continue;
        if(visited[newx][newy]==0)
            ret = max(ret,dfs(newx,newy));
        else if(visited[newx][newy]==-1)
            retur 
    }
    ret+=1;
    visited[newx][newy]=1;
    return ret;
}
int main()
{
    int n,e,a,b;
    //n is the number of Nodes
    //e is the number of edges
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int start,end;
    cin>>start>>end;
    memset(visited,0,sizeof visited);

    

    //Finally Check if it's visited.
    if(visited[end])
        cout<<"Path Exists";
    else
        cout<<"Path Doesn't exist";
    return 0;
}