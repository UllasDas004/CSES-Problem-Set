// https://cses.fi/problemset/task/1645
 
 
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define MOD 1000000007
#define pip pair<ll,ll>
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    stack<int> st;
    for(int i=0;i<n;i++)
    {
        while(st.size() && a[st.top()] >= a[i]) st.pop();
        if(st.size()) cout<<st.top()+1<<" ";
        else cout<<0<<" ";
        st.push(i);
    }
    cout<<endl;
    return 0;
}
