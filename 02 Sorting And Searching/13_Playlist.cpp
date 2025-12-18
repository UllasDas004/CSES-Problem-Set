// https://cses.fi/problemset/task/2216
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<ll,ll> mp;
    ll ans = 0,i = 0,j = 0,len = 0;
    while(j < n)
    {
        if(mp.find(a[j]) == mp.end())
        {
            mp[a[j]]++;
            j++;
            len++;
        }
        else
        {
            mp[a[i]]--;
            if(mp[a[i]] == 0) mp.erase(a[i]);
            i++;
            len--;
        }
        ans = max(ans,len);
    }
    cout<<ans<<endl;
}