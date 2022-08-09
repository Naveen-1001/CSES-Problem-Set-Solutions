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
 
ll sum_of_digits(ll n)
{
    ll sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

/*
In this question, dfs cannot be used to find the negative cycles. This is because, when we are searching for 
negative cycles and maintaining the sum, the exact path we follow is important. But during dfs, we cannot 
control this path. So if we completly explore a node of a cycle in another path that is not part off the negative
cycle, then when we actually traverse the negative cycle, this node will already have been explored and we wont 
get the chance to detect that cycle. Hence, answer will be NO even when there is a negative cycle.

Hence, to solve this question, bellman ford algorithm has to be used. Do  iterations 
of Bellman-Ford algorithm. If there were no changes on the last iteration, 
there is no cycle of negative weight in the graph. Otherwise take a vertex the distance 
to which has changed, and go from it via its ancestors until a cycle is found. 
This cycle will be the desired cycle of negative weight.
*/

struct Edge{
    int a,b,w;
};


void solve()
{
    //check t
    ll n,m;
    cin>>n>>m;
    vector<Edge>edges(m);
    for(ll i=0;i<m;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        edges[i].a=a;
        edges[i].b=b;
        edges[i].w=c;
    }

    vector<ll>dist(n+1,INF);
    vector<ll>parent(n+1,-1);
    dist[1]=0;
    ll x;
    for(ll i=0;i<n;i++)
    {   
        x=-1;
        for(Edge e : edges)
        {   
            if(dist[e.a]+e.w<dist[e.b])
            {   
                dist[e.b]=dist[e.a]+e.w;
                parent[e.b]=e.a;
                x=e.b;
                
            }
        }
    }
    if(x==-1)
    {
        cout<<"NO\n";
    }
    else
    {   
        for(ll i=0;i<n;i++) x=parent[x];
        // ll count=0;
        vector<ll>ans;
        ans.push_back(x);
        // cout<<x<<"\n";
        ll curr=parent[x];
        while(curr!=x)
        {
            ans.push_back(curr);
            //  cout<<curr<<"\n";
            curr=parent[curr];
            //  if(++count==10) break;
        }
        ans.push_back(curr);
        reverse(ans.begin(),ans.end());
        cout<<"YES\n";
        for(auto x:ans)
        {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
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