// https://cses.fi/problemset/task/2162
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
void josephus(vector<ll> a)
{
    int n = a.size();
    if(n == 1)
    {
        cout<<a[0]<<endl;
        return;
    }
    for(int i=1;i<n;i+=2) cout<<a[i]<<" ";
    vector<ll> newA;
    if(n%2 == 1)
    {
        newA.push_back(a[n-1]);
        for(int i=0;i<n-1;i+=2)
        newA.push_back(a[i]);
    }
    else
    {
        for(int i=0;i<n;i+=2)
        newA.push_back(a[i]);
    }
    josephus(newA);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) a[i] = i+1;
    josephus(a);
    return 0;
}