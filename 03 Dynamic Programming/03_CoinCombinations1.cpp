// https://cses.fi/problemset/task/1635

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
ll rec(vector<ll>& a,int x,vector<ll>& dp)
{
    if(x == 0) return 1;
    if(x < 0) return 0;
    if(dp[x] != -1) return dp[x];
    ll n = a.size();
    ll ans = 0;
    for(int i=0;i<n;i++) ans = (ans+rec(a,x-a[i],dp)) % MOD;
    return dp[x] = ans % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> dp(x+1,-1);
    ll ans = rec(a,x,dp);
    cout<<ans % MOD<<endl;
}