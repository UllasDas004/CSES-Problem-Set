// https://cses.fi/problemset/task/1631
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
#define pip pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,sum = 0,mx = 0;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
        mx = max(mx,a[i]);
    }
    cout<<max(sum,2*mx)<<endl;
}
