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

vector<ll>order;
vector<ll>kingdom;
ll ccount;

void dfs1(ll ind, vector<vector<ll>>&graph, vector<ll>&visited)
{
    visited[ind]=1;
    for(ll i=0;i<graph[ind].size();i++)
    {
        if(!visited[graph[ind][i]])
        {
            dfs1(graph[ind][i],graph,visited);
        }
    }
    order.push_back(ind);
}

void dfs2(ll ind, vector<vector<ll>>&graph, vector<ll>&visited)
{
    visited[ind]=1;
    kingdom[ind]=ccount;
    for(ll i=0;i<graph[ind].size();i++)
    {
        if(!visited[graph[ind][i]])
        {
            dfs2(graph[ind][i],graph,visited);
        }
    }
}

void solve()
{
    //check t
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>graph(n+1),revg(n+1);
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        revg[b].push_back(a);
    }
    vector<ll>visited(n+1);
    kingdom=vector<ll>(n+1,-1);
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs1(i,graph,visited);
        }
    }
    reverse(order.begin(),order.end());
    fill(visited.begin(),visited.end(),0);
    ccount=1;
    for(ll i=0;i<order.size();i++)
    {
        if(!visited[order[i]])
        {
            dfs2(order[i],revg,visited);
            ccount++;
        }
    }
    cout<<ccount-1<<"\n";
    for(ll i=1;i<=n;i++)
    {
        cout<<kingdom[i]<<" ";
    }
    cout<<"\n";
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