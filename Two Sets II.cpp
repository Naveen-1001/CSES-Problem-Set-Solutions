#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;
 
/*
This is a 0-1 knapsack in disguise. We run 0-1 knapsack to get the number of ways to reach n(n+1)4
*So basically, knapsack is when we can take the objects exactly once and we have to have the weights under a target or max capacity
using subsets of the numbers 1..n-1. Why n-1? Because by only considering numbers up to n-1, 
we always put n in the second set, and therefore only count each pair of sets once (
otherwise we count every pair of sets twice).
 
dp[i][x] = number of ways to make sum x using subsets of the numbers 1..i.
 
We say there is one way (the empty set) to make sum 0, so dp[0][0] = 1;
 
For counting number of ways to make sum x using values up to i, we consider the number i. 
Either we didn't include it, then there are dp[i-1][x] possibilities, or we included it, 
and there are dp[i-1][x-i] possibilities. So dp[i][x] = dp[i-1][x] + dp[i-1][x-i].
*/
 
ll twoSets(ll n)
{
    if(n*(n+1)%4!=0) return 0;
 
    vector<vector<ll> >dp(n,vector<ll>(n*(n+1)/4+1));
 
    dp[0][0]=1;
 
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<=n*(n+1)/4;j++)
        {
            dp[i][j]=dp[i-1][j];
 
            if(i<=j)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][j-i])%modc;
            }
        }
    }
 
    return dp[n-1][n*(n+1)/4];
 
}
 
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    
    cout<<twoSets(n);
    
    return 0;
}