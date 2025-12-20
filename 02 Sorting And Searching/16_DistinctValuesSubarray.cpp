// https://cses.fi/problemset/task/3420
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<ll,ll> mp;
    ll ans = 0;
    int l = 0;
    for(int r=0;r<n;r++)
    {
        mp[a[r]]++;
        while(mp[a[r]] > 1) mp[a[l++]]--;
        ans += (r - l + 1);
    }
    cout<<ans<<endl;
    return 0;
}