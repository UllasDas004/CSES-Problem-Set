// https://cses.fi/problemset/task/2217
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),pos(n+1);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        pos[a[i]] = i+1;
    }
    ll rounds = 1;
    for(int i=2;i<=n;i++) if(pos[i-1] > pos[i]) rounds++;
    auto bad = [&](ll x)
    {
        if(x < 1 || x >= n) return false;
        return (pos[x+1] < pos[x]);
    };
    for(int i=0;i<m;i++)
    {
        ll l,r;
        cin>>l>>r;
        if(l == r)
        {
            cout<<rounds<<endl;
            continue;
        }
        ll x = a[l-1],y = a[r-1];
        set<ll> affected = {x,x-1,y,y-1};
        for(auto i : affected) rounds -= bad(i);
        swap(a[l-1],a[r-1]);
        swap(pos[x],pos[y]);
        for(auto i : affected) rounds += bad(i);
        cout<<rounds<<endl;
    }
}