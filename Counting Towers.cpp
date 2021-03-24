#include<bits/stdc++.h>
#define mod 998244353
#define modc 1000000007
     
const long double PI = 3.141592653589793236L;
     
typedef long long int ll;
typedef long double ld;
     
using namespace std;

ll fast_power(ll a, ll b, ll m)//a^b
{
    if(b==0) return 1;
    if(b==1) return a;

    ll temp=fast_power(a,b/2,m);

    if(b%2==0) return (temp*temp)%m;
    return ((temp*temp)%m*a)%m;
}

ll gcd(ll a, ll b)
{
    if (b == 0) return a;
    return gcd(b, a % b); 
}

ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}

ll sum_of_digits(ll n)
{
    ll sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

void solve()
{   
    ll q;
    cin>>q;
    vector<ll>v(q);
    ll n=0;
    for(ll i=0;i<q;i++)
    {
        cin>>v[i];
        n=max(n,v[i]);
    }
    vector<vector<ll>>dp(n+1,vector<ll>(2));
    dp[1][0]=1;
    dp[1][1]=1;
    //States are 0--> block is of width 2, 1-->2 blocks is of width 1
    // So if the prev block is of width 2, we can either add 2 blocks of width 1 or (add new block of width
    // 2 or extend previos block of width 2)

    // If the previous blocks are of width 1, then either can add a new block of width 2 or
    // (1. extend both prev width 1 blocks)
    // (2. add 2 new width 1 blocks)
    // (3. add 1 new and extend 1 either on left or right side)
    for(ll i=2;i<=n;i++)
    {
        dp[i][0]=(2*dp[i-1][0]+dp[i-1][1])%modc;
        dp[i][1]=(dp[i-1][0]+4*dp[i-1][1])%modc;
    }

    for(ll i=0;i<q;i++)
    {
        cout<<(dp[v[i]][0]+dp[v[i]][1])%modc<<"\n";
    }
}
     
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll t;
    t=1;
    //cin>>t;
    while(t--)
    {   
        solve();
    }
    return 0;
}