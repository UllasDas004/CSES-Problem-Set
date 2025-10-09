// https://cses.fi/problemset/task/1069

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll n = s.length();
    int ans = 1,count = 1;
    int i = 1;
    while(i < n)
    {
        if(s[i] == s[i-1]) count++;
        else
        {
            ans = max(ans,count);
            count = 1;
        }
        i++;
    }
    ans = max(ans,count);
    cout<<ans<<endl;
    return 0;
}