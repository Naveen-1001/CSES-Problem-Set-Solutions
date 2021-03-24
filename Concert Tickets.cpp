#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,m,v;
    cin>>n>>m;
    multiset<ll>s;
    vector<ll>c(m);
    for(ll i=0;i<n;i++)
    {
        cin>>v;
        s.insert(v);
    }
    for(ll i=0;i<m;i++)
    {
        cin>>c[i];
    }
    for(ll i=0;i<m;i++)
    {
        auto it=s.lower_bound(c[i]);
        if(*it==c[i])
        {
            cout<<*it<<"\n";
            s.erase(it);
            continue;
        }
        if(it==s.begin())
        {
            cout<<-1<<"\n";
            continue;
        }
        it--;
        cout<<*it<<"\n";
        s.erase(it);
    }
    return 0;
}