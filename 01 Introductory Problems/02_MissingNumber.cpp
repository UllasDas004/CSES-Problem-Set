// https://cses.fi/problemset/task/1083

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    vector<int> a(n-1);
    for(int i=0;i<n-1;i++) cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++)
    {
        if(a[i] != i+1)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
    return 0;
}