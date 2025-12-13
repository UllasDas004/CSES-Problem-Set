// https://cses.fi/problemset/task/1091

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
vector<ll> parent;
ll find(ll x)
{
    if(x < 0) return -1;
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    parent.resize(n);
    for(int i=0;i<n;i++) parent[i] = i;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());

    for(ll i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        ll lo = 0,hi = n;
        while(lo < hi)
        {
            ll mid = lo + (hi-lo)/2;
            if(a[mid] <= x) lo = mid + 1;
            else hi = mid;
        }
        lo--;
        lo = find(lo);
        if(lo == -1) cout<<-1<<endl;
        else
        {
            cout<<a[lo]<<endl;
            parent[lo] = find(lo-1);
        }
    }
}