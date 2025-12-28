// https://cses.fi/problemset/task/1164
 
 
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
    vector<vector<ll>> a(n,vector<ll>(3));
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
        a[i][2] = i;
    }
    sort(a.begin(),a.end());
    priority_queue<pip,vector<pip>,greater<pip>> pq;
    ll room = 0;
    vector<ll> ans(n);
    for(int i=0;i<n;i++)
    {
        ll start = a[i][0],end = a[i][1],idx = a[i][2];
        if(pq.size() && pq.top().first < start)
        {
            pip p = pq.top();
            pq.pop();
            ans[idx] = p.second;
            pq.push({end,p.second});
        }
        else
        {
            room++;
            ans[idx] = room;
            pq.push({end,room});
        }
    }
    cout<<room<<endl;
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}
