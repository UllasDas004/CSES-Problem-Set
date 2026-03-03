// https://cses.fi/problemset/task/1633

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
ll rec(ll n,vector<ll>& dp)
{
    if(n < 0) return 0;
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    ll ans = 0;
    for(int i=1;i<=6;i++)
    ans = (ans + rec(n-i,dp)) % MOD;
    return dp[n] = ans;
}
int main()
{
    ll n;
    cin>>n;
    vector<ll> dp(n+1,-1);
    cout<<rec(n,dp) % MOD<<endl;
}