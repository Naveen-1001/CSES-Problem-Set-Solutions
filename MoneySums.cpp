#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

void possibleSums(int n, vector<int>v, int sum)
{
    vector<vector<int> >dp(n+1,vector<int>(sum+1));

    for(int i=1;i<=n;i++)
    {   
        dp[i][v[i-1]]=1;
        for(int j=1;j<=sum;j++)
        {
            dp[i][j]=max(dp[i][j],dp[i-1][j]);
            if(dp[i-1][j]==1)
            {
                dp[i][j+v[i-1]]=1;
            }
        }
    }

    int total=0;
    for(int i=1;i<=sum;i++)
    {
        total+=dp[n][i];
    }

    cout<<total<<"\n";
    for(int i=1;i<=sum;i++)
    {
        if(dp[n][i]) cout<<i<<" ";
    }
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<int>v(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    for(int i=0;i<n;i++)
        sum+=v[i];

    possibleSums(n,v,sum);

    return 0;
}