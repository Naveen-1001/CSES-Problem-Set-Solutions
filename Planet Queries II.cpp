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

ll parent[200005][30];
ll next_planet[200005];
ll cycle_dist[200005];
ll cycle_ids[200005];
void solve()
{
    ll n,q;
    cin>>n>>q;
    map<ll,vector<ll>>before;
    for(ll i=0;i<n;i++)
    {
        cin>>next_planet[i];
        next_planet[i]--;
        before[next_planet[i]].push_back(i);
    }
    vector<map<ll,ll>>cycles;
    for(ll i=0;i<n;i++)
    {
        cycle_ids[i]=-2;
    }
    for(ll i=0;i<n;i++)
    {
        if(cycle_ids[i]!=-2)
        {
            continue;
        }
        ll at=i;
        vector<ll>path{at};
        while(cycle_ids[next_planet[at]]==-2)
        {
            at=next_planet[at];
            cycle_ids[at]=-3;
            path.push_back(at);
        }
        map<ll,ll>cycle;
        bool in_cycle=false;
        for(auto i:path)
        {
            in_cycle = in_cycle || i==next_planet[at];
            if(in_cycle)
            {
                cycle[i]=cycle.size();
            }
            cycle_ids[i]= in_cycle ? cycles.size() : -1;
        }
        cycles.push_back(cycle);
    }
 
    for(ll i=0;i<n;i++)
    {   
        if(cycle_ids[i]!=-1 || cycle_ids[next_planet[i]]==-1)
        {
            continue;
        }
        cycle_dist[i]=1;
        queue<ll>q;
        q.push(i);
        while(!q.empty())
        {
            ll front=q.front();
            q.pop();
            cycle_dist[front]=cycle_dist[next_planet[front]]+1;
            for(auto x:before[front])
            {
                q.push(x);
            }
        }
    }
 
    ll max_jump=ceil(log2(n));
 
    for(ll i=0;i<n;i++)
    {
        parent[i][0]=next_planet[i];
    }
 
    for(ll jump=1;jump<max_jump+1;jump++)
    {
        for(ll i=0;i<n;i++)
        {
            parent[i][jump]=parent[parent[i][jump-1]][jump-1];
        }
    }
 
    auto advance = [&](ll pos, ll dist){
        for(ll i=0;i<=max_jump;i++)
        {
            if((dist & (1<<i))!=0)
            {
                pos=parent[pos][i];
            }
        }
        return pos;
    };
 
    while(q--)
    {
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        if(cycle_ids[parent[u][max_jump]]!=cycle_ids[parent[v][max_jump]])
        {
            cout<<-1<<"\n";
            continue;
        }
        if(cycle_ids[u]!=-1 || cycle_ids[v]!=-1)
        {
            if(cycle_ids[u]!=-1 && cycle_ids[v]==-1)
            {
                cout<<-1<<"\n";
                continue;
            }
            ll dist_u = cycle_dist[u];
            ll u_cyc_node = advance(u,dist_u);
 
            map<ll,ll>&cyc = cycles[cycle_ids[u_cyc_node]];
            ll u_cyc_pos = cyc[u_cyc_node];
            ll v_cyc_pos = cyc[v];
            ll dist = (u_cyc_pos <= v_cyc_pos) ? (v_cyc_pos - u_cyc_pos) : (cyc.size() - (u_cyc_pos - v_cyc_pos));
            cout<<dist_u + dist<<"\n";
        }
        else
        {
            if(cycle_dist[v]>cycle_dist[u])
            {
                cout<<-1<<"\n";
            }
            else
            {
                ll final_node_u = advance(u,cycle_dist[u]-cycle_dist[v]);
                (final_node_u == v) ? cout<<cycle_dist[u]-cycle_dist[v]<<"\n" : cout<<-1<<"\n";
            }
        }
 
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