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
#include <unordered_map>
#include <unordered_set>
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
unordered_map<ll,ll>components;
unordered_map<ll,vector<ll>>scc;
ll comp_count=0;
vector<ll>cond_order;
unordered_map<ll,char>assigned;
unordered_map<ll,unordered_set<ll>>condensed_graph_set;

void dfs1(ll ind, unordered_map<ll,unordered_set<ll>>&graph, unordered_set<ll>&visited, bool cond)
{   
    visited.insert(ind);
    for(auto x:graph[ind])
    {
        if(visited.find(x)==visited.end())
        {
            dfs1(x,graph,visited,cond);
        }
    }
    if(!cond) order.push_back(ind);
    else cond_order.push_back(ind);
}

void dfs2(ll ind, unordered_map<ll,unordered_set<ll>>&graph, unordered_set<ll>&visited)
{
    visited.insert(ind);
    components[ind]=comp_count;
    scc[comp_count].push_back(ind);
    condensed_graph_set[comp_count];
    for(auto x:graph[ind])
    {
        if(visited.find(x)==visited.end())
        {
            dfs2(x,graph,visited);
        }
    }
}

/* We can represent a or b as nota and b and notb and a.
We create a directed graph consisting of the following edges. Unordred map is used as nodes are negative also. Unordered set is
used to avoid multiple edges in same pair of nodes.

It is impossible to solve the boolean satisfiablity problem if two nodes x and -x come in same strongly connected component.
Find the strongly connected components using kosaraju. Then create condensation graph and again get the topological order.
In the reverse topologiacl order, start assigning nodes belonging to the condensed node the values i.e + if they are positive
and - of they are negative if they have not been assigned yet.

Time complexity=> brute force would be n*2^m. i.e for each of the 2^m possible solutions, try out on all n people.
==> with graphs, now the time complexity is O(V+E) i.e. O(n+m) since we are only applying kosaraju which is linear.
*/

void solve()
{
    //check t
    ll n,m;
    cin>>n>>m;
    unordered_map<ll,unordered_set<ll>>graph;
    unordered_map<ll,unordered_set<ll>>revg;
    for(ll i=1;i<=m;i++)
    {
        graph[i];
        revg[i];
        graph[-i];
        revg[-i];
    }
    for(ll i=0;i<n;i++)
    {
        char ch;
        ll a,b;
        cin>>ch>>a;
        if(ch=='-')a*=-1;
        cin>>ch>>b;
        if(ch=='-')b*=-1;
        graph[-a].insert(b);
        graph[-b].insert(a);
        revg[b].insert(-a);
        revg[a].insert(-b);
    }

    unordered_set<ll>visited;

    for(auto it=graph.begin();it!=graph.end();it++)
    {
        if(visited.find(it->first)==visited.end())
        {
            dfs1(it->first,graph,visited,false);
        }
    }

    reverse(order.begin(),order.end());
    visited.clear();
    comp_count=0;
    for(ll i=0;i<order.size();i++)
    {
        if(visited.find(order[i])==visited.end())
        {
            dfs2(order[i],revg,visited);
            comp_count++;
        }
    }

    for(ll i=1;i<=m;i++)
    {
        if(components[i]==components[-i])
        {
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }

    for(auto it=graph.begin();it!=graph.end();it++)
    {   
        for(auto x:it->second)
        {
            if(components[it->first]!=components[x])
            {   
                condensed_graph_set[components[it->first]].insert(components[x]);
            }
        }
    }
    
    visited.clear();

    for(auto it=condensed_graph_set.begin();it!=condensed_graph_set.end();it++)
    {
        if(visited.find(it->first)==visited.end())
        {
            dfs1(it->first,condensed_graph_set,visited,true);
        }
    }

    for(ll i=0;i<cond_order.size();i++)
    {
        for(ll j=0;j<scc[cond_order[i]].size();j++)
        {   
            if(assigned.find(abs(scc[cond_order[i]][j]))==assigned.end())
            {
                assigned[abs(scc[cond_order[i]][j])] = (scc[cond_order[i]][j] >0) ? '+': '-';
            }
        }
    }

    for(ll i=1;i<=m;i++)
    {
        cout<<assigned[i]<<" ";
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