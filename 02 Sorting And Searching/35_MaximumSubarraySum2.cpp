// https://cses.fi/problemset/task/1644

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n,x,y;
    cin>>n>>x>>y;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i] += a[i-1];
    }
    deque<ll> dq;
    for(int i=1;i<y;i++)
    {
        while(dq.size() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
    }
    ll ans = LLONG_MIN;
    for(int i=0;i<=n-x;i++)
    {
        while(i+y<=n && dq.size() && a[dq.back()] <= a[i+y]) dq.pop_back();
        if(i+y <= n) dq.push_back(i+y);
        while(dq.size() && dq.front() < i+x) dq.pop_front();
        ans = max(ans,a[dq.front()]-a[i]);
    }
    cout<<ans<<endl;
}