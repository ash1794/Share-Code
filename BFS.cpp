#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n,e,a,b;
    //n is the number of Nodes
    //e is the number of edges
    cin>>n>>e;
    vector<int> adj_list[n+1];
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int start,end;
    cin>>start>>end;

    //BFS Starts Here
    vector<int> visited(n+1,0); //Vector of size n+1 
    queue<int> q;

    q.push(start);
    visited[start]=1;           //Push the first element and mark it visited
    
    while(!q.empty())
    {
        int cur = q.front();q.pop();    //We are at cur

        for(int i=0;i<adj_list[cur].size();i++)     //Check for cur's neighbours.
        {
            //cur adj_list[cur][i]
            if(!visited[adj_list[cur][i]])          //If it's unprocessed push it to queue.
            {
                q.push(adj_list[cur][i]);
                visited[adj_list[cur][i]]=1;
            }
        }
    }

    //Finally Check if it's visited.
    if(visited[end])
        cout<<"Path Exists";
    else
        cout<<"Path Doesn't exist";
    return 0;
}