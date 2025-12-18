// https://cses.fi/problemset/task/2183


#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll reach = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i] > reach+1) break;
        else reach += a[i];
    }
    cout<<reach+1<<endl;
}