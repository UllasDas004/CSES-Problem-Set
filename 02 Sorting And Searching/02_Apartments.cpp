// https://cses.fi/problemset/task/1084

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll i = 0,j = 0,count = 0;
    while(i < n && j < m)
    {
        if(a[i] == b[j])
        {
            i++;
            j++;
            count++;
        }
        else if(a[i] < b[j])
        {
            if(a[i] + k >= b[j])
            {
                count++;
                j++;
            }
            i++;
        }
        else
        {
            if(a[i] - k <= b[j])
            {
                count++;
                i++;
            }
            j++;
        }
    }
    cout<<count<<endl;
}