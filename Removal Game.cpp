#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;

    vector<ll>v(n);

    for(ll i=0;i<n;i++) cin>>v[i];

    vector<vector<ll>>dp(n,vector<ll>(n,LLONG_MIN));
    //dp[i][j]-->max score1-score2 for interval i,j
    ll sum=0;
    for(ll i=n-1;i>=0;i--)
    {   
        sum+=v[i];
        for(ll j=i;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j]=v[j];
            }
            else
            {
                dp[i][j]=max(dp[i][j],v[i]-dp[i+1][j]);
                dp[i][j]=max(dp[i][j],v[j]-dp[i][j-1]);
            }
        }
    }
    cout<< (dp[0][n-1]+sum)/2;
}