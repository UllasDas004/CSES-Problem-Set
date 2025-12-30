// https://cses.fi/problemset/task/1630
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
#define pip pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(2));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    sort(a.begin(),a.end());
    ll ans = 0,sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += a[i][0];
        ans += (a[i][1] - sum);
    }
    cout<<ans<<endl;
}
