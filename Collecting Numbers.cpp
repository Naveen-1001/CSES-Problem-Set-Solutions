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
    vector<ll>res;
    for(ll i=0;i<n;i++)
    {
        auto it=upper_bound(res.begin(),res.end(),v[i],greater<ll>());
        if(it==res.end())
        {
            res.push_back(v[i]);
        }
        else 
        {
            *it=v[i];
        }
    }
    for(ll i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
    cout<<res.size();
}