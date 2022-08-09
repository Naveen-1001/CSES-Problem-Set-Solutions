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
const long long INF = 10000000000000000;//10^16 
    
typedef long long int ll;
typedef long double ld;
     
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
 
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
 
void solve()
{
    //check t

    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>graph(n+1);
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
    }
    vector<ll>dist(n+1,LONG_MAX),minf(n+1,LONG_MAX),maxf(n+1),routes(n+1);
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>>pq;
    pq.push({0,0,1});
    dist[1]=0;
    minf[1]=0;
    maxf[1]=0;
    routes[1]= 1;
    while(!pq.empty())
    {   
        tuple<ll,ll,ll>top=pq.top();
        ll u=get<2>(top),len=get<1>(top),d=get<0>(top);
        pq.pop();
        if(d>dist[u])
        {   
            continue;
        }
        for(ll i=0;i<graph[u].size();i++)
        {
            if(dist[u]+graph[u][i].second<dist[graph[u][i].first])
            {   
                dist[graph[u][i].first]=dist[u]+graph[u][i].second;
                routes[graph[u][i].first]=routes[u];
                minf[graph[u][i].first]=minf[u]+1;
                maxf[graph[u][i].first]=maxf[u]+1;
                pq.push({dist[graph[u][i].first],len+1,graph[u][i].first});
            }
            else if(dist[u]+graph[u][i].second==dist[graph[u][i].first])
            {
                routes[graph[u][i].first]=(routes[graph[u][i].first]+routes[u])%modc;
                minf[graph[u][i].first]=min(minf[graph[u][i].first],minf[u]+1);
                maxf[graph[u][i].first]=max(maxf[graph[u][i].first],maxf[u]+1);
            }
        }
    }
    cout<<dist[n]<<" "<<routes[n]<<" "<<minf[n]<<" "<<maxf[n]<<"\n";
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