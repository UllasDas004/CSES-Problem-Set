// https://cses.fi/problemset/task/1660
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
#define pip pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int i = 0,j = 0;
    ll ans = 0,sum = 0;
    while(i < n)
    {
        while(i<n && sum < x) sum += a[i++];
        while(j<i && sum >= x)
        {
            if(sum == x) ans++;
            sum -= a[j++];
        }
    }
    if(sum == x) ans++;
    cout<<ans<<endl;
    return 0;
}
