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

ll dfs(ll index, ll curr, vector<vector<ll>>&graph, vector<ll>&visited, vector<ll>&ans)
{   
    ll retval=0;
    visited[index]=1;
    for(ll i=0;i<graph[index].size();i++)
    {
        if(!visited[graph[index][i]])
        {   
            if(curr==1) 
            {
                ans[graph[index][i]]=2;
            }
            else
            {
                ans[graph[index][i]]=1;
            }
            retval=min(retval,dfs(graph[index][i],(curr==1)?2:1,graph,visited,ans));
        }
        else if(ans[graph[index][i]]==curr)
        {
            {
                retval=-1;
            }
        }
    }
    return retval;
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
        // cout<<"i";
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<ll>visited(n+1);
    vector<ll>ans(n+1,1);
    ll val=0;
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i])
        {   
            // cout<<"j";
            val=min(val,dfs(i,1,graph,visited,ans));
        }
    }
    if(val==-1)
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    else
    {
        for(ll i=1;i<=n;i++)
        {
            cout<<ans[i]<<" ";
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