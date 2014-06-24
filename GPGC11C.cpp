#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cctype>
#include<cassert>
#include<climits>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<clocale>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>

//containers
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<complex>
#include<string>
#include<stack>
#include<bitset>
#include<istream>
#include<valarray>

//IOs
#include<iostream>
#include<sstream>
#include<iomanip>
#include<fstream>
#include<exception>
#include<ios>
#include<iosfwd>
#include<ostream>
#include<iterator>
#include<stdexcept>
#include<streambuf>


//algorithm & miscellaneous
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<limits>
#include<locale>
#include<memory>
#include<new>

#define MOD 1000000007
#define inf (long long) 1e18
#define iinf (int)1e9

using namespace std;
template<class T1> void deb(T1 e1){cout<<e1<<"\n";}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<"\n";}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<"\n";}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<"\n";}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<"\n";}
template<class T1,class T2,class T3,class T4,class T5,class T6>
void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<"\n";}

#define CHILDREN int tm = (tl+tr)>>1; \
					int cl = node<<1; \
					int cr = cl|1

#define MAX_N 10100
vector<int> graph[MAX_N];
int visited[MAX_N];
vector<int> ans;
bool loop=false;
int label;
//-1 visiting, 1-visited,0-not visited;
void dfs(int node)
{
	visited[node]=-1;
	//deb(node);
	for(int i=0;i<(int) graph[node].size();i++)
	{
		if(visited[graph[node][i]]==-1)
		{
			loop=true;
			return;
		}
		else if(!visited[graph[node][i]])
		{
			dfs(graph[node][i]);
		}
	}
	label++;

	visited[node]=1;
	ans.push_back(node);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,h;
		scanf("%d %d",&n,&h);
		label=0;
		for(int i=1;i<=n;i++)
			graph[i].clear();
		ans.clear();
		int a,b;
		for(int i=0;i<h;i++)
		{
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
		}
		memset(visited,0,sizeof visited);
		loop=false;
		for(int i=1;i<=n and !loop;i++)
		{
			if(!visited[i])
			{
				dfs(i);
			}
		}

		if(loop)
		{
			printf("recheck hints\n");
			continue;
		}
		bool missing=false;
		int sum=0;
		if(( (int) ans.size() )!=n)
			missing=true;
		label=0;
		memset(visited,0,sizeof visited);
		dfs(ans[n-1]);
		if(label!=n)
			missing=true;
		for(int i=0;i<n and !missing;i++)
			sum+=ans[i];
		sum-= ( n*(n+1))/2;
		if(sum)
			missing=true;
		if(missing)
		{
			printf("missing hints\n");
		}
		else
		{
			for(int i=n-1;i>=0;i--)
			{
				printf("%d",ans[i]);
				if(i)
					printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}