#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

ll count(ll n,vector<ll>&dp)
{
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    if(n==0) return dp[n]=1;
    ll count_here=0;
    for(ll i=1;i<=6;i++) count_here=(count_here+count(n-i,dp))%modc;
    return dp[n]=count_here;
}

//Function for code wothout repeatitions
/*
ll count(ll n, ll pos, vector<ll>v,vector<vector<ll> >&dp)
{
    if(n<0 or ( n>0 and pos<=0)) return 0;

    if(dp[n][pos]!=-1) return dp[n][pos];

    if(n==0) return dp[n][pos]=0;

    return dp[n][pos]=count(n-v[pos],pos,v,dp)+count(n,pos-1,v,dp);

Here we basically count that in one case the req element at pos is either omitted or taken atleast once

}
*/

     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    t=1;
    //cin>>t;
    while(t--)
    {   
        ll n;
        cin>>n;
        vector<ll>dp(n+1,-1);

        cout<<count(n,dp);

    }
    return 0;
}