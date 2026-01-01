// https://cses.fi/problemset/task/1641
 
 
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
    vector<vector<ll>> a(n,vector<ll>(2));
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0];
        a[i][1] = i+1;
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            ll target = x - a[i][0] - a[j][0];
            int lo = j+1,hi = n-1;
            while(lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;
                if(a[mid][0] == target)
                {
                    cout<<a[i][1]<<" "<<a[j][1]<<" "<<a[mid][1]<<endl;
                    return 0;
                }
                else if(a[mid][0] < target) lo = mid + 1;
                else hi = mid - 1;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
