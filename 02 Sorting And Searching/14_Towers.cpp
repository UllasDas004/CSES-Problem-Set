// https://cses.fi/problemset/task/1073
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<ll> top = {a[0]};
    for(int i=1;i<n;i++)
    {
        int lo = 0,hi = top.size()-1;
        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            if(top[mid] > a[i]) hi = mid-1;
            else lo = mid+1;
        }
        if(lo == top.size() || top[lo] == a[i]) top.push_back(a[i]);
        else top[lo] = a[i];
    }
    cout<<top.size()<<endl;
}