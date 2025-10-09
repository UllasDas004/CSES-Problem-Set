// https://cses.fi/problemset/task/1070

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cin>>n;
    int n1 = (n+1)/2;
    if(n == 1) cout<<1<<endl;
    else if(n <= 3) cout<<"NO SOLUTION"<<endl;
    else if(n == 4) cout<<"3 1 4 2"<<endl;
    else
    {
        for(int i=1,j=n1+1;i<=n1;i++,j++)
        {
            cout<<i<<" ";
            if(j <= n) cout<<j<<" ";
        }
    }
    return 0;
}