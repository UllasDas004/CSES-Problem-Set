// https://cses.fi/problemset/task/1661
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
#define pip pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<ll,int> mp;
    ll sum = 0,ans = 0;
    mp[0] = 1;
    for(int i=0;i<n;i++)
    {
        sum += a[i];
        ll need = sum - x;
        if(mp.find(need) != mp.end()) ans += mp[need];
        mp[sum]++;
    }
    cout<<ans<<endl;
    return 0;
}
