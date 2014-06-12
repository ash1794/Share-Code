#include<bits/stdc++.h>

using namespace std;

#define MAX_N 1050000

int skill_level[MAX_N];     
int seg_tree[2*MAX_N];      //4 Times the MAX_N since this stores our segment Tree.


//The Segment tree here stores the "index" of the maximum skill
//Each node contains in that range or sub-tree which index has the maximum value
void build(int node,int tl,int tr)
{
    //TL and TR are ranges that we define. 
    //The build function assigns a unique id for each range. 
    //The root is assigned value 1
    //The children for each node will be 1<<node [Left Child] and (1<<node)+1 [Right Child]

    if(tl == tr)
    {
        //We've readched a leaf node
        seg_tree[node] = tl;
        return;
    }

    //Now we recurse over the left and right halves.
    int tm = (tl+tr)>>1;        //The middle element of the range.
    int cl = node<<1;           //The left Child
    int cr = cl|1;              //The right Child

    build(cl,tl,tm);            //Left Range is always (tl,tm)
    build(cr,tm+1,tr);          //And the right is always (tm+1,tr)

    //Once the recursion returns, we know the current node's children
    //is populated and we can populate current node accordingly.

    if(skill_level[seg_tree[cl]] > skill_level[seg_tree[cr]])
        seg_tree[node] = seg_tree[cl];
    else
        seg_tree[node] = seg_tree[cr];
}

int query(int node,int tl,int tr,int ind,int lvl)
{
    //All segment trees have node, tl and tr to identify the range and it's unique id.
    //The Node value is always implicitly calculated in the recursion.

    if(seg_tree[node]==ind)     //If my current node has the same index i'm searching
        return lvl;             //I've won 'lvl' matches.
    
    int tm = (tl+tr)>>1;        //The middle element of the range.
    int cl = node<<1;           //The left Child
    int cr = cl|1;              //The right Child

    if(ind > tm)                //If index lies in the right range (tm+1,tr) we go right.
        return query(cr,tm+1,tr,ind,lvl-1);
    else                        //Else go left.
        return query(cl,tl,tm,ind,lvl-1);
}

void update(int node,int tl,int tr,int ind,int val)
{
    //To update a single element we need the index and the value.
    if(tl==tr and tl==ind)
    {
        skill_level[ind]=val;
        return;
    }
    int tm = (tl+tr)>>1;        //The middle element of the range.
    int cl = node<<1;           //The left Child
    int cr = cl|1;              //The right Child

    if(ind > tm)                //If index lies in the right range (tm+1,tr) we go right.
        update(cr,tm+1,tr,ind,val);
    else                        //Else go left.
        update(cl,tl,tm,ind,val);
    
    if(skill_level[seg_tree[cl]] > skill_level[seg_tree[cr]])
        seg_tree[node] = seg_tree[cl];
    else
        seg_tree[node] = seg_tree[cr];

}

char getmychar()
{
    char ch = getchar_unlocked();
    if(ch=='R' or ch=='W' or ch=='S')
        return ch;
    return getmychar();
}

int main()
{
    int n,q,max_rounds;
    scanf("%d %d",&n,&q);
    max_rounds=n;
    n = (1<<n);
    for(int i=1;i<=n;i++)
        scanf("%d",&skill_level[i]);
    build(1,1,n);

    int ind,val;
    for(int i=1;i<=q;i++)
    {
        int chk=-1;
        char ch = getmychar();
        if(ch=='R')
            chk = 0;
        if (ch=='W')
            chk = 1;
        if (ch=='S')
            chk = 2;
        if(chk==0)
        {
            scanf("%d",&ind);
            scanf("%d",&val);
            update(1,1,n,ind,val);
        }
        else if(chk==1)
        {
            printf("%d\n", seg_tree[1]);
        }
        else if(chk==2)
        {
            scanf("%d",&ind);
            printf("%d\n",query(1,1,n,ind,max_rounds) );
        }
    }
    return 0;
}