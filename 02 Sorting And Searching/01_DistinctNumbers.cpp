// https://cses.fi/problemset/task/1621

#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n;
    cin>>n;
    set<ll> st;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        st.insert(x);
    }
    cout<<st.size()<<endl;
}