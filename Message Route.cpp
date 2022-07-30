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
 
ll lcm(ll a, ll b)
{
    return (a*b)/gcd(a,b);
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
    queue<pair<ll,ll>>q;
    unordered_map<ll,ll>path;
    q.push({1,0});
    vector<bool>visited(n+1);
    visited[1]=true;
    ll count=0;
    while(!q.empty())
    {
        pair<ll,ll>front=q.front();
        q.pop();
        ll prev;
        if(front.first==n)
        {
            cout<<front.second+1<<"\n";
            vector<ll>temp;
            temp.push_back(n);
            prev=n;
            for(ll j=0;j<front.second;j++)
            {
                temp.push_back(path[prev]);
                prev=path[prev];
            }
            reverse(temp.begin(),temp.end());
            for(ll i=0;i<temp.size();i++)
            {
                cout<<temp[i]<<" ";
            }
            cout<<"\n";
            return;
        }
        for(ll j=0;j<graph[front.first].size();j++)
        {
            if(!visited[graph[front.first][j]])
            {
                visited[graph[front.first][j]]=true;
                q.push({graph[front.first][j],front.second+1});
                path[graph[front.first][j]]=front.first;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
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