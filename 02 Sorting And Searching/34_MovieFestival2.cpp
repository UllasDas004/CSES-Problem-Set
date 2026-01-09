// https://cses.fi/problemset/task/1632

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
bool cmp(const vector<ll>& a,const vector<ll>& b)
{
    return a[1] < b[1];
}
int main()
{
    ll n,k;
    cin>>n>>k;
    vector<vector<ll>> a(n,vector<ll>(2));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    sort(a.begin(),a.end(),cmp);
    multiset<ll> endtimes;
    for(int i=0;i<k;i++) endtimes.insert(0);
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        ll start = a[i][0],end = a[i][1];
        auto it = endtimes.upper_bound(start);
        if(it == endtimes.begin()) continue;
        it--;
        ans++;
        endtimes.erase(it);
        endtimes.insert(end);
    }
    cout<<ans<<endl;
}