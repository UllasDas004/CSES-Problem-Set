// https://cses.fi/problemset/task/1642
 
 
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
    map<ll,pair<int,int>> mp;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ll need = x - (a[i] + a[j]);
            if(mp.find(need) != mp.end())
            {
                int p = mp[need].first,q = mp[need].second;
                if(p != i && q != j && p != j && q != i)
                {
                    cout<<p+1<<" "<<q+1<<" "<<i+1<<" "<<j+1<<endl;
                    return 0;
                }
            }
        }
        for(int j=0;j<i;j++) mp[a[i]+a[j]] = {j,i};
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
