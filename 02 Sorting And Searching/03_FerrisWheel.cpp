// https://cses.fi/problemset/task/1090

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll count = 0;
    ll i = 0,j = n-1;
    while(i < j)
    {
        if(a[i] + a[j] <= x)
        i++;
        j--;
        count++;
    }
    if(i == j) count++;
    cout<<count<<endl;
}