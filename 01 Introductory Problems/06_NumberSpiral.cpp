// https://cses.fi/problemset/task/1071

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        ll ans = 0;
        if(x > y)
        {
            if(x%2 == 0) ans = x*x - y + 1LL;
            else ans = (x-1LL)*(x-1LL) + y;
        }
        else
        {
            if(y%2 == 1) ans = y*y - x + 1LL;
            else ans = (y-1LL)*(y-1LL) + x;
        }
        cout<<ans<<endl;
    }
    return 0;
}