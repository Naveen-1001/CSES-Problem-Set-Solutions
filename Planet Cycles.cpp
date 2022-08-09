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
    ll n;
    cin>>n;
    vector<ll>next(n);
    map<ll,vector<ll>>before;
    for(ll i=0;i<n;i++)
    {
        cin>>next[i];
        next[i]--;
        before[next[i]].push_back(i);
    }
    vector<ll>cycle_ids(n,-2);
    vector<ll>cycles_sizes;
    for(ll i=0;i<n;i++)
    {
        if(cycle_ids[i]!=-2)
        {
            continue;
        }
        vector<ll>path{i};
        ll at=i;
        cycle_ids[at]=-3;
        while(cycle_ids[next[at]]==-2)
        {
            at=next[at];
            cycle_ids[at]=-3;
            path.push_back(at);
        }
        bool in_cycle=false;
        ll cycle_size=0;
        for(auto planet:path)
        {
            in_cycle=in_cycle || planet==next[at];
            if(in_cycle)
            {
                cycle_size++;
            }
            if(in_cycle)
            {
                cycle_ids[planet]=cycles_sizes.size();
            }
            else
            {
                cycle_ids[planet]=-1;
            }
        }
        cycles_sizes.push_back(cycle_size);
    }
    vector<ll>cycle_dist(n,0);
    for(ll i=0;i<n;i++)
    {
        if(cycle_ids[i]!=-1 || cycle_ids[next[i]]==-1)
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
            cycle_dist[front]=1+cycle_dist[next[front]];
            cycle_ids[front]=cycle_ids[next[front]];
            for(auto x:before[front])
            {
                q.push(x);
            }
        }
    }
    for(ll i=0;i<n;i++)
    {
        cout<<cycle_dist[i]+cycles_sizes[cycle_ids[i]]<<" ";
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