#include<bits/stdc++.h>

using namespace std;

vector<pair<int,string> > arr;

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
}
int main()
{
    int n;
    cin>>n;
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

        print(arr.begin(),arr.end());
        cout<<"\n";
        cin>>n;
    }
    return 0;
}