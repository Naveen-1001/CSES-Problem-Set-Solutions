#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,a,b;
    cin>>n;
    unordered_map<ll,ll>m;
    set<ll>s;
    vector<ll>prefix(2*n+1);
    ll count=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a>>b;
        m[a]=1;
        m[b]=-1;
        s.insert(a);
        s.insert(b);
    }
    for(auto it=s.begin();it!=s.end();it++)
    {
        if(m[*it]==1)
        {
            prefix[count]=prefix[count]+1;
        }
        else if(m[*it]==-1)
        {
            prefix[count+1]=prefix[count+1]-1;
        }
        count++;
    }
    /*
    for(ll i=0;i<2*n;i++)
    {
        cout<<prefix[i]<<" ";
    }
    */
    //cout<<"\n";
    ll res=prefix[0];
    for(ll i=1;i<2*n;i++)
    {
        prefix[i]=prefix[i-1]+prefix[i];
        res=max(res,prefix[i]);
        //cout<<prefix[i]<<" ";
    }
    //cout<<"\n";
    cout<<res;
}