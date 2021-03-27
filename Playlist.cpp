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
    ll count=0;
    ll ans=0;
    ll lastRepeat=0;
    map<ll,ll>m;
    for(ll i=0;i<n;i++)
    {
        if(m.find(v[i])==m.end())
        {
            count++;
        }
        else
        {   
            lastRepeat=max(lastRepeat,m[v[i]]);
            count=i-lastRepeat;
        }
        m[v[i]]=i;
        ans=max(ans,count);
    }
    cout<<ans;
}