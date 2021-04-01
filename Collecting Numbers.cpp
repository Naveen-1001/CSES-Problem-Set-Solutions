#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    vector<ll>v(n);
    map<ll,ll>m;
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(ll i=0;i<n;i++)
    {
        m[v[i]]=i;
    }
    ll count=0;
    ll prev=INT_MAX;
    for(auto it=m.begin();it!=m.end();it++)
    {
        if(it->second<prev)
        {
            count++;
        }
        prev=it->second;
    }
    cout<<count;
    return 0;
}