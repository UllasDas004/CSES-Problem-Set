// https://cses.fi/problemset/task/1158

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int rec(vector<int>& h,vector<int>& s,int i,int x,vector<vector<int>>& dp)
{
    int n = h.size();
    if(i == n) return 0;
    if(dp[i][x] != -1) return dp[i][x];
    int ans = 0;
    ans = max(ans,rec(h,s,i+1,x,dp));
    if(x >= h[i]) ans = max(ans,s[i]+rec(h,s,i+1,x-h[i],dp));
    return dp[i][x] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> h(n),s(n);
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<n;i++) cin>>s[i];
    vector<int> dp(x+1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=x;j>=h[i];j--)
        dp[j] = max(dp[j],s[i]+dp[j-h[i]]);
    }
    cout<<dp[x]<<endl;
}