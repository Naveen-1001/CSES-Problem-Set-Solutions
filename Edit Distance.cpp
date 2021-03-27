#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

/*

suppose when we are st dp[i][j] we are seeing edit distance for two string ai and b[j]
so at this point we already have the values for the edit distance of stirngs from dp[0,i-1][whole b] and and for dp[i][j-1] of b.

so to get dp[i][j] where we already have dp[i-1][whole b] and dp[i][up till j-1], we can do the following things

1-> insert char to a which makes a[i+1] = b[j]. so total cost=1+dp[i][j-1]. as the prev char of a are there but b loses one char
2-> delete char from a total cost=1+dp[i-1][j] because we dont know how many we have to delete
3-> replace char from a to that of b. a[i-1] remaing and b[j-1]. so total cost=1+dp[i-1][j-1]

so create a bottom up dp table where dp[i][j] is the min cost for converting first i char of a to the first j char of b where
the subproblems are already solved.. i.e dp[i][j] is the edit distance for a[1....i] and b[1....j]

*/

int editDistance(string a, string b)
{
    vector<vector<int> >dp(a.size()+1,vector<int>(b.size()+1,1e9));
    dp[0][0]=0;

    //if a is empty, we have to insert the char in a.
    // if b is empty we have to delete the char.
    // if both are not empty we check for delete, insert and replace

    for(int i=0;i<=a.size();i++)
    {
        for(int j=0;j<=b.size();j++)
        {
            if(i)//if i is not empty, we can check for delete case
            {
                dp[i][j]=min(dp[i][j], 1+dp[i-1][j]);
            }

            if(j)//if b is not empty, we can check for insert in a
            {
                dp[i][j]=min(dp[i][j], 1+dp[i][j-1]);
            }

            if(i and j)//we check for the replace option(if they are equal, we just need to check for dp[i-1][j-1] here, a[i-1] means ith char)
            {
                dp[i][j]=min(dp[i][j], (a[i-1]!=b[j-1])+dp[i-1][j-1]);
            }
        }
    }

    return dp[a.size()][b.size()];
}


int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a,b;
    cin>>a>>b;
    cout<<editDistance(a,b);
    return 0;
}