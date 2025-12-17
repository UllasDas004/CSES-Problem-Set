// https://cses.fi/problemset/task/1629

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
bool cmp(vector<ll>& a,vector<ll>& b)
{
    if(a[1] < b[1]) return true;
    else if(a[1] == b[1]) return a[0] < b[0];
    return false;
}
int main()
{
    ll n;
    cin>>n;
    vector<vector<ll>> a(n,vector<ll>(2));
    for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
    sort(a.begin(),a.end(),cmp);
    ll ans = 0,ending = -1;
    for(int i=0;i<n;i++)
    {
        if(a[i][0] >= ending)
        {
            ans++;
            ending = a[i][1];
        }
    }
    cout<<ans<<endl;
}