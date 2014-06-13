#include<iostream>
#include<string.h>
#include<cassert>
#include<vector>

using namespace std;

#define MAX_N 100100
typedef long long ll;

int n;
int p[MAX_N],pn[MAX_N];
//int cnt[MAX_N];
int c[20][MAX_N];
string str;
int t,w,csize,i1,i2,x,y,cur,i,k,h;
void input()
{
	cin>>str;
	n=str.size();
}
int main()
{
	
	cin>>t;
	
	while(t--)
	{
		input();
		//memset(cnt,0,sizeof cnt);
		vector<int> cnt;
		cnt.resize(300);
		for(i=0;i<n;i++)
			cnt[int(str[i])]++;

		for(i=1;i<300;i++)
			cnt[i]+=cnt[i-1];
		memset(p,0,sizeof p);
		for(i=0;i<n;i++)
		{
			p[--cnt[int(str[i])]]=i;
		}
		memset(c,0,sizeof c);
		w = 1;
		c[0][p[0]]=0;
		for(i=1;i<n;i++)
		{
			if(str[p[i]]!=str[p[i-1]]) w++;
			c[0][p[i]] = w-1;
		}
		csize=0;
		for(k=0,h=1;h<n;k++,h*=2)
		{
			memset(pn,0,sizeof pn);
			for(i=0;i<n;i++)
			{
				pn[i]= p[i] - h;
				while(pn[i]<0) pn[i]+=n;
			}
			
			//memset(cnt,0,sizeof cnt);
			cnt.clear();
			cnt.resize(w);
			for(i=0;i<n;i++)
				cnt[c[k][pn[i]]]++;
			for(i=1;i<w;i++)
				cnt[i]+=cnt[i-1];
			for(i=n;i--;)
				p[--cnt[c[k][pn[i]]]]=pn[i];
			w=0;
			//c.push_back( vector<int>(n));
			for(i=0;i<n;i++)
			{
				if(i==0 || c[k][p[i]] != c[k][p[i-1]]) {
					w++; 
				} else {
					i1 = p[i]   + h; while(i1>=n) i1-=n;
					i2 = p[i-1] + h; while(i2>=n) i2-=n;
					if(c[k][i1]!=c[k][i2]) w++;
				}
				c[k+1][p[i]] = w-1;
			}
			csize=k+1;
		}
		ll ans = ll(n)*(n+1)/2;
		
		for(k=1;k<n;k++)
		{
			x=p[k];
			y=p[k-1];
			cur = 0;
			for (h=csize; h--;)
				if (c[h][x] == c[h][y]) {
					cur += 1<<h;
					x += 1<<h;
					y += 1<<h;

				}
			ans-=cur;
		}
		cout<<ans<<"\n";
	}
	return 0;
}