// https://cses.fi/problemset/task/1634

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int rec(vector<int>& a,int x,vector<ll>& dp)
{
    if(x == 0) return 0;
    if(x < 0) return 10000000;
    if(dp[x] != -1) return dp[x];
    int n = a.size();
    int ans = 10000000;
    for(int i=0;i<n;i++) ans = min(ans,1+rec(a,x-a[i],dp));
    return dp[x] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> dp(x+1,-1);
    int ans = rec(a,x,dp);
    cout<<(ans == 10000000 ? -1 : ans)<<endl;
}