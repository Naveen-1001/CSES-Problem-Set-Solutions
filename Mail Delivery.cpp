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
    vector<unordered_set<ll>>graph(n+1);
    unordered_map<ll,ll>degree;
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        degree[a]++;
        degree[b]++;
        graph[a].insert(b);
        graph[b].insert(a);
    }

    stack<ll>s;
    vector<ll>ans;
    ll count_odd=0;
    for(ll i=1;i<=n;i++)
    {
        if(degree[i]%2==1) 
        {
            count_odd++;
        }
    }
    if(count_odd)
    {   
        cout<<"IMPOSSIBLE\n";
        return;
    }
    s.push(1);
    while(!s.empty())
    {   
        ll top=s.top();
        if(graph[top].empty())
        {
            s.pop();
            ans.push_back(top);
        }
        else
        {
            ll v=*(graph[top].begin());
            s.push(v);
            graph[top].erase(v);
            graph[v].erase(top);
        }
    }
    if(ans.size()-1<m)
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    for(ll i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
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