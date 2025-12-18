// https://cses.fi/problemset/task/2216
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n;
    cin>>n;
    vector<ll> pos(n+1);
    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        pos[x] = i;
    }
    ll round = 1;
    for(int i=2;i<=n;i++)
    {
        if(pos[i] < pos[i-1])
        round++;
    }
    cout<<round<<endl;
}