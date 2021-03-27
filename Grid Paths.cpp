#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

ll countPaths(ll n, vector<vector<char> >grid)
{
    vector<vector<ll> >dp(n,vector<ll>(n));

    if(grid[n-1][n-1]=='*' or grid[0][0]=='*')
        return 0;

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(grid[i][j]=='*')
                dp[i][j]=-1;
        }
    }

    for(ll i=n-1;i>=0;i--)
    {
        for(ll j=n-1;j>=0;j--)
        {   
            ll right=0,down=0;
            if(i==n-1 && j==n-1) dp[i][j]=1;
            else if(dp[i][j]!=-1)
            {   
                if(i<n-1 and dp[i+1][j]!=-1) down=dp[i+1][j];
                if(j<n-1 and dp[i][j+1]!=-1) right=dp[i][j+1];
                dp[i][j]=(right+down)%modc;
            }
        }
    }

    return dp[0][0];
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));

    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<countPaths(n,grid);

    return 0;
}