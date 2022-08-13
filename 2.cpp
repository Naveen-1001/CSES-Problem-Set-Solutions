#include<bits/stdc++.h>

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
 
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
const long long INF = 10000000000000000;//10^16 
    
typedef long long int ll;
typedef long double ld;
     
// using namespace __gnu_pbds;
using namespace std;
 
void solve()
{
    //check t
    ll n;
    cin>>n;
    vector<string>v(n);
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<map<pair<char,char>,ll>>dp(n);
    dp[0][{v[0][0],v[0][v[0].length()-1]}]=v[0].length();
    for(ll i=1;i<n;i++)
    {   
        ll len=v[i].length();
        char a=v[i][0],b=v[i][len-1];
        dp[i][{a,b}]=len;
        for(char ch='a';ch<='z';ch++)
        {
            for(char ch2='a';ch2<='z';ch2++)
            {
                dp[i][{ch,ch2}]=dp[i-1][{ch,ch2}];
            }
        }
        for(char ch='a';ch<='z';ch++)
        {  
            dp[i][{ch,b}]=max(dp[i][{ch,b}],dp[i-1][{ch,a}]+len);
        }
    }
    ll ans=0;
    for(char ch='a';ch<='z';ch++)
    {
        for(char ch2='a';ch2<='z';ch2++)
        {   
            ans=max(ans, dp[n-1][{ch,ch2}]);
        }
    }
    cout<<ans<<"\n";
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    t=1;
    // cin>>t;
    while(t--)
    {   
        solve();
    }
    return 0;
}