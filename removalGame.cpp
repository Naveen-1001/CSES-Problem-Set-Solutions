#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

ll maxProfit(ll n, vector<ll>v)
{
    vector<vector<ll> >dp(n+1,vector<ll>(n+1));

    if(n==1) return v[0];

    vector<ll>prefix(n);
    prefix[0]=v[0];

    for(ll i=1;i<n;i++)
    {
        prefix[i]=prefix[i-1]+v[i];
    }
    //rows aare the  beginning of  the subarray and columns are the length
    for(ll i=1;i<=n;i++)
    {
        dp[i][1]=v[i-1];
    }

    for(ll i=2;i<=n;i++)//we will go for completing all the positions for each length first in the outer loop. so we are basically going through the columns first
    {
        for(ll j=1;j<=n-i+1;j++)
        {
            dp[j][i]=max(v[j-1]+prefix[j+i-2]-prefix[j-1]-dp[j+1][i-1],v[j+i-2]+prefix[j+i-3]-((j!=1)?prefix[j-2]:0)-dp[j][i-1]);
        }
    }
    return dp[1][n];
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;

    vector<ll>v(n);

    for(ll i=0;i<n;i++) cin>>v[i];

    cout<<maxProfit(n,v);

    return 0;
}