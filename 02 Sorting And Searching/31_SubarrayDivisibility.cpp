// https://cses.fi/problemset/task/1662
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
#define pip pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,sum = 0;
    cin>>n;
    vector<ll> a(n);
    map<ll,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
        ll x = (sum % n + n) % n;
        mp[x]++;
    }
    ll ans = 0;
    for(auto p : mp)
    {
        ll num = p.first,count = p.second;
        if(num == 0) ans += count;
        ans += ((count-1)*count)/2;
    }
    cout<<ans<<endl;
    return 0;
}
