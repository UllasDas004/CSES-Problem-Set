// https://cses.fi/problemset/task/1074


#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll median = a[n/2];
    ll ans = 0;
    for(int i=0;i<n;i++) ans += abs(a[i] - median);
    cout<<ans<<endl;
    return 0;
}