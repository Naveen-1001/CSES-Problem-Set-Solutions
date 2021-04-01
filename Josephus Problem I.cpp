#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n;
    cin>>n;
    set<ll>s;
    for(ll i=1;i<=n;i++)
    {
        s.insert(i);
    }
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    auto it=s.begin();
    it++;
    while(1)
    {
        cout<<*it<<" ";
        s.erase(it++);
        if(s.empty()) 
        {
            break;
        }
        if(it==s.end())
        {
            it=s.begin();
        }
        it++;
        if(it==s.end())
        {
            it=s.begin();
        }
    }
}
