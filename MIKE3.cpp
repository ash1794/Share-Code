#include<bits/stdc++.h>

using namespace std;

int dp[21][1<<21];
int sz;
int arr[22][20100];
int graph[22][22];
int n,m;
int doit(int pos,int mask)
{
    if(pos==m)
        return 0;
    int &ret = dp[pos][mask];
    if(ret!=-1)
        return ret;
    ret=0;
    bool chk=true;
    for(int i=0;i<pos;i++)
    {
        if((1<<i)&mask)
            chk&=graph[pos][i];
    }
    if(chk)
        ret=max(ret,1+doit(pos+1,mask|(1<<pos)));
    ret=max(ret,doit(pos+1,mask));
    return ret;
}
int main()
{
    cin>>n>>m;
    int temp;
    for(int i=0;i<m;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
            cin>>temp,arr[i][temp]=1;
    }
    for(int i=0;i<m;i++)
    {
        for(int a=0;a<m;a++)
            graph[i][a]=1;
        graph[i][i]=0;
        
        for(int j=1;j<=n;j++)
        {
            if(!arr[i][j])
                continue;
            for(int a=0;a<m;a++)
            {
                if(graph[i][a] and arr[a][j])
                    graph[i][a]=0;
            }
        }
    }
    
    memset(dp,-1,sizeof dp);
    cout<<doit(0,0)<<"\n";
    return 0;
}