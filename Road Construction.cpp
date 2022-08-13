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

ll find(ll u, vector<ll>&parent)
{
    if(u==parent[u])
    {
        return u;
    }
    return parent[u]=find(parent[u],parent);
}

ll max_component,components;

void unite(ll u, ll v, vector<ll>&parent, vector<ll>&size)
{
    u=find(u,parent);
    v=find(v,parent);
    if(size[u]>size[v])
    {
        swap(u,v);
    }
    components--;
    size[v]+=size[u];
    parent[u]=v;
    max_component=max(max_component,size[v]);
}
 
void solve()
{
    //check t
    ll n,m;
    cin>>n>>m;
    vector<ll>parent(n+1);
    components=n;
    max_component=1;
    for(ll i=1;i<=n;i++)
    {
        parent[i]=i;
    }
    vector<ll>size(n+1,1);
    for(ll i=0;i<m;i++)
    {   
        ll u,v;
        cin>>u>>v;
        if(find(u,parent)!=find(v,parent))
        {
            unite(u,v,parent,size);
        }
        cout<<components<<" "<<max_component<<"\n";
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