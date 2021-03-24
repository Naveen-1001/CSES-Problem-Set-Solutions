#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

ll count(ll n)
{
    ll dp[n+1];
    dp[0]=0;
    
    for(ll i=1;i<=n;i++)
    {
        ll minOps=INT_MAX;
        ll x=i;

        while(x>0)
        {
            ll rem=x%10;
            if(rem!=0)
            {
                minOps=min(minOps,dp[i-rem]);
            }
            x/=10;
        }

        dp[i]=minOps+1;
    }

    return dp[n];

}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    cout<<count(n);
    return 0;
}