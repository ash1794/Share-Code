#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
bool comp(const pair<double,double>& a,const pair<double,double>& b)
{
    return ((a.x*a.x)+(a.y*a.y))>((b.x*b.x)+(b.y*b.y));
}

double dist(pair<double,double> a,pair<double,double> b)
{
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
#undef x
#undef y
main()
{
    int t;
    cin>>t;
    int cas_no = 1;
    while(t--)
    {
    int n;
    double x,y;
    scanf("%d",&n);
    vector< pair<double,double> > p;
    for(int i=0;i<n;i++)
    {
        scanf("%lf %lf",&x,&y);
        p.push_back(make_pair(x,y));
    }
    //sort(p.begin(),p.end(),comp);
    double ans=1e21;
    for(int a=0;a<=1e6;a++)
    {
        int i = rand()%n,j=rand()%n,k=rand()%n;
        if(i!=j and j!=k and k!=i)
        {
            ans = min(ans,dist(p[i],p[j])+dist(p[k],p[j])+dist(p[i],p[k]));
            //cout<<p[i].first<<" "<<p[i].second<<" "<<p[j].first<<" "<<p[j].second<<" ";
            //cout<<p[k].first<<" "<<p[k].second<<" ";
            //cout<<(dist(p[i],p[j])+dist(p[k],p[j])+dist(p[i],p[k]))<<"\n";
        }
        //ans = min(ans,dist(p[0],p[1])+dist(p[0],p[2])+dist(p[1],p[2]));
    }
    //ans = sqrt(ans);
    printf("Case %d: ",cas_no++);
    printf("%.9lf\n",ans);
    }

}