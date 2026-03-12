// https://cses.fi/problemset/task/1746

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int rec(vector<int>& a,int i,int m,int prev,vector<vector<int>>& dp)
{
    int n = a.size();
    if(i == n) return 1;
    if(dp[i][prev] != -1) return dp[i][prev];
    if(a[i] != 0)
    {
        if(abs(a[i]-prev) > 1) return 0;
        else return dp[i][prev] = rec(a,i+1,m,a[i],dp) % MOD;
    }
    int start,end;
    if(prev == 0)
    {
        start = 1;
        end = m;
    }
    else
    {
        start = max(1,prev-1);
        end = min(prev+1,m);
    }
    int ans = 0;
    for(int j=start;j<=end;j++)
    ans = (ans % MOD + rec(a,i+1,m,j,dp) % MOD) % MOD;
    return dp[i][prev] = ans % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n,vector<int>(m+2,0));
    if(a[0] == 0)
    {
        for(int j=1;j<=m;j++)
        dp[0][j] = 1;
    }
    else dp[0][a[0]] = 1;
    for(int i=1;i<n;i++)
    {
        if(a[i] == 0)
        {
            for(int j=1;j<=m;j++)
            dp[i][j] = ((ll)dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
        }
        else
        {
            int j = a[i];
            dp[i][j] = ((ll)dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1]) % MOD;
        }
    }
    int ans = 0;
    for(int i=1;i<=m;i++) ans = (ans + dp[n-1][i]) % MOD;
    cout<<ans<<endl;
}