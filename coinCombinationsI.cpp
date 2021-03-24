#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;
/* this is memoisation(tle)

ll coinComb(ll n, vector<ll>v, vector<ll>&dp)
{
    if(n<0) return 0;

    if(dp[n]!=-1) return dp[n];

    if(n==0) return 1;

    ll total=0;

    for(ll i=0;i<v.size();i++)
    {   
        total=(total+coinComb(n-v[i],v,dp))%modc;
    }

    return dp[n]=total;
}
*/

ll coinComb(ll x, vector<ll>v)
{
    ll dp[x+1];

    for(ll i=1;i<=x;i++) dp[i]=0;

    for(ll i=0;i<v.size();i++) if(v[i]<=x) dp[v[i]]=1;

    for(ll i=1;i<=x;i++)
    {
        for(ll j=0;j<v.size();j++)
        {
            if(i-v[j]>=1 && dp[i-v[j]]!=-1)
            {
                dp[i]=(dp[i]+dp[i-v[j]])%modc;
            }
        }
    }

    return dp[x];
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,x;
    cin>>n>>x;

    vector<ll>v(n,0);

    for(ll i=0;i<n;i++) cin>>v[i];

    cout<<coinComb(x,v);

    return 0;
}