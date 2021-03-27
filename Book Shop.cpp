#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;
//Basically this is a version of 01knapsack as all the books are diff(so assuming all of them will have ddiff weight)
int maxPages(int n,int x, vector<int>price, vector<int>pages)
{
    vector<vector<int> >dp(n+1,vector<int>(x+1));

    for(int i=0;i<=n;i++)//including the ith weight/book from the list of weights
    {
        for(int j=0;j<=x;j++)// when till the ith book is included and max capacity of knapsack/budget is j
        {
            if(i==0 or j==0) dp[i][j]=0;
            else if(price[i-1]<=j)
            {
                dp[i][j]=max(dp[i-1][j], pages[i-1]+dp[i-1][j-price[i-1]]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][x];
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,x;
    cin>>n>>x;
    vector<int>price(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cin>>pages[i];
    cout<<maxPages(n,x,price,pages);
    return 0;
}