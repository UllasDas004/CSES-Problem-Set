// https://cses.fi/problemset/task/2163
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
int findSum(vector<int>& ft,int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += ft[idx];
        idx -= (idx & -(idx));
    }
    return sum;
}
void update(vector<int>& ft,int val,int idx)
{
    while(idx < ft.size())
    {
        ft[idx] += val;
        idx += (idx & -(idx));
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,k;
    cin>>n>>k;
    vector<int> fenwickTree(n+1,0);
    for(int i=1;i<=n;i++) update(fenwickTree,1,i);
    int rank = 0;
    for(int i=n;i>=1;i--)
    {
        rank = (rank + k) % i;
        int lo = 1,hi = n;
        int ans = -1;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(findSum(fenwickTree,mid) >= rank+1)
            {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        cout<<ans<<" ";
        update(fenwickTree,-1,ans);
    }
    cout<<endl;
    return 0;
}
