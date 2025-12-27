// https://cses.fi/problemset/task/2168
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
bool cmp(const vector<ll>& a,const vector<ll>& b)
{
    if(a[0] < b[0]) return true;
    else if(a[0] == b[0]) return a[1] > b[1];
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(3));
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(),a.end(),cmp);
    vector<int> ans1(n,0),ans2(n,0);
    ll minEnd = LLONG_MAX;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i][1] >= minEnd) ans1[a[i][2]] = 1;
        minEnd = min(minEnd,a[i][1]);
    }
    ll maxEnd = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i][1] <= maxEnd) ans2[a[i][2]] = 1;
        maxEnd = max(maxEnd,a[i][1]);
    }
    for(int i=0;i<n;i++) cout<<ans1[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++) cout<<ans2[i]<<" ";
    cout<<"\n";
    return 0;
}
