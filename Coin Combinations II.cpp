/*#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
typedef long int li;
     
using namespace std;
/*Memoisation approach(runtime error due to (mostly) extended recursion stack)
ll coinComb(ll x,ll pos, vector<ll>v, vector<vector<ll> > &dp)
{   
    if(x<0 or (pos<1 and x>0)) return 0;

    if(x==0) return 1;

    if(dp[x][pos]!=-1) return dp[x][pos];

    return dp[x][pos]=coinComb(x-v[pos],pos,v,dp)+coinComb(x,pos-1,v,dp);

}
*/
/*
int coinComb(int x, vector<int>v)
{
    vector<vector<int> >dp(x+1,vector<int>(v.size(),0));
    for(int i=0;i<v.size();i++)
        dp[0][i]=1;

    int inc_total=0,notinc_total=0;

    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(i>=v[j])
            {
                inc_total=dp[i-v[j]][j];
            }
            else inc_total=0;

            if(j>0)
            {
                notinc_total=dp[i][j-1];
            }
            else notinc_total=0;

            dp[i][j]=(inc_total+notinc_total)%modc;
        }
    }

    return dp[x][v.size()-1];
}    



Since we are doing 108

operations in one second, we need those operations to be efficient. This means we can't have many cache misses.

You get cache misses by accessing array entries that are far away from each other. My implementation loops through i, then j. It accesses dp[i][j], dp[i-1][j] and dp[i][j-x[i-1]].

If you order your loops differently (j, then i), or use dp[j][i] instead of dp[i][j] (so you swapped the meaning of the dimensions), you will likely get TLE.

In terms of rules of thumb, we see that the dimension containing j-x[i-1] varies most, and therefore put it as the inner dimension of the dp array. And we loop through the dimensions the same order as the dimensions of the array. Below are some more detailed explanations.

If we loop through i, j-x[i-1] varies a lot, this means cache misses. Therefore we need to loop through i in the outer loop. Looping through j gives contiguous memory accesses, so we get few cache misses by having j as the inner loop.

If you define your array as dp[j][i] instead of dp[i][j], then dp[j-x[i-1]][i] goes far from dp[j][i], compared to dp[i][j] and dp[i][j-x[i-1]]. This is because the outer dimension gives smaller distance in memory than the inner dimension (you can think of dp[i][j] as accessing index 106i+j
in a linear array, if the second dimension has size 106).


int coinComb(int x, vector<int>v)
{
    vector< vector<int> >dp(v.size(),vector<int>(x+1));
    int inc_total=0,notinc_total=0;

    for(int i=0;i<v.size();i++)
        dp[i][0]=1;

    for(int i=1;i<=x;i++)
    {
        for(int j=0;j<v.size();j++)
        {
            if(i>=v[j])
            {
                inc_total=dp[j][i-v[j]];
            }
            else inc_total=0;

            if(j>0)
            {
                notinc_total=dp[j-1][i];
            }
            else notinc_total=0;

            dp[j][i]=(inc_total+notinc_total)%modc;
        }
    }

    return dp[v.size()-1][x];
}

int main()
{       
    int x;
    int n;
    cin>>n>>x;

    vector<int>v(n,0);

    for(int i=0;i<n;i++) cin>>v[i];

    //vector<vector<ll> >dp(x+1,vector<ll>(n+1,-1));

    cout<<coinComb(x,v);

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  int mod = 1e9+7;
  int n, target;
  cin >> n >> target;
  vector<int> x(n);
  for (int&v : x) cin >> v;

  vector<vector<int>> dp(n+1,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-x[i-1];
      if (left >= 0) {
    (dp[i][j] += dp[i][left]) %= mod;
      }
    }
  }
  cout << dp[n][target] << endl;
}