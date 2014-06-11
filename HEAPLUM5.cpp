#include<bits/stdc++.h>

using namespace std;
#define MAX_N 50010
#define CHILDREN int tm = (tl+tr)>>1; \
                    int cl = node<<1; \
                    int cr = cl|1

vector<pair<int,char*> > arr;

int segTree[4*MAX_N];
int N;
void build(int node,int tl,int tr)
{
    if(tl == tr)
    {
        segTree[node]=tl;
        return;
    }
    CHILDREN;
    build(cl,tl,tm);
    build(cr,tm+1,tr);
    segTree[node] = (arr[segTree[cl]] > arr[segTree[cr]])?segTree[cl]:segTree[cr];
}

int query(int node,int tl,int tr,int l,int r)
{
    if(tl == l and tr==r)
        return segTree[node];
    CHILDREN;
    if(r<=tm)
        return query(cl,tl,tm,l,r);
    else if(l>tm)
        return query(cr,tm+1,tr,l,r);
    else
    {
        int lans = query(cl,tl,tm,l,tm);
        int rans = query(cr,tm+1,tr,tm+1,r);
        return (arr[lans]>arr[rans])?lans:rans;
    }
}

void print(int lo,int hi)
{
    if(lo>hi)
        return;
    int ind = query(1,0,N-1,lo,hi);
    printf("(");
    print(lo,ind-1);
    printf("%s/%d",arr[ind].second,arr[ind].first);
    print(ind+1,hi);
    printf(")");
}

int main()
{
    int n;
    scanf("%d",&n);
    N=n;
    while(n)
    {
        string str;
        arr.clear();
        for(int i=0;i<n;i++)
        {
            char str[100];
            scanf("%s",str);
            char *label = new char[60];
            int j=0,pri=0,k=0;
            while(str[j]!='/')label[k++]=str[j],j++;
            label[k]='\0';
            j++;
            while(str[j])
            {
                pri*=10;
                pri+= (str[j]-'0');
                j++;
            }
            arr.push_back(make_pair(pri,label));
        }
        build(1,0,n-1);
        print(0,n-1);
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}