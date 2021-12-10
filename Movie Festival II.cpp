#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n,k,a,b;
    cin>>n>>k;
    vector<pair<ll,ll>>v;
    for(ll i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end(),[](const pair<ll,ll>&p1,const pair<ll,ll>&p2){
        if(p1.second==p2.second)
        {
            return p1.first<=p2.first;
        }
        return p1.second<p2.second;
    });
    multiset<ll,greater<ll>>s;
    int ans=0;
    for(ll i=0;i<k;i++)
    {
        s.insert(0);
    }
    for(int i=0;i<n;i++)
    {
        auto it=s.lower_bound(v[i].first);
        if(it!=s.end())
        {
            s.erase(it);
            s.insert(v[i].second);
            ans++;
        }
    }
    cout<<ans;
}