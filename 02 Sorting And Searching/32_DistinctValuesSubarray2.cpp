// https://cses.fi/problemset/task/2428
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
#define pip pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<ll,ll> mp;
    ll ans = 0;
    int j = 0;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;
        if(mp.size() > k)
        {
            while(j<i && mp.size() > k)
            {
                ans += (i - j);
                mp[a[j]]--;
                if(mp[a[j]] == 0) mp.erase(a[j]);
                j++;
            }
        }
    }
    while(j < n)
    {
        ans += (n - j);
        j++;
    }
    cout<<ans<<endl;
    return 0;
}
