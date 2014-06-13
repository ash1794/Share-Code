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

#define MAX_N 100100


struct SuffixArray3 {
  const int L;
  string s;
  vector<vector<int> > P;
  vector<pair<pair<int,int>,int> > M;
  vector<int> pos;
  int level;
  SuffixArray3(const string &s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) ,pos(L),level(1){
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    
    for (int skip = 1; skip < L; skip *= 2, level++) {
      P.push_back(vector<int>(L, 0));
      for (int i = 0; i < L; i++) 
    M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
      sort(M.begin(), M.end());
      for (int i = 0; i < L; i++) 
    P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
    }
    for (int i = 0;i < L;i++)
        pos[P[level-1][i]]=i;
  }
  int lower_bound(int lo,int hi,char ch,int i)
  {
    int count = hi-lo+1 , step,mid;

    while(count>0)
    {
        step = count/2;
        mid = lo + step;
        if(s[P[level-1][mid]+i] < ch)
        {
            lo = ++mid;
            count-= step+1;
        }
        else
        {
            count=step;
        }
    }
    return lo;
  }

  int higer_bound(int lo,int hi,char ch,int i)
  {
    int count = hi-lo+1 , step,mid;

    while(count>0)
    {
        step = count/2;
        mid = lo + step;
        if(!(s[P[level-1][mid]+i] < ch))
        {
            lo = ++mid;
            count-= step+1;
        }
        else
        {
            count=step;
        }
    }
    return lo;
  }
    int  find(string needle)
    {
        int lo = 0,hi = L-1;
        for(int i = 0;i < L;i++)
        {
            lo = lower_bound(lo,hi,needle[i],i);
            hi = higer_bound(lo,hi,needle[i],i);
        }
        deb(lo,hi);
        if(lo<=hi)
            return hi-lo+1;
        return -1;
    }
  vector<int> GetSuffixArray() { return P.back(); }

  // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
  int LongestCommonPrefix(int i, int j) {
    int len = 0;
    if (i == j) return L - i;
    for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
      if (P[k][i] == P[k][j]) {
    i += 1 << k;
    j += 1 << k;
    len += 1 << k;
      }
    }
    return len;
  }
};
vector<int> suffixArray2(const string &s)
{
    const int L = s.size();
    vector<vector<int> > P(1,vector<int>(L,0));
    vector<pair<pair<int,int>,int> > M(L);
    for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
    for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
        P.push_back(vector<int>(L, 0));
        for (int i = 0; i < L; i++) 
            M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
        sort(M.begin(), M.end());
        for (int i = 0; i < L; i++) 
            P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
        
    }
    return P.back();

}
vector<int> suffixArray(const string &s)
{
    const int L = s.size();
    vector<vector<int> > P(1,vector<int>(L,0));
    vector<pair<pair<int,int>,int> > M(L);
    
    for(int i=0;i<L;i++)
        P[0][i]=int(s[i]);
    for(int j=1,k=1;k<L;j++,k*=2)
    {
        P.push_back(vector<int>(L,0));
        for(int i=0;i<L;i++)
            M[i]=make_pair(make_pair(P[j-1][i], (i+k < L ? P[j-1][i+k]:-1000) ),i);
        sort(M.begin(), M.end());
        for(int i=0;i<L;i++)
            P[j][M[i].second] = (i>0 and M[i].first==M[i-1].first) ? P[j][M[i-1].second]:i;

    }
    return P.back();
}
int main()
{
    string s;
    cin>>s;
    vector<int> sa;
    SuffixArray3 ab(s);
    sa = ab.GetSuffixArray();
    for (int i=0;i<sa.size();i++)
    {
        cout<<sa[i]<<" ";
    }
    cout<<"\n";
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string find;
        cin>>find;
        cout<<ab.find(find)<<"\n";
    }
    return 0;
}