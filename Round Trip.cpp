#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
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

void dfs(ll index, ll parent, vector<vector<ll>>&graph, vector<ll>&visited, unordered_map<ll,ll>&path,bool &found)
{   
    // cout<<index<<", visited index=>"<<visited[index]<<"\n";
    if(visited[index]==1 && found) return;
    if(visited[index]==1 && !found)
    {   
        found=true;
        ll first_parent=path[index];
        ll prev=parent;
        ll count=2;
        vector<ll>ans;
        ans.push_back(index);
        ans.push_back(parent);
        prev=path[parent];
        while(prev!=first_parent)
        {   
            // cout<<"h";
            ans.push_back(prev);
            prev=path[prev];
            count++;
        }
        cout<<count<<"\n";
        for(ll i=0;i<count;i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    visited[index]=1;
    // cout<<"exploring "<<index<<"\n";
    for(ll i=0;i<graph[index].size();i++)
    {   
        if(found) return;
        if(visited[graph[index][i]]!=2 && graph[index][i]!=parent)
        {
            if(path.find(graph[index][i])==path.end()) path[graph[index][i]]=index;
            dfs(graph[index][i], index, graph, visited, path, found);
        }
    }
    visited[index]=2;
    // cout<<"explored "<<index<<"\n";
}
 
void solve()
{
    //check t
    ll n,m;
    cin>>n>>m;
    vector<vector<ll>>graph(n+1);
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<ll>visited(n+1);
    unordered_map<ll,ll>path;
    bool found=false;
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i] && !found)
        {   
            path[i]=-1;
            dfs(i,-1,graph,visited,path,found);
        }
    }
    if(!found) cout<<"IMPOSSIBLE\n";
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