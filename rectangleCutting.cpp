#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

int maxCut(int a, int b)
{
    vector<vector<int> >dp(a+1,vector<int>(b+1,1e9));

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {   
            if(i==j)
            {
                dp[i][j]=0;
            }
            else
            {
                for(int k=1;k<i;k++)//seeing all possible horizontal cuts for (i,j)
                {
                    dp[i][j]=min(dp[i][j],1+dp[i-k][j]+dp[k][j]);
                }

                for(int k=1;k<j;k++)//seeing all possible vertical cuts for (i,j)
                {
                    dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
                }
            }
        }
    }
    //we build up by seeing all possible cuts on smaller rectagles(i,j) and then build up to (a,b)
    return dp[a][b];
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b;
    cin>>a>>b;
    cout<<maxCut(a,b);

    return 0;
}