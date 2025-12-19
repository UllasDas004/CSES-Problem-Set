// https://cses.fi/problemset/task/11163
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll x,n;
    cin>>x>>n;
    set<ll> pos;
    multiset<ll> len;
    pos.insert(0);
    pos.insert(x);
    len.insert(x);
    vector<ll> ans(n);
    for(int i=0;i<n;i++)
    {
        ll p;
        cin>>p;
        auto right = pos.upper_bound(p);
        auto left = right;
        left--;
        ll l = *left,r = *right;
        len.erase(len.find(r-l));
        len.insert(p-l);
        len.insert(r-p);
        ans[i] = *len.rbegin();
        pos.insert(p);
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}