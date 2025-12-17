// https://cses.fi/problemset/task/1640

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    map<ll,ll> mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]] = i+1;
    }
    for(int i=0;i<n;i++)
    {
        if(mp[x-a[i]] && mp[x-a[i]] != i+1)
        {
            cout<<i+1<<" "<<mp[x-a[i]]<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}