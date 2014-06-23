#include<bits/stdc++.h>
using namespace std;
#define ll long long
//Solving for the problem GEEKOUNT IN spoj
//Edit the state variables as neccesary for your dp.

ll dp[20][20][20],res[20];
int len;
ll doit(int pos,int odd,int even)
{
	if(pos==len)
	{
		return (even>0)?1:0;
	}
	ll &ret = dp[pos][odd][even];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=(pos==0)?1:0;i<=9;i++)
		ret+=doit(pos+1,odd+(i%2==1),even+(i%2==0));
	return ret;
}

ll solve(ll x)
{

	if(x<=0)
		return 0;
	char buf[20];
	sprintf(buf,"%lld",x);
	ll ans=0;

	int n=strlen(buf);
	len =n;
	for(int i=1;i<n;i++)ans+=res[i];
	for(int i=0;i<n;i++)
	{
		int odd=0,even=0;
		for(int j=0;j<i;j++)
		{
			odd+=((buf[j]-'0')%2==1);
			even+=((buf[j]-'0')%2==0);
		}
		for(int j=(i==0)?1:0;j<buf[i]-'0';j++)
		{
			memset(dp,-1,sizeof dp);
			ans+=doit(i+1,odd+(j%2==1),even+(j%2==0));
		}
		if(i==n-1)
		{
			odd+=((buf[i]-'0')%2==1);
			even+=((buf[i]-'0')%2==0);
			if(even>0)
				ans++;
		}
	}
	return ans;

}
int main()
{
	memset(res,0,sizeof res);
	for(int i=1;i<=17;i++)
	{
		len=i;
		memset(dp,-1,sizeof dp);
		res[i]=doit(0,0,0);
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		cout<<solve(b)-solve(a-1)<<"\n";
	}
	return 0;
}