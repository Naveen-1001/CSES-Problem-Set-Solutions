#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll dp[20][20][2][2];

//dp(N,x,leading_zeros,tight) is the number of answers for N digits when leading number is not x.
ll solve(string number,int n,int x,bool leading_zeros,bool tight)
{
    if(n==0)
    {
        return 1;
    }

    if(x!=-1 and dp[n][x][leading_zeros][tight]!=-1) 
    {
        return dp[n][x][leading_zeros][tight];
    }

    int lb=0;
    int ub=tight? (number[number.length()-n]-'0'):9; //first based on tight condition

    ll answer=0;

    for(int dig=lb;dig<=ub;dig++)
    {
        if(dig==x and leading_zeros==0)//when we have two adj. same positions
            continue;
        answer+=solve(number,n-1,dig,(leading_zeros & dig==0),(tight & (dig==ub)));
        //if leading zeros is 1, then if we add non zero number, then no longer we can have leading zeros.
        //if tight is 1 but then we add a number less than upperbound, then remaining positions are no longer tight
    }
    return dp[n][x][leading_zeros][tight]=answer;

}

int main()
{
    ll a,b;
    cin>>a>>b;
    string A=to_string(a-1);
    string B=to_string(b);
    memset(dp,-1,sizeof dp);
    ll ansb=solve(B,B.length(),-1,1,1);
    memset(dp,-1,sizeof dp);
    ll ansa=solve(A,A.length(),-1,1,1);
    cout<<ansb-ansa;
}