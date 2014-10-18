#include<bits/stdc++.h>

using namespace std;

#define MAX_N 100100
#define ll long long
ll freq[MAX_N];
int vis[MAX_N];
void update(int i){
    while(i<MAX_N){
        freq[i] += 1;
        i+= i&-i;
    }
}

ll read(int i){
    ll sum=0;
    while(i>0){
        sum+=freq[i];
        i-= i&-i;
    }
    return sum;
}

int main()
{
    int t;
    cin>>t;
    int cas_no=1;
    while(t--)
    {
        bool repeat = false;
        int n,temp,k;
        cin>>n>>k;
        vector<int> arr;
        memset(vis,0,sizeof vis);
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(temp);
            if(vis[temp])
                repeat=true;
            vis[temp]=1;
        }
        memset(freq,0,sizeof freq);
        long long ans = 0;
        for(int i=0;i<n;i++)
        {
            update(arr[i]);
            ans+= read(arr[i]);
        }
        long long N = n;
        ll ret= (long long) N;
        ret*= (N+1);
        ret/=2;
        ret-=ans;
        if(ret < k)
        {
            long long left = k - ret;
            if(left % 2 == 1 and !repeat)
                ret = 1;
            else
                ret = 0;
        }
        else
        {
            ret-=k;
        }
        cout<<"Case "<<cas_no++<<": "<<ret<<"\n";
    }
    return 0;
}