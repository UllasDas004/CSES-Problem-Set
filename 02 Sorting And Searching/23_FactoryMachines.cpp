// https://cses.fi/problemset/task/1620
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
#define pip pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,t;
    cin>>n>>t;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll lo = 1,hi = t*a[n-1];
    while(lo <= hi)
    {
        ll mid = lo + (hi - lo) / 2;
        ll count = 0;
        for(int i=0;i<n;i++)
        {
            count += mid/a[i];
            if(count >= t) break;
        }
        if(count >= t) hi = mid - 1;
        else lo = mid + 1;
    }
    cout<<lo<<endl;
}
