// https://cses.fi/problemset/task/1637

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
ll rec(vector<vector<int>>& a,ll i,ll j,vector<vector<ll>>& dp)
{
    ll n = a.size();
    if(i == n || j == n) return 0;
    if(i == n-1 && j == n-1) return ll(a[i][j] != 1);
    if(a[i][j] == 1) return 0LL;
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = 0LL;
    ans = (ans + rec(a,i+1,j,dp)) % MOD;
    ans = (ans + rec(a,i,j+1,dp)) % MOD;
    return dp[i][j] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n,0));
    for(ll i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<n;j++) if(s[j] == '*') a[i][j] = 1;
    }
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,-1));
    cout<<rec(a,0,0,dp) % MOD<<endl;
}