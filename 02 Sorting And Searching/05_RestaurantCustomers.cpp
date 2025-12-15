// https://cses.fi/problemset/task/1619

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;

int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(2));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    ll ans = 0,count = 0;
    sort(a.begin(),a.end());
    ll i = 0;
    priority_queue<ll,vector<ll>,greater<ll>> minHeap;
    while(i < n)
    {
        if(minHeap.empty() || (minHeap.size() && a[i][0] < minHeap.top()))
        {
            minHeap.push(a[i][1]);
            count++;
            i++;
        }
        else
        {
            minHeap.pop();
            count--;
        }
        ans = max(ans,count);
    }
    cout<<ans<<endl;
}