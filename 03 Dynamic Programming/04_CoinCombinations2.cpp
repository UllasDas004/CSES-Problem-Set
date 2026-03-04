// https://cses.fi/problemset/task/1635

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int rec(vector<int>& a,int i,int x,vector<vector<int>>& dp)
{
    if(x == 0) return 1;
    int n = a.size();
    if(i == n || x < 0) return 0;
    int ans = 0;
    ans = (ans + rec(a,i+1,x,dp)) % MOD;
    if(x >= a[i]) ans = (ans + rec(a,i,x-a[i],dp)) % MOD;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
    cout<<rec(a,0,x,dp) % MOD<<endl;
}