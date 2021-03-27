#include<bits/stdc++.h>
#define mod 998244353
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

ll count(ll n, vector<ll>v, ll x)
{
    ll dp[x+1];
    for(ll i=1;i<=x;i++) dp[i]=-1;

    for(ll i=0;i<n;i++) 
    {   
        if(v[i]<=x)dp[v[i]]=1;
    }

    for(ll i=1;i<=x;i++)
    {   
        ll ans=LONG_MAX;
        if(dp[i]==-1)
        {
            for(ll j=0;j<n;j++) 
            {
                if(i-v[j]>=1 && dp[i-v[j]]!=-1) 
                {   
                    dp[i]=min(ans,1+dp[i-v[j]]);
                    ans=dp[i];
                }
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
    cout<<count(n,v,x);
    return 0;
}