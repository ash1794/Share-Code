#include<bits/stdc++.h>

using namespace std;
#define MAX_N 50010
#define CHILDREN int tm = (tl+tr)>>1; \
                    int cl = node<<1; \
                    int cr = cl|1

vector<pair<int,string> > arr;

int segTree[4*MAX_N];
int N;
void build(int node,int tl,int tr)
{
    if(tl == tr)
    {
        segTree[node]=tl;
        //cout<<node<<" "<<tl<<" "<<tr<<" "<<segTree[node]<<"\n";
        return;
    }
    CHILDREN;
    build(cl,tl,tm);
    build(cr,tm+1,tr);
    
    //cout<<node<<" "<<tl<<" "<<tr<<"$\n";
    //cout<<cl<<" "<<segTree[cl]<<" "<<cr<<" "<<segTree[cr]<<"\n";
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
    cout<<"(";
    print(lo,ind-1);
    cout<<arr[ind].second<<"/"<<arr[ind].first;
    print(ind+1,hi);
    cout<<")";
}
/*
void print(vector<pair<int,string> >::iterator begin,vector<pair<int,string> >::iterator end)
{
    if(begin==end)
        return;
    vector<pair<int,string> >::iterator cur = max_element(begin,end);
    cout<<"(";
    print(begin,cur);
    cout<<cur->second<<"/"<<cur->first;
    print(cur+1,end);
    cout<<")";
}*/
int main()
{
    int n;
    cin>>n;
    N=n;
    while(n)
    {
        string str;
        arr.clear();
        for(int i=0;i<n;i++)
        {
            cin>>str;
            int j=0;
            string label;
            int pri=0;
            while(str[j]!='/')
                label+=str[j],j++;
            j+=1;
            while(j<(int)str.size())
            {
                pri*=10;
                pri+= (str[j]-'0');
                j++;
            }
            //a.insert(label,pri);
            arr.push_back(make_pair(pri,label));
        }
        build(1,0,n-1);
        print(0,n-1);
        //print(arr.begin(),arr.end());
        cout<<"\n";
        cin>>n;
    }
    return 0;
}