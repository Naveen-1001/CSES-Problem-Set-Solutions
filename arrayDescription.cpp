#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;
/*
We take dp[i][j] to be the no. of ways to fill the vector upto index i when v[i]=j, i.e the coloumn  gives the allowed vlaues the 
elements int the vactor may take

Then coming to the algo,
we store all the possible ways in the dp only using the sum of possible values in the previous row.

*/

ll countArrays(ll m, ll n, vector<ll>v)
{
    vector< vector <ll> >dp(n,vector<ll>(m+1));

    if(v[0]==0)
    {
        for(ll i=0;i<m+1;i++)
            dp[0][i]=1;
    }
    else
    {
        dp[0][v[0]]=1;
    }

    for(ll i=1;i<n;i++)
    {
        if(v[i]==0)
        {
            for(ll j=1;j<m+1;j++)
            {
                for(ll k: {j-1,j,j+1})
                {
                    if(k>0 and k<=m)
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%modc;
                }
            }
        }
        else
        {
            for(ll k: {v[i]-1,v[i],v[i]+1})
            {
                if(k>0 and k<=m)
                    dp[i][v[i]]=(dp[i][v[i]]+dp[i-1][k])%modc;
            }
        }
    }

    ll ans=0;

    for(ll i=1;i<m+1;i++)
        ans=(ans+dp[n-1][i])%modc;

    return ans;
}


     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n);
    for(ll i=0;i<n;i++) cin>>v[i];

    cout<<countArrays(m,n,v);
    return 0;
}