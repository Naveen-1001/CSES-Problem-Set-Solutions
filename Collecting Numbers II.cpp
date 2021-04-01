#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll check(ll a,ll b,vector<ll>&pos,vector<ll>&v,ll count,set<pair<ll,ll>>&s)
{
    if(v[a]-1>0 and s.find({v[a]-1,v[a]})==s.end())
    {
        if(pos[v[a]]>pos[v[a]-1])
        {
            if(b<=pos[v[a]-1])
            {
                count++;
            }
        }
        else if(pos[v[a]]<pos[v[a]-1])
        {
            if(b>=pos[v[a]-1])
            {
                count--;
            }
        }
        s.insert({v[a]-1,v[a]});
    }
    
    if(s.find({v[a],v[a]+1})==s.end())
    {
        if(pos[v[a]]>pos[v[a]+1])
        {
            if(b<=pos[v[a]+1])
            {
                count--;
            }
        }
        else if(pos[v[a]]<pos[v[a]+1])
        {
            if(b>=pos[v[a]+1])
            {
                count++;
            }
        }
        s.insert({v[a],v[a]+1});
    }
    return count;
}

int main()
{   
    //For the swapped numebrs just check the change in position with respect to positions of next and previous
    //value numbers. Also dont take the same two combinations of numbers more than once.
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n+1);
    vector<ll>pos(n+1);
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
        pos[v[i]]=i;
    }
    ll prev=INT_MAX;
    ll count=0;
    for(ll i=1;i<=n;i++)
    {
        if(pos[i]<prev)
        {
            count++;
        }
        prev=pos[i];
    }
    ll a,b;
    for(ll i=0;i<m;i++)
    {   
        set<pair<ll,ll>>s;
        cin>>a>>b;
        count=check(a,b,v,pos,count,s);
        count=check(b,a,v,pos,count,s);
        swap(pos[v[a]],pos[v[b]]);
        swap(v[a],v[b]);
        cout<<count<<"\n";
    }
}