#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    ll maxSum=-1e10;
    ll runningSum=0;
    for(ll i=0;i<n;i++)
    {   
        runningSum=max(runningSum+v[i],v[i]);
        maxSum=max(maxSum,runningSum);
    }
    cout<<maxSum;
    return 0;
}