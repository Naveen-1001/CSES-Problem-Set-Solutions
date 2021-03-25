#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,x,vi;
    cin>>n>>x;
    vector<pair<ll,ll>>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>vi;
        v[i]={vi,i+1};
    }
    sort(v.begin(),v.end());
    ll l=0,r=n-1;
    ll flag=0;
    while(l<r)
    {
        if(v[l].first+v[r].first==x)
        {   
            cout<<v[l].second<<" "<<v[r].second;
            flag=1;
            break;
        }
        if(v[l].first+v[r].first<x)
        {
            l++;
            continue;
        }
        r--;
    }
    if(!flag)
    {
        cout<<"IMPOSSIBLE";
    }
    return 0;
}