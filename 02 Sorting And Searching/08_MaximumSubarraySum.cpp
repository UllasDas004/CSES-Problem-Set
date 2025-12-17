// https://cses.fi/problemset/task/1643

// Kadane's Algorithm
#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
int main()
{
    ll n,sum = 0,maxSum = INT_MIN;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        sum += x;
        maxSum = max(sum,maxSum);
        if(sum < 0) sum = 0;
    }
    cout<<maxSum<<endl;
    return 0;
}