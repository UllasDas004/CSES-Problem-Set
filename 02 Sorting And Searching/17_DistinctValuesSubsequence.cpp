// https://cses.fi/problemset/task/3421
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n);
    map<ll,ll> mp;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    ll product = 1;
    for(auto& p : mp)
    {
        p.second++;
        product = (product * p.second) % MOD;
    }
    cout<<(product-1) % MOD<<endl;
    return 0;
}