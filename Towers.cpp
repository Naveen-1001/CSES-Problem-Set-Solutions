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
    vector<ll>towers;
    for(ll i=0;i<n;i++)
    {
        auto it=upper_bound(towers.begin(),towers.end(),v[i]);
        if(it==towers.end())
        {
            towers.push_back(v[i]);
        }
        else
        {
            *it=v[i];
        }
    }
    cout<<towers.size();
}