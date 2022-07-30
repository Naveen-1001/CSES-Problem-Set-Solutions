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
 
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m));
    ll xa,ya,xb,yb;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='A')
            {
                xa=i,ya=j;
            }
            if(v[i][j]=='B')
            {
                xb=i,yb=j;
            }
        }
    }
    string ans;
    queue<pair<ll,pair<ll,ll>>>q;
    map<pair<ll,ll>,pair<ll,ll>>path_map;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    visited[xa][ya]=true;
    q.push({0,{xa,ya}});
    ll count=0;
    while(!q.empty())
    {   
        pair<ll,pair<ll,ll>>front=q.front();
        q.pop();
        pair<ll,ll>coor=front.second;
        ll count=front.first;
        // cout<<coor.first<<" "<<coor.second<<"\n";
        if(coor.first==xb && coor.second==yb)
        {
            cout<<"YES\n"<<count<<"\n";
            string ans="";
            pair<ll,ll>curr=coor;
            while(count--)
            {
                pair<ll,ll>prev=path_map[curr];
                if(prev.first==curr.first)
                {
                    if(prev.second==curr.second-1)
                    {
                        ans+="R";
                    }
                    else ans+="L";
                }
                if(prev.second==curr.second)
                {
                    if(prev.first==curr.first+1)
                    {
                        ans+="U";
                    }
                    else ans+="D";
                }
                curr=prev;
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<"\n";
            return;
        }
        if(coor.first+1<n && !visited[coor.first+1][coor.second] && v[coor.first+1][coor.second]!='#')
        {
            q.push({count+1,{coor.first+1,coor.second}});
            visited[coor.first+1][coor.second]=true;
            path_map[{coor.first+1,coor.second}]=coor;
        }
        if(coor.first-1>=0 && !visited[coor.first-1][coor.second] && v[coor.first-1][coor.second]!='#')
        {
            q.push({count+1,{coor.first-1,coor.second}});
            visited[coor.first-1][coor.second]=true;
            path_map[{coor.first-1,coor.second}]=coor;
        }
        if(coor.second+1<m && !visited[coor.first][coor.second+1] && v[coor.first][coor.second+1]!='#')
        {
            q.push({count+1,{coor.first,coor.second+1}});
            visited[coor.first][coor.second+1]=true;
            path_map[{coor.first,coor.second+1}]=coor;
        }
        if(coor.second-1>=0 && !visited[coor.first][coor.second-1] && v[coor.first][coor.second-1]!='#')
        {
            q.push({count+1,{coor.first,coor.second-1}});
            visited[coor.first][coor.second-1]=true;
            path_map[{coor.first,coor.second-1}]=coor;
        }        
    }
    cout<<"NO\n";
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