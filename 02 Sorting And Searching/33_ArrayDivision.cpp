// https://cses.fi/problemset/task/1085
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
#define pip pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,k,sum = 0,lo = 0;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
        lo = max(lo,a[i]);
    }
    ll hi = sum;
    while(lo < hi)
    {
        ll mid = lo + (hi - lo) / 2;
        ll curr = 0,count = 1;
        // cout<<mid<<endl;
        for(int i=0;i<n;i++)
        {
            // cout<<curr<<" "<<count<<endl;
            if(a[i] > mid)
            {
                count = k+1;
                break;
            }
            if(curr + a[i] <= mid) curr += a[i];
            else
            {
                count++;
                curr = a[i];
            }
        }
        if(count > k) lo = mid + 1;
        else hi = mid;
    }
    cout<<lo<<endl;
    return 0;
}
