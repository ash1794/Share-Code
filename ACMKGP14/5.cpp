#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int cas_no = 1;
    while(t--)
    {
        int n,temp;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.rbegin(), arr.rend());
        int ans = arr[0]+arr[1]+arr[2];
        cout<<"Case "<<cas_no++<<": "<<ans<<"\n";
    }
    return 0;
}