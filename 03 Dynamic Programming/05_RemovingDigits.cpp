// https://cses.fi/problemset/task/1637

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
ll rec(ll n,vector<ll>& dp)
{
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    ll a = n,ans = INT_MAX;
    while(a > 0)
    {
        ll r = a%10;
        a /= 10;
        if(r) ans = min(ans,1LL+rec(n-r,dp));
    }
    return dp[n] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> dp(n+1,-1);
    cout<<rec(n,dp)<<endl;
}