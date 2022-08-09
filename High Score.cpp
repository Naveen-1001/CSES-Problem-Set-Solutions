#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <climits>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
 
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
typedef long long int ll;
typedef long double ld;

const ll MX16=100000000000000;//10^14
     
// using namespace __gnu_pbds;
using namespace std;
 
// template<class T> 
// using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
 
ll fast_power(ll a, ll b, ll m)//a^b
{
    if(b==0) return 1;
    if(b==1) return a;
 
    ll temp=fast_power(a,b/2,m);
 
    if(b%2==0) return (temp*temp)%m;
    return ((temp*temp)%m*a)%m;
}
 
ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b); 
}

void solve()
{
    //check t
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>graph(n+1);
    vector<vector<ll>>revgraph(n+1);
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,-c});
        revgraph[b].push_back(a);
    }
    queue<ll>q;
    vector<bool>visited_d(n+1);
    visited_d[n]=true;
    q.push(n);
    while(!q.empty())
    {
        ll front=q.front();
        q.pop();
        for(ll i=0;i<revgraph[front].size();i++)
        {
            if(!visited_d[revgraph[front][i]])
            {
                visited_d[revgraph[front][i]]=true;
                q.push(revgraph[front][i]);
            }
        }
    }

    vector<ll>dist(n+1,MX16);
    dist[1]=0;
    map<pair<ll,ll>,ll>mm;
    for(ll i=1;i<=n;i++)
    {   
        vector<ll>d=dist;
        for(ll j=1;j<=n;j++)
        {   
            if(dist[j]<MX16)
            {
                for(auto it=graph[j].begin();it!=graph[j].end();it++)
                {
                    ll comp=dist[j]+(*it).second;
                    if(comp<dist[(*it).first])
                    {
                        d[(*it).first]=comp;
                        if(visited_d[(*it).first] && i==n)
                        {
                            cout<<-1<<"\n";
                            return;
                        }
                    }
                }
            }
        }
        dist=d;
    }
    cout<<-dist[n]<<"\n";
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    t=1;
    // cin>>t;
    while(t--)
    {   
        solve();
    }
    return 0;
}