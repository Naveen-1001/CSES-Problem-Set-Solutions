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
    //check t
    ll n,m;
    cin>>n>>m;
    vector<vector<char>>labyrinth(n,vector<char>(m));
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            cin>>labyrinth[i][j];
        }
    }
    queue<pair<pair<ll,ll>,ll>>q;
    vector<vector<ll>>count(n,vector<ll>(m,10000000));
    ll a,b;

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            if(labyrinth[i][j]=='M')
            {
                q.push({{i,j},0});
                count[i][j]=0;
            }
            if(labyrinth[i][j]=='A')
            {
                a=i,b=j;
            }
        }
    }
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    map<pair<ll,ll>,pair<ll,ll>>path;
    path[{a,b}]={-1,-1};
    while(!q.empty())
    {
        pair<pair<ll,ll>,ll>p=q.front();
        q.pop();
        ll r=p.first.first,c=p.first.second;
        ll val=p.second;
        if(r+1<n && !visited[r+1][c] && labyrinth[r+1][c]!='#')
        {
            visited[r+1][c]=true;
            q.push({{r+1,c},val+1});
            count[r+1][c]=val+1;
        }
        if(r>0 && !visited[r-1][c] && labyrinth[r-1][c]!='#')
        {
            visited[r-1][c]=true;
            q.push({{r-1,c},val+1});
            count[r-1][c]=val+1;
        }
        if(c>0 && !visited[r][c-1] && labyrinth[r][c-1]!='#')
        {
            visited[r][c-1]=true;
            q.push({{r,c-1},val+1});
            count[r][c-1]=val+1;
        }
        if(c+1<m && !visited[r][c+1] && labyrinth[r][c+1]!='#')
        {
            visited[r][c+1]=true;
            q.push({{r,c+1},val+1});
            count[r][c+1]=val+1;
        }
    }
    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<m;j++)
    //     {
    //         cout<<count[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    q.push({{a,b},0});
    vector<vector<bool>>visiteda(n,vector<bool>(m));
    while(!q.empty())
    {
        pair<pair<ll,ll>,ll>front=q.front();
        q.pop();
        ll r=front.first.first,c=front.first.second;
        ll val=front.second;
        if(r==n-1 or r==0 or c==m-1 or c==0)
        {
            pair<ll,ll>curr={r,c};
            cout<<"YES\n";
            string str;
            pair<ll,ll>final={a,b};
            while(curr!=final)
            {
                pair<ll,ll>parent=path[curr];
                if(parent.first==curr.first)
                {
                    if(parent.second==curr.second+1)
                    {
                        str+="L";
                    }
                    else str+="R";
                }
                else
                {
                    if(parent.first==curr.first+1)
                    {
                        str+="U";
                    }
                    else str+="D";
                }
                curr=path[curr];
            }
            cout<<str.length()<<"\n";
            reverse(str.begin(),str.end());
            cout<<str<<"\n";
            return;
        }
        if(r<n && !visiteda[r+1][c] && labyrinth[r+1][c]=='.' && count[r+1][c]>(val+1))
        {
            visiteda[r+1][c]=true;
            q.push({{r+1,c},val+1});
            path[{r+1,c}]=front.first;
        }
        if(r>0 && !visiteda[r-1][c] && labyrinth[r-1][c]=='.' && count[r-1][c]>(val+1))
        {
            visiteda[r-1][c]=true;
            q.push({{r-1,c},val+1});
            path[{r-1,c}]=front.first;
        }
        if(c>0 && !visiteda[r][c-1] && labyrinth[r][c-1]=='.' && count[r][c-1]>(val+1))
        {
            visiteda[r][c-1]=true;
            q.push({{r,c-1},val+1});
            path[{r,c-1}]=front.first;
        }
        if(c<m && !visiteda[r][c+1] && labyrinth[r][c+1]=='.' && count[r][c+1]>(val+1))
        {
            visiteda[r][c+1]=true;
            q.push({{r,c+1},val+1});
            path[{r,c+1}]=front.first;
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