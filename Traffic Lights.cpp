#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
//Store the lengths and the no. of times they occur in a map.
//store the positions of lights in a set. whenver we add a light, decrease map[length(next,prev)] by one and add the new coresponding lengths
//after each query, output the max length in map i.e map[end-1]
int main()
{
    ll x,n;
    cin>>x>>n;
    set<ll>s;
    s.insert(0);
    s.insert(x);
    map<ll,ll>m;
    m[x]=1;
    for(ll i=0;i<n;i++)
    {   
        ll p;
        cin>>p;
        auto it=s.lower_bound(p);
        ll l=*it;
        it--;
        ll r=*it;
        m[l-r]--;
        if(!m[l-r])
        {
            m.erase(l-r);
        }
        m[l-p]++;
        m[p-r]++;
        s.insert(p);
        cout<<(--m.end())->first<<" ";
    }
}